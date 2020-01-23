
using System;
using System.Runtime.InteropServices; // useful for interop with X11, Xt and Xm.
/* Xt widget base class for XmBuilder */



namespace CodeImp.DoomBuilder.G4_XmUI.Xt {

    // libXm needs this class!

    public unsafe class XtWidget : IDisposable {

        [DllImport("libXt")]
            private static extern 

        public IntPtr dpy_handle; // X11 display handle
        //public 

        public void Dispose() {
            // TODO: write Xt widget disposer
        }

    }

}