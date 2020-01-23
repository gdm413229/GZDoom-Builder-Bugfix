/* Xm-related includes for custom widgets/controls. */

#include <X11/Xlib.h> // Motif needs Xlib!
//#include <X11/Intrinsic.h> // for dem custom widgets/controls!
#include <X11/Xcursor/Xcursor.h> // for shape-shifting that cursor!
#include <Xm/Xm.h> // THE MOTIF BASE HEADER FILE!

// Do we want DtSpinBox or XmSpinBox???

#ifdef USE_DT_CONTROLS

#include <Dt/SpinBox.h>

#else

#include <Xm/SpinBox.h>

#endif