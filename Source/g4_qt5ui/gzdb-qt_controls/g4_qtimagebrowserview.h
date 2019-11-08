#ifndef G4_QTIMAGEBROWSERVIEW_H
#define G4_QTIMAGEBROWSERVIEW_H

#include <QOpenGLWidget>

class G4_QtImageBrowserView : public QOpenGLWidget
{
    Q_OBJECT

public:
    G4_QtImageBrowserView(QWidget *parent = 0);
};

#endif // G4_QTIMAGEBROWSERVIEW_H
