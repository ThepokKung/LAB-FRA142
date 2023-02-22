#include "Node.h"

Node::Node() // Constructor
{
    value = 0;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int newValue, Node *newPrev, Node *newNext)
{
    value = newValue;
    prev = newPrev;
    next = newNext;
}

/* Value */
void Node::printValue() // Print value
{
    cout << "Value : " << value << endl;
}

void Node::setValue(int newValue)
{
    value = newValue;
}

int Node::getValue() // returns Value
{
    return value;
}

/* Next */
void Node::printNext() // Print Next value
{
    cout << "Next : " << next << endl;
}

void Node::setNext(Node *newNext) // Sets next value
{
    next = newNext;
}

Node *Node::getNext() // returns next Node
{
    return next;
}

/* Prev */
void Node::setPrev(Node *newPrev) // Sets prev value
{
    prev = newPrev;
}
Node *Node::getPrev() // returns prev Node
{
    return prev;
}
/* ALL */

void Node::printAll() // Print
{
    cout << "Valaue : " << value << " , Prev : " << prev << " , Next : " << next << endl;
}