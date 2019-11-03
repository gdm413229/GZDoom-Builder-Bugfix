#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <memory>

#ifdef WIN32
#include <Windows.h>
#undef min
#undef max
#endif

// [gdm413229] for RawMouse on Linux

#ifdef G413229_XLIB_RAWMOUSE
#include <X11/Xlib.h> // for XWarpPointer and XQueryPointer
#endif

#include "gl_load/gl_system.h"

#define APART(x) (static_cast<uint32_t>(x) >> 24)
#define RPART(x) ((static_cast<uint32_t>(x) >> 16)  & 0xff)
#define GPART(x) ((static_cast<uint32_t>(x) >> 8)  & 0xff)
#define BPART(x) (static_cast<uint32_t>(x) & 0xff)
