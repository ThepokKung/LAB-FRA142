#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack():LinkedList()
{}

Stack::~Stack()
{}

void Stack::push(Node *newNode)
{
    insert(newNode,0);
}

Node *Stack::pop()
{
    Node *temp = gethead();
    remove(0);
    return temp;
}

int Stack::peek()
{
    Node *temp = gethead();
    return temp->getvalue();
}