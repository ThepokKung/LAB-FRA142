#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

class Stack: public LinkedList
{
public:
    Stack();
    ~Stack();
    void push(Node *newNode);
    Node *pop();
    int peek();
};

#endif