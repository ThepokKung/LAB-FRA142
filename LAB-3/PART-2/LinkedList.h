#ifndef LINK_H
#define LINK_H
#include "Node.h"
class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();
    void insert(Node *newNode,int pos);
    void remove(int pos);
    void print();
    void printHeadandTail();
    void printFormtail();
};


#endif