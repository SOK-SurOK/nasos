#ifndef CYLINDER_H
#define CYLINDER_H

#include "emkost.h"

class Cylinder: public Emkost
{
public:
    explicit Cylinder();
    void setRH(float r, float h);
    double Volume() override;
    double getHOfLitr() override;
    double getR();
    double getH();
private:
    double R, H;
};

#endif // CYLINDER_H
