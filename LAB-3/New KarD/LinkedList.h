#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList
{
private:
    Node *first = nullptr;
    Node *last = nullptr;
    int size;

public:
    LinkedList();
    int insert(Node *newNode, int pos);
    int remove(int pos);
    void show();
    void showfl();
    void printpok();
};

#endif