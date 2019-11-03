#pragma once

#ifndef G413229_XLIB_RAWMOUSE // not using gdm413229's Xlib version of RawMouse?

#ifdef WIN32

class RawMouse
{
public:
	RawMouse(void* ownerWindow);
	~RawMouse();

	float GetX();
	float GetY();

private:
	LRESULT OnMessage(INT message, WPARAM wparam, LPARAM lparam);
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	HWND handle = 0; // Win32 window handle
	int x = 0;
	int y = 0;

	friend class RawMouseWindowClass;
};

#else

class RawMouse
{
public:
	RawMouse(void* ownerWindow);
	~RawMouse();

	float GetX();
	float GetY();
};

#endif
#endif

#ifdef G413229_XLIB_RAWMOUSE

class RawMouse {
	public:
	RawMouse(void* ownerWindow);
	~RawMouse();

	float GetX();
	float GetY();
	
	private:
	
	int x=0; int y=0;

	Display* disp=0; Window handle = 0; // Xlib display and window handles
};

#endif
