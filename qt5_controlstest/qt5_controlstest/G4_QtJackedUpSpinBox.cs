
/* Jacked-up SpinBox, for GZDB-Qt [Managed Side] */

// get the control's native side from libgzdb-qt_controls.so
//[DllImport("gzdb-qt_controls")]
//public static extern void make_jackedupspinbox();

using System.Runtime.InteropServices;
using System;
using QtWidgets;



namespace qt5_controlstest
{
    public class G4_QtJackedUpSpinBox : QWidget
    {
        private const string successful_creation = "Jacked-up Spinbox successfully created.";

        public G4_QtJackedUpSpinBox()
        {
            Console.Error.WriteLine(successful_creation); // write debug message to stderr
        }
        // Disposer for this widget.
        public void Dispose()
        {

        }
    }
}
