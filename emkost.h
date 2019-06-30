#ifndef EMKOST_H
#define EMKOST_H


class Emkost
{
public:
    Emkost();
    void setLitr(double litr);
    double getLitr();
    virtual ~Emkost();

    virtual double Volume() = 0;
    virtual double getHOfLitr() = 0;
    virtual void outLitr(Emkost *inLitr) = 0;
    virtual void draw() = 0;

protected:
    double Litr;
};

#endif // EMKOST_H
