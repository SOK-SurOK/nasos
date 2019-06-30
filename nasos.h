#ifndef NASOS_H
#define NASOS_H

#include "emkost.h"

class Nasos
{
public:
    Nasos();
    void setInE(Emkost *E);
    void setOutE(Emkost *E);
    void setPotok(double potok);
    double getPotok();
    void Start();
    void Stop();

private:
    bool State;
    double Potok;
    Emkost *InE, *OutE;

    void updateInE();
    void updateOutE();
};

#endif // NASOS_H
