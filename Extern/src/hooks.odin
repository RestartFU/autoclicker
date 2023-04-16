package spectrum

import "core:sys/windows"
import "core:c"

dispatch_messages :: proc () {
    msg : ^windows.MSG
    for windows.GetMessageW(msg, nil, 0, 0) {
        windows.TranslateMessage(msg)
        windows.DispatchMessageW(msg)
    }
}

Hook :: union {
    Mouse,
    Keyboard,
}

hook :: proc (h: Hook) {
    if m, ok := h.(Mouse); ok {
        mhook = m
        windows.SetWindowsHookExW(14, mouse_callback, nil, 0)
    } else if k, ok := h.(Keyboard); ok {
        khook = k
        windows.SetWindowsHookExW(13, keyboard_callback, nil, 0)
    }
}

unhook :: proc (h: Hook) {
    if m, ok := h.(Mouse); ok {
        windows.UnhookWindowsHookEx(m.hook)
    } else if k, ok := h.(Keyboard); ok {
        khook = k
        windows.UnhookWindowsHookEx(k.hook)
    }
}