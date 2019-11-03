
#include "Precomp.h"
#include "RawMouse.h"

#ifndef G413229_XLIB_RAWMOUSE // not using gdm413229's Xlib version of RawMouse?

#ifdef WIN32

#ifndef HID_USAGE_PAGE_GENERIC
#define HID_USAGE_PAGE_GENERIC		((USHORT) 0x01)
#endif

#ifndef HID_USAGE_GENERIC_MOUSE
#define HID_USAGE_GENERIC_MOUSE	((USHORT) 0x02)
#endif

#ifndef HID_USAGE_GENERIC_JOYSTICK
#define HID_USAGE_GENERIC_JOYSTICK	((USHORT) 0x04)
#endif

#ifndef HID_USAGE_GENERIC_GAMEPAD
#define HID_USAGE_GENERIC_GAMEPAD	((USHORT) 0x05)
#endif

#ifndef RIDEV_INPUTSINK
#define RIDEV_INPUTSINK	(0x100)
#endif

class RawMouseWindowClass
{
public:
	RawMouseWindowClass()
	{
		WNDCLASSEX windowClassDesc;
		memset(&windowClassDesc, 0, sizeof(WNDCLASSEX));
		windowClassDesc.cbSize = sizeof(WNDCLASSEX);
		windowClassDesc.lpszClassName = ClassName;
		windowClassDesc.hInstance = GetModuleHandle(nullptr);
		windowClassDesc.lpfnWndProc = &RawMouse::WindowProc;
		RegisterClassEx(&windowClassDesc);
	}

	const TCHAR* ClassName = TEXT("RawMouseWindow");
};

RawMouse::RawMouse(void* ownerWindow)
{
	static RawMouseWindowClass win32class;
	handle = CreateWindowEx(0, win32class.ClassName, TEXT(""), WS_POPUP, 0, 0, 100, 100, 0, 0, GetModuleHandle(nullptr), this);

	RAWINPUTDEVICE rid;
	rid.usUsagePage = HID_USAGE_PAGE_GENERIC;
	rid.usUsage = HID_USAGE_GENERIC_MOUSE;
	rid.dwFlags = RIDEV_INPUTSINK;
	rid.hwndTarget = handle;
	RegisterRawInputDevices(&rid, 1, sizeof(RAWINPUTDEVICE));
}

RawMouse::~RawMouse()
{
	if (handle)
		DestroyWindow(handle);
}

float RawMouse::GetX()
{
	float result = x;
	x = 0;
	return result;
}

float RawMouse::GetY()
{
	float result = y;
	y = 0;
	return result;
}

LRESULT RawMouse::OnMessage(INT message, WPARAM wparam, LPARAM lparam)
{
	if (message == WM_INPUT)
	{
		HRAWINPUT rawinputHandle = (HRAWINPUT)lparam;
		UINT size = 0;
		UINT result = GetRawInputData(rawinputHandle, RID_INPUT, 0, &size, sizeof(RAWINPUTHEADER));
		if (result == 0 && size > 0)
		{
			std::vector<uint32_t> buf((size + 3) / 4);
			result = GetRawInputData(rawinputHandle, RID_INPUT, buf.data(), &size, sizeof(RAWINPUTHEADER));
			if (result >= 0)
			{
				RAWINPUT* rawinput = (RAWINPUT*)buf.data();
				if (rawinput->header.dwType == RIM_TYPEMOUSE)
				{
					x += rawinput->data.mouse.lLastX;
					y += rawinput->data.mouse.lLastY;
				}
			}
		}
		return 0;
	}
	else
	{
		return DefWindowProc(handle, message, wparam, lparam);
	}
}

LRESULT RawMouse::WindowProc(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
{
	if (message == WM_CREATE)
	{
		CREATESTRUCT* createInfo = (CREATESTRUCT*)lparam;
		auto window = reinterpret_cast<RawMouse*>(createInfo->lpCreateParams);
		window->handle = handle;
		SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<ULONG_PTR>(window));
		return window->OnMessage(message, wparam, lparam);
	}
	else
	{
		auto window = reinterpret_cast<RawMouse*>(GetWindowLongPtr(handle, GWLP_USERDATA));
		if (window)
			return window->OnMessage(message, wparam, lparam);
		else
			return DefWindowProc(handle, message, wparam, lparam);
	}
}

#else

RawMouse::RawMouse(void* ownerWindow)
{
}

RawMouse::~RawMouse()
{
}

float RawMouse::GetX()
{
	return 0;
}

float RawMouse::GetY()
{
	return 0;
}

#endif
#endif

#ifdef G413229_XLIB_RAWMOUSE

// TODO: create Xlib version of RawMouse

// [gdm413229] Xlib version of RawMouse, may grab the keyboard to ensure the menus don't unexpectedly pop up.

class RawMouse
{

public:
	RawMouse(void* ownerWindow);
	~RawMouse();

private:
	// Cursor position
	int x = 0;
	int y = 0;

	Display* disp=0; // Xlib display handle
	Window handle=0; // Xlib window handle
	const unsigned int grab_evmask = PointerMotionMask|ButtonMotionMask; // we want to get mouse delta-related events!

private:
	// Cursor grabber
	inline void GrabCursor() {
		XGrabPointer(disp,handle,0,grab_evmask,GrabModeSync,GrabModeSync,None,None,CurrentTime);
		XFlush(handle);
	}

	// Cursor releaser
	inline void UngrabCursor() {
		XUngrabPointer(disp,CurrentTime);
		XFlush(handle);
	}

	// Keyboard grabber, useful for making sure dem menus don't pop when users didn't mean to!
	inline void GrabKeyboard() {
		XGrabKeyboard(disp,handle,0,GrabModeSync,GrabModeSync,CurrentTime);
		XFlush(handle);
	}

	// Keyboard releaser
	inline void UngrabKeyboard() {
		XUngrabKeyboard(disp,CurrentTime);
		XFlush(handle);
	}

	// Cursor query wrapper

	inline void QueryCursor() {
		XQueryPointer(disp,handle,NULL,NULL,NULL,NULL,&this.x,&this.y,NULL); // not sure if WinForms cursor position is absolute (X display pos.) or relative (local pos. inside window)
	}

	inline void QueryCursorRelative() {
		XQueryPointer(disp,handle,NULL,NULL,NULL,NULL,&this.x,&this.y,NULL); // not sure if WinForms cursor position is absolute (X display pos.) or relative (local pos. inside window)
	}

};

RawMouse::RawMouse(void* ownerWindow) {
	// ctor for Xlib RawMouse
	this.disp=XOpenDisplay(NULL);

	// checks if Xlib gave us a display handle.

	if(this.disp == NULL) {
		throw std::runtime_error(std::string("ＯＨ　▄█▀ █━█ █ ▀█▀！ Xlib refused to give us a display handle!"));
	}
	// TODO: negotiate with dpJudas for Xlib window handle retrieval from GL context holder
}

RawMouse::~RawMouse() {
	XCloseDisplay(this.disp); // get rid of our redundant display handle
	this.handle=0; // Nullify the window handle.
}

float RawMouse::GetX() {
	QueryCursor();
	XFlush(this.disp); // as a guarantee
	return this.x;
}

float RawMouse::GetY() {
	QueryCursor();
	XFlush(this.disp); // as a guarantee
	return this.y;
}

#endif

/////////////////////////////////////////////////////////////////////////////

extern "C"
{

RawMouse* RawMouse_New(void* hwnd)
{
	return new RawMouse(hwnd);
}

void RawMouse_Delete(RawMouse* mouse)
{
	delete mouse;
}

float RawMouse_GetX(RawMouse* mouse)
{
	return mouse->GetX();
}

float RawMouse_GetY(RawMouse* mouse)
{
	return mouse->GetY();
}


