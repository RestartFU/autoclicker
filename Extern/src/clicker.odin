package spectrum

import "core:sys/windows"
import "core:thread"
import "core:time"
import "core:math/rand"
import "core:runtime"
import "core:os"
import "core:fmt"

Procedure :: proc()

MIN_LEFT, MAX_LEFT: uint = 10, 20
TOGGLE_LEFT: u32 = 0x79
LAST_CLICK_LEFT: time.Time
TOGGLED_LEFT: bool
MOUSE_DOWN_LEFT: bool
FIRST_CLICK_LEFT: bool
TOGGLE_PROC_LEFT: Procedure 

MIN_RIGHT, MAX_RIGHT: uint = 10, 20
TOGGLE_RIGHT: u32 = 0x49
LAST_CLICK_RIGHT: time.Time
TOGGLED_RIGHT: bool
MOUSE_DOWN_RIGHT: bool
FIRST_CLICK_RIGHT: bool
TOGGLE_PROC_RIGHT: Procedure

rand_int :: proc(min, max: uint) -> uint {
    if max - min == 0{
        return min
    }
    seed := rand.create(u64(time.now()._nsec))
    n := rand.int_max(int(max - min), &seed)
    return uint(n) + min
}

MOUSE_BUTTON :: enum {
    right,
    left,
}

@export
set_min_cps :: proc "c" (btn: MOUSE_BUTTON, min: uint) {
    switch btn {
        case .right: {
            if min > MAX_RIGHT {
                MAX_RIGHT = min
            }
            MIN_RIGHT = min
        }
        case .left: {
            if min > MAX_LEFT {
                MAX_LEFT = min
            }
            MIN_LEFT = min
        }
    }
}

@export
set_max_cps :: proc "c" (btn: MOUSE_BUTTON, max: uint) {
    switch btn {
        case .right: {
            if max < MIN_RIGHT {
                MIN_RIGHT = max
            }
            MAX_RIGHT = max
        }
        case .left: {
            if max < MIN_LEFT {
                MIN_LEFT = max
            }
            MAX_LEFT = max
        }
    }
}

@export
max_cps :: proc "c" (btn: MOUSE_BUTTON) -> uint {
    switch btn {
        case .right: {
            return MAX_RIGHT
        }
        case .left: {
            return MAX_LEFT
        }
    }
    return 0
}

@export
min_cps :: proc "c" (btn: MOUSE_BUTTON) -> uint {
    switch btn {
        case .right: {
            return MIN_RIGHT
        }
        case .left: {
            return MIN_LEFT
        }
    }
    return 0
}

@export
set_toggle :: proc "c" (btn: MOUSE_BUTTON, toggle: u32) {
    switch btn {
        case .right: TOGGLE_RIGHT = toggle
        case .left: TOGGLE_LEFT = toggle
    }
}

@export
set_toggle_proc :: proc "c" (btn: MOUSE_BUTTON, prc: Procedure) {
    switch btn {
        case .right: {
            TOGGLE_PROC_RIGHT = prc
        }
        case .left: {
            TOGGLE_PROC_LEFT = prc
        }
    }
}

@export
set_toggled :: proc "c" (btn: MOUSE_BUTTON, toggle: bool) {
    switch btn {
        case .right: TOGGLED_RIGHT = toggle
        case .left: TOGGLED_LEFT = toggle
    }
}

@export 
toggled :: proc "c" (btn: MOUSE_BUTTON) -> bool {
    switch btn {
        case .right: return TOGGLED_RIGHT
        case .left: return TOGGLED_LEFT
    }
    return false
}

@export
exit_dll :: proc "c" () {
    os.exit(1)
}

focused :: proc () -> bool {
    return windows.GetForegroundWindow() == windows.FindWindowA(nil, "Minecraft")
}

@export
start_clicker :: proc "c" () {
    context = runtime.default_context()
    mhook := Mouse{
        handler = proc(wParam: windows.WPARAM, mstruct: ^MSLLHOOKSTRUCT) {
          if wParam != 0x0200 && mstruct.flags == 0 {
            if wParam == 0x201 {
                FIRST_CLICK_LEFT = true
                MOUSE_DOWN_LEFT = true
            } else if wParam == 0x202 {
                MOUSE_DOWN_LEFT = false
            } else if wParam == 0x0204 {
                FIRST_CLICK_RIGHT = true
                MOUSE_DOWN_RIGHT = true
            } else if wParam == 0x0205 {
                MOUSE_DOWN_RIGHT = false
            }
          }
        },
    }
    khook := Keyboard{
        handler = proc(wParam: windows.WPARAM, kstruct: ^KBDLLHOOKSTRUCT) {
            if wParam == 0x0101 {
                if kstruct.vkCode == TOGGLE_LEFT {
                    TOGGLED_LEFT = !TOGGLED_LEFT
                    if TOGGLE_PROC_LEFT != nil {
                        TOGGLE_PROC_LEFT()
                    }
                } else if kstruct.vkCode == TOGGLE_RIGHT {
                    TOGGLED_RIGHT = !TOGGLED_RIGHT
                    if TOGGLE_PROC_RIGHT != nil {
                        TOGGLE_PROC_RIGHT()
                    }
                }
            }
        },
    }

    hook(mhook)
    hook(khook)

    defer {
        unhook(mhook)
        unhook(khook)
    }

    thread.create_and_start(proc(^thread.Thread) {
        for {
            if TOGGLED_LEFT && MOUSE_DOWN_LEFT {
                if FIRST_CLICK_LEFT {
                    time.sleep(time.Millisecond * 30)
                    FIRST_CLICK_LEFT = false
                } else if focused() && (time.Duration(time.now()._nsec - LAST_CLICK_LEFT._nsec) > time.Duration( 1000 / rand_int(MIN_LEFT, MAX_LEFT)) * time.Millisecond) {
                    send_mouse_input(0x004)
                    send_mouse_input(0x002)
                    LAST_CLICK_LEFT = time.now()
                }
            }
            time.sleep(1 * time.Millisecond)
        }
    })
    thread.create_and_start(proc(^thread.Thread) {
        for {
            if TOGGLED_RIGHT && MOUSE_DOWN_RIGHT {
                if FIRST_CLICK_RIGHT {
                    time.sleep(time.Millisecond * 30)
                    FIRST_CLICK_RIGHT = false
                } else if focused() && (time.Duration(time.now()._nsec - LAST_CLICK_RIGHT._nsec) > time.Duration( 1000 / rand_int(MIN_RIGHT, MAX_RIGHT)) * time.Millisecond) {
                    send_mouse_input(0x0010)
                    send_mouse_input(0x0008)
                    LAST_CLICK_RIGHT = time.now()
                }
            }
            time.sleep(1 * time.Millisecond)
        }
    })
    dispatch_messages()
}