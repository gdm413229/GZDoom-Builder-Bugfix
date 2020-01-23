
/* [gdm413229] RawMouse for XmBuilder.exe */

#include "XmRawMouse.hpp"

extern "C" {
    RawMouse* RawMouse_New(handlepair_t handles) {
        return new RawMouse(handles.dpy,handles.win);
    }
}