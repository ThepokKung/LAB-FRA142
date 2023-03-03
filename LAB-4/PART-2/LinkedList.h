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
    void insert(Node *newNode, int pos);
    Node *remove(int pos);
    void print();
    void printheadandtail();
    void printformtail();
    void append(Node *newNode);
    int getsize();
    Node *getTail();
    Node *getHead();
};
#endif