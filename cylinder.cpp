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
    return Litr/PI*R*R;
}

void Cylinder::draw()
{
    gluCylinder(quadratic,1.0,1.0,3.0,32,32); // Рисуем наш цилиндр
    gluDisk(quadratic,0.5,1.5,32,32); // Рисуем диск (в виде CD)
}

double Cylinder::getR()
{
    return R;
}

double Cylinder::getH()
{
    return H;
}
