#include "listik.h"

Listik::Listik()
{
    head = nullptr;
    tail = nullptr;
    X = 0;
}

void Listik::Add()
{
    Node *temp = new Node;
    temp->next = nullptr;
    temp->x = X++;
    temp->E = new Cylinder();

    if(head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void Listik::Del()
{
    Node *head2;
    while (head != nullptr)
    {
        head2 = head;
        head = head->next;
        delete head2->E;
        delete head2;
    }
    X = 0;
}

Emkost *Listik::getEmkost(int x)
{
    if(x>=0 && x<X)
    {
        Node *head2;
        head2 = head;
        while (head2->x != x)
        {
            head2 = head2->next;
        }
        return head2->E;
    }
    else
    {
        throw QString("неправильный индекс элемента");
        //return nullptr;
    }
}

int Listik::getSize()
{
    return X;
}

void Listik::AllRandom()
{

}

int RandomBetween(int low, int high)
{
    qint64 l = low, h = high;
    unsigned int value = static_cast<unsigned int>(QRandomGenerator::global()->generate());
    return static_cast<int>(value % ((h + 1) - l) + l);
}
