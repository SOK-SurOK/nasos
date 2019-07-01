#include "emkost.h"

Emkost::Emkost()
{

}

void Emkost::outLitr(Emkost *inLitr)
{
    double May = inLitr->Volume() - inLitr->Litr;
    double Pereliv = 0;
    Litr > May ? Pereliv = May : Pereliv = Litr;
    Litr -= Pereliv;
    inLitr->Litr += Pereliv;
}

void Emkost::outLitr(Emkost *inLitr, double kol)
{
    double May = inLitr->Volume() - inLitr->Litr;
    double Pereliv = 0;
    kol > May ? Pereliv = May : Pereliv = kol;
    Litr -= Pereliv;
    inLitr->Litr += Pereliv;
}

void Emkost::outLitr(double kol)
{
    double May = Litr;
    double Pereliv = 0;
    kol > May ? Pereliv = May : Pereliv = kol;
    Litr -= Pereliv;
}

void Emkost::inLitr(double kol)
{
    double May = Volume() - Litr;
    double Pereliv = 0;
    kol > May ? Pereliv = May : Pereliv = kol;
    Litr += Pereliv;
}

void Emkost::setLitr(double litr)
{
    if(litr>=0 && litr<=Volume())
    {
        Litr= litr;
    }
    else
    {
        throw QString("Плохие литры");
    }
}

double Emkost::getLitr()
{
    return Litr;
}

Emkost::~Emkost()
{

}


