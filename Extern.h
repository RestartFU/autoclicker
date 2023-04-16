#include <windows.h>

namespace Extern
{
	enum MouseButton
	{
		right,
		left
	};
	typedef void (*Procedure)();

	typedef void (*start_clicker_t)();
	typedef void (*set_min_cps_t)(MouseButton btn, UINT min);
	typedef void (*set_max_cps_t)(MouseButton btn, UINT max);
	typedef void (*set_toggle_proc_t)(MouseButton btn, Procedure prc);
	typedef void (*set_toggled_t)(MouseButton btn, bool toggled);
	typedef bool (*toggled_t)();

	static HINSTANCE hmodule = LoadLibraryA("clicker.dll");

	static auto start_clicker = (start_clicker_t)GetProcAddress(hmodule, "start_clicker");
	static auto set_min_cps = (set_min_cps_t)GetProcAddress(hmodule, "set_min_cps");
	static auto set_max_cps = (set_max_cps_t)GetProcAddress(hmodule, "set_max_cps");
	static auto set_toggle_proc = (set_toggle_proc_t)GetProcAddress(hmodule, "set_toggle_proc");
	static auto set_toggled = (set_toggled_t)GetProcAddress(hmodule, "set_toggled");
	static auto toggled = (toggled_t)GetProcAddress(hmodule, "toggled");
}