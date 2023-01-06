// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "wingdi.h"
#include "winuser.h"

#define dllx extern "C" __declspec(dllexport)

dllx double set_color_key(void* hwnd_ptr, double red, double green, double blue) {
	HWND hwnd = (HWND)hwnd_ptr;
	long flags = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	flags |= WS_EX_LAYERED;
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, flags);
	bool result = SetLayeredWindowAttributes(hwnd, RGB((int)red, (int)green, (int)blue), 255, LWA_COLORKEY);

	//RECT rect;
	//GetWindowRect(hwnd, &rect);
	//HDC hdc_dest = GetDC(NULL);
	//HDC hdc = CreateCompatibleDC(NULL);
	//POINT pt_src = { 0 };
	//POINT pt_dest = { rect.left, rect.top };
	//BLENDFUNCTION blend = { AC_SRC_OVER,0,255,AC_SRC_ALPHA };
	//bool result = UpdateLayeredWindow(hwnd, NULL, NULL, NULL, NULL, NULL, RGB(red, green, blue), &blend, ULW_COLORKEY);

	if (result == true) {
		return 0;
	}
	return GetLastError();
}

dllx double set_always_on_top(void* hwnd_ptr,double on_top) {
	HWND hwnd = (HWND)hwnd_ptr;
	if (on_top > 0) {
		return SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	} else {
		return SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
}

dllx double get_cursor_x(void* hwnd_ptr) {
	HWND hwnd = (HWND)hwnd_ptr;
	POINT p;
	GetCursorPos(&p);
	if (ScreenToClient(hwnd,&p)) {
		return (double)p.x;
	}
	else {
		return -1.0;
	}
}

dllx double get_cursor_y(void* hwnd_ptr) {
	HWND hwnd = (HWND)hwnd_ptr;
	POINT p;
	GetCursorPos(&p);
	if (ScreenToClient(hwnd,&p)) {
		return (double)p.y;
	}
	else {
		return -1.0;
	}
}

dllx double get_error() {
	DWORD err = GetLastError();
	return (double) err;
}