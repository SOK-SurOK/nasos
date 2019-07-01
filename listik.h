#ifndef LISTIK_H
#define LISTIK_H

#include "emkost.h"
#include "cylinder.h"
#include <QObject>
#include <QRandomGenerator>

struct Node
{
    int x;
    Emkost *E;
    Node *next;
};

class Listik
{
public:
    Listik();
    void Add();
    //void Add(int x);
    void Del();
    //void Del(int x);
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
