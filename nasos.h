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
    void Do();

private:
    bool State;
    double Potok;
    Emkost *InE, *OutE;

};

#endif // NASOS_H
