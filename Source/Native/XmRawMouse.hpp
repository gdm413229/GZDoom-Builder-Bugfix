
/* [gdm413229] RawMouse for XmBuilder.exe */

#ifdef WIN32 // building for the demon-possessed Redmond Beast???

/* TODO: yell at cl.exe saying this program won't compile with the presence of the
 * Mark of the Beast. */

/* And I saw the beast, and the kings of the earth, and their armies,
 * gathered together to make war against him that sat on the horse,
 * and against his army. (Revelation 19:19 AKJV) */

/* Ye are of your father the devil, and the lusts of your father ye will do.
 * He was a murderer from the beginning, and abode not in the truth,
 * because there is no truth in him. When he speaketh a lie,
 * he speaketh of his own: for he is a liar, and the father of it. (John 8:44 AKJV) */

#elseif X11 // building for X11-enabled UNIX-like systems??? Think of GNU/Linux, IRIX, Tru64 and Solaris.

#include <X11/Xlib.h> // uses Xlib! (dpy and win handles and a whole lot more!)

/* And the beast was taken, and with him the false prophet that wrought miracles
 * before him, with which he deceived them that had received the mark of the beast,
 * and them that worshipped his image. These both were cast alive into a lake of fire
 * burning with brimstone. (Revelation 19:20 AKJV) */

/* This Book of Revelation reference relates to what happens inside your PC when
 * Windows 10 is replaced with GNU/Linux. */

// X11 handle pair

typedef struct {
    Display* dpy;
    Window win;
} handlepair_t;

class RawMouse{
public:
    RawMouse(Display* dpy,Window win); // ctor, needs dpy and win handles due to how X11 works!
    ~RawMouse(); // dtor
private:
    // private stuff!
    uint x,y; // X and Y mouse positions.
    handlepair_t handle;
};

#endif
