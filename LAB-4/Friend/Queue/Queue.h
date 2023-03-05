#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

class Queue: public LinkedList
{
public:
    Queue();
    ~Queue();
    void enqueue(Node *newNode);
    Node *dequeue();
    int peek();
    void de2en();
};

#endif