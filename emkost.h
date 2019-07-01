#ifndef EMKOST_H
#define EMKOST_H

#include <QObject>
#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>
#include <qgl.h>
#include <QGL>

const double PI = 3.1415927;

class Emkost
{
public:
    Emkost();
    void setLitr(double litr);
    double getLitr();
    virtual ~Emkost();

    virtual double Volume() = 0;
    virtual double getHOfLitr() = 0;
    virtual void outLitr(Emkost *inLitr);
    virtual void outLitr(Emkost *inLitr, double kol);
    virtual void outLitr(double kol);
    virtual void inLitr(double kol);
    virtual void draw() = 0;


protected:
    double Litr;
};

#endif // EMKOST_H
