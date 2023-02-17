#ifndef LINKED_H
#define LINKED_H
#include "Node.h"
class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();
    void insert(Node *newNode, int pos);
    Node* remove(int pos);
    void print();
};

#endif