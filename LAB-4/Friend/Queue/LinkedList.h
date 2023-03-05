#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList();
    void print();
    void insert(Node *newNode, int index);
    void remove(int index);
    void append(Node *newNode);
    Node *gethead();
    Node *gettail();
    int getsize();
};

#endif