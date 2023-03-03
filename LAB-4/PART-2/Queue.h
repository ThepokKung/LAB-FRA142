#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

class Queue : public LinkedList
{
private:
    /* data */
public:
    Queue();
    ~Queue();
    void enqueue(Node *newNode);
    Node *dequeue();
    Node *peek();
};

#endif