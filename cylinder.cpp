#include "cylinder.h"

Cylinder::Cylinder()
{
    quadratic=gluNewQuadric();     // Создаем указатель на квадратичный объект ( НОВОЕ )
    gluQuadricNormals(quadratic, GLU_SMOOTH); // Создаем плавные нормали ( НОВОЕ )
    gluQuadricTexture(quadratic, GL_TRUE);    // Создаем координаты текстуры ( НОВОЕ )

    R = 0;
    H = 0;
    Litr = 0;

}

void Cylinder::setRH(double r, double h)
{
    if(r<0 || h<0)
        throw QString("Нельзя отрицательное значение");
    else
    {
        Litr = 0;
        H=h;
        R=r;
    }
}

double Cylinder::Volume()
{
    return PI*R*R*H;
}

double Cylinder::getHOfLitr()
{
    return Litr/(PI*R*R);
}

void Cylinder::draw()
{
    glColor3d(1, 0, 0);
    gluCylinder(quadratic,R,R,H,32,32); // Рисуем наш цилиндр

    glTranslated(0,0,getHOfLitr());
    glColor3d(0, 1, 0);
    gluDisk(quadratic,R,R+1,32,32); // Рисуем диск (в виде CD)
}

double Cylinder::getR()
{
    return R;
}

double Cylinder::getH()
{
    return H;
}
