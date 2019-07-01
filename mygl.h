#ifndef MYGL_H
#define MYGL_H

#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>
#include <qgl.h>

#include "emkost.h"

class MyGL: public QGLWidget
{
    Q_OBJECT

public:
    MyGL(QWidget *parrent = nullptr);
    void setE(Emkost *e);
    void delE();
    void setXYZ(int xyz);
    //void drawC2(bool i);
    void drawXYZ(bool i);

private:
    QPoint pressPosition, releasePosition;
    GLdouble xAxisRotation, yAxisRotation;
    GLdouble scale;
    GLdouble currentWidth, currentHeight;
    GLdouble hh, ww;

    int XYZ;
    bool isSetNode = false, is2=true, isXYZ=true;

    Emkost *E;

    void drawAxis(float x, float y, float z);
    //void drawEmkost();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
};

#endif // MYGL_H
