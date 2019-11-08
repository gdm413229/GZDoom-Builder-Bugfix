#ifndef G4_QTIMAGEVIEW_H
#define G4_QTIMAGEVIEW_H

#include <QOpenGLWidget>

typedef struct {
    GLuint xsize; GLuint ysize; // img dimensions
    GLuint* img_handle; // handle to GL texture
    GLenum img_target; GLenum img_fmt; GLenum img_gltype; // OpenGL properties
    GLint internal_fmt; GLsizei int_width; GLsizei int_height; GLint int_border; // More GL properties
} g4_qtglimg_t;

class G4_QtImageView : public QOpenGLWidget
{
    Q_OBJECT

private:
    // GL image to view
    g4_qtglimg_t disp_img;
public:
    GLuint pub_xsize; GLuint pub_ysize; // image dimensions [public!]
public:
    G4_QtImageView(QWidget *parent = 0); // ctor
    void upload_img();
    void paintGL();
    ~G4_QtImageView(); // dtor
};

#endif // G4_QTIMAGEVIEW_H
