#include "Node.h"

Node::Node()
{
    value = 0;
    prev = nullptr;
    next = nullptr;
}

Node::Node(int newValue, Node *newPrev, Node *newNext)
{
    value = newValue;
    prev = newPrev;
    next = newNext;
}

/* Getther */
int Node::getValue()
{
    return value;
}
Node *Node::getPrev()
{
    return prev;
}

Node *Node::getNext()
{
    return next;
}

/* Setter */
void Node::setValue(int newValue){
    value = newValue;
}

void Node::setPrev(Node *newPrev){
    prev = newPrev;
}

void Node::setNext(Node *newNext){
    next = newNext;
}