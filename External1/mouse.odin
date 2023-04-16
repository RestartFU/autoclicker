package spectrum

import "core:sys/windows"
import "core:runtime"
import "core:fmt"

@(private)
mhook : Mouse

Mouse :: struct {
    hook: windows.HHOOK,
    handler: proc(windows.WPARAM, ^MSLLHOOKSTRUCT),
} 

POINT :: struct {
    x: i32,
    y: i32,
}

MSLLHOOKSTRUCT :: struct {
    pt: POINT,
    mouseData: u32,
    flags: u32,
    time: u32,
    dwExtraInfo: ^u64,
}

mouse_callback :: proc "stdcall" (code: windows.c_int, wParam: windows.WPARAM, lParam: windows.LPARAM) -> windows.LRESULT {
    context = runtime.default_context()

    m_struct := cast(^MSLLHOOKSTRUCT)uintptr(lParam)
    mhook.handler(wParam, m_struct)
    return windows.CallNextHookEx(mhook.hook, code, wParam, lParam)
}

send_mouse_input :: proc (flags: windows.DWORD) {
    input := windows.INPUT{
        type = windows.INPUT_TYPE.MOUSE,
    }
    input.mi.dwFlags = flags

    windows.SendInput(1, &input, size_of(windows.INPUT))
}