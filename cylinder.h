#ifndef CYLINDER_H
#define CYLINDER_H

#include "emkost.h"

class Cylinder: public Emkost
{
public:
    explicit Cylinder();
    void setRH(double r, double h);
    double Volume() override;
    double getHOfLitr() override;
    void draw() override;
    double getR();
    double getH();
private:
    GLUquadricObj *quadratic;    // Место для хранения объекта Quadratic ( НОВОЕ )
    double R, H;
};

#endif // CYLINDER_H
