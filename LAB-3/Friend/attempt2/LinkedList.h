#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();

    LinkedList(Node *newHead, Node *newTail);

    Node *getHead();

    void setHead(Node *newHead);
    
    Node *getTail();

    void setTail(Node *newTail);

    int getSize();

    void setSize(int newSize);

    void insert(Node *newNode, int pos);

    Node *remove(int pos);

    void printList();
};

#endif
