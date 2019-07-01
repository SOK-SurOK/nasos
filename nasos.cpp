#include "nasos.h"

Nasos::Nasos()
{
    InE = nullptr;
    OutE = nullptr;
    Potok = 0;
}

void Nasos::setInE(Emkost *E)
{
    InE = E;
}

void Nasos::setOutE(Emkost *E)
{
    OutE = E;
}

void Nasos::setPotok(double potok)
{
    if(Potok>=0)
    {
        Potok = potok;
    }
    else
    {
        throw QString("Нельзя отрицательный поток");
    }
}
double Nasos::getPotok()
{
    return Potok;
}

void Nasos::Start()
{

}

void Nasos::Stop()
{

}

void Nasos::Do()
{
    if(InE == nullptr)
    {
        if(OutE != nullptr)
        {
            OutE->outLitr(Potok);
        }
        else
        {
            throw QString("насос никуда не подсоединен");
        }
    }
    else
    {
        if(OutE == nullptr)
        {
            InE->inLitr(Potok);
        }
        else
        {
            InE->outLitr(OutE, Potok);
        }
    }
}

