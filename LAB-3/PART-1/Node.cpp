#include <iostream>
#include "Node.h"
using namespace std;

Node::Node() // Constructor
{
    value = 0;
    next = NULL;
}

Node::Node(int newValue, Node *newNext)
{
    value = newValue;
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

/* ALL */

void Node::printAll() // Print
{
    cout << "Valaue : " << value << " , Next : " << next->getValue() << endl;
}