#ifndef LISTIK_H
#define LISTIK_H

#include "emkost.h"
#include "cylinder.h"
#include "nasos.h"
#include <QObject>
#include <QRandomGenerator>

struct Node
{
    int x;
    Emkost *E;
    Nasos *n1, *n2;
    Node *next;
};

class Listik
{
public:
    Listik();
    void Add();
    void Del();
    Nasos *getN1(int x);
    Nasos *getN2(int x);
    Emkost *getEmkost(int x);
    int getSize();
    void AllRandom();
    ~Listik();
private:
    Node *head, *tail;
    int X;
    Node *Find(int x);
};

#endif // LISTIK_H
