#include "mygl.h"


MyGL::MyGL(QWidget *parrent):
    QGLWidget (parrent)
{
    xAxisRotation = yAxisRotation = 0;
    scale = 1;
    ww = hh = 3;
    XYZ = 1;
}

void MyGL::setE(Emkost *e)
{
    isSetNode = true;
    E = e;
}

void MyGL::delE()
{
    isSetNode = false;
}

void MyGL::setXYZ(int xyz)
{
    if(xyz<0)
    {
        throw QString("Отрицательная длина оси");
    }
    else
    {
        XYZ = xyz;
    }

}

void MyGL::drawXYZ(bool i)
{
    isXYZ = i;
}

void MyGL::drawAxis(float x, float y, float z)
{
    glLineWidth(3.0f); // устанавливаем ширину линии

    glBegin(GL_LINES); // построение линии
       // ось x
       glColor4f(1.00f, 0.00f, 0.00f, 1.0f); // устанавливается цвет последующих линий
       glVertex3f( x,  0.0f,  0.0f); // первая точка
       glVertex3f(-x,  0.0f,  0.0f); // вторая точка

       // ось y
       glColor4f(0.00f, 1.00f, 0.00f, 1.0f);
       glVertex3f( 0.0f,  y,  0.0f);
       glVertex3f( 0.0f, -y,  0.0f);

       // ось z
       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       glVertex3f( 0.0f,  0.0f,  z);
       glVertex3f( 0.0f,  0.0f, -z);
    glEnd();

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    renderText(static_cast<double>(x), 0, 0, QString::fromUtf8("X"), QFont());
    renderText(-static_cast<double>(x), 0, 0, QString::fromUtf8("-X"), QFont());

    glColor4f(0.00f, 1.00f, 0.00f, 1.0f);
    renderText(0, static_cast<double>(y), 0, QString::fromUtf8("Y"), QFont());
    renderText(0, -static_cast<double>(y), 0, QString::fromUtf8("-Y"), QFont());

    glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
    renderText(0, 0, static_cast<double>(z), QString::fromUtf8("Z"), QFont());
    renderText(0, 0, -static_cast<double>(z), QString::fromUtf8("-Z"), QFont());

    glLineWidth(1.0f);
}

void MyGL::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);  // заполняем экран цветом

    glEnable(GL_DEPTH_TEST);  // задаем глубину проверки пикселей
    glShadeModel(GL_FLAT);  // убираем режим сглаживания цветов
    //glEnable(GL_CULL_FACE);  // говорим, что будем строить только внешние поверхности

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

}

void MyGL::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);  // установка режима матрицы
    glLoadIdentity();  // загрузка единичной матрицы
    //glOrtho(-0.5, 1.5, -0.5, 1.5, -10.0, 10.0);

    glOrtho(-ww, ww, -hh, hh, -10, 10);  // видимые границы
    glViewport(0, 0, static_cast<GLint>(w), static_cast<GLint>(h));  // установка точки обзора
    currentWidth = w;
    currentHeight = h;
}

void MyGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // очистка экрана
    glMatrixMode(GL_MODELVIEW);  // задаем модельно-видовую матрицу
    glLoadIdentity();  // загрузка единичную матрицу

    glScaled(scale, scale, scale);        // масштабирование
    glRotated(yAxisRotation, 0.0, 1.0, 0.0);
    glRotated(xAxisRotation, 1.0, 0.0, 0.0);

    if(isXYZ) drawAxis(XYZ, XYZ, XYZ);

    if(isSetNode) E->draw();
}

void MyGL::mousePressEvent(QMouseEvent *event)
{
    pressPosition = event->pos();
}

void MyGL::mouseMoveEvent(QMouseEvent *event)
{
    xAxisRotation += (180 / scale * ((event->y()) - (pressPosition.y()))) / (currentHeight);
    yAxisRotation += (180 / scale * ((event->x()) - (pressPosition.x()))) / (currentWidth);

    pressPosition = event->pos();

    updateGL();
}

void MyGL::wheelEvent(QWheelEvent *event)
{
    // если колесико вращаем вперед -- умножаем переменную масштаба на 1.1
    // иначе -- делим на 1.1
    if ((event->delta())>0)
        scale *= 1.1;
    else
        if ((event->delta())<0)
            scale /= 1.1;
    updateGL();
}
