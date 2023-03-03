#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

class Stack : public LinkedList
{
private:
    /* data */
public:
    Stack();
    ~Stack();
    void push(Node *newNode);
    Node *pop();
    Node *peek();
};

#endif