package spectrum

import "core:sys/windows"
import "core:runtime"

@(private)
khook : Keyboard

Keyboard :: struct {
    hook: windows.HHOOK,
    handler: proc(windows.WPARAM, ^KBDLLHOOKSTRUCT),
} 

KBDLLHOOKSTRUCT :: struct {
    vkCode:      u32,
	scanCode:    u32,
	flags:       u32,
	time:        u32,
	dwExtraInfo: ^u64,
}

keyboard_callback :: proc "stdcall" (code: windows.c_int, wParam: windows.WPARAM, lParam: windows.LPARAM) -> windows.LRESULT {
    context = runtime.default_context()

    k_struct := cast(^KBDLLHOOKSTRUCT)uintptr(lParam)
    khook.handler(wParam, k_struct)
    return windows.CallNextHookEx(khook.hook, code, wParam, lParam)
}