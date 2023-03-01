#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

Node::Node()
{
    value = 0;
    prevaddr = nullptr;
    nextaddr = nullptr;
}

Node::Node(int newvalue, Node *newprevaddr, Node *newnextaddr)
{
    value = newvalue;
    prevaddr = newprevaddr;
    nextaddr = newnextaddr;
}

void Node::setValue(int newValue)
{
    value = newValue;
}

int Node::getValue()
{
    return value;
}

void Node::setprevaddr(Node *newprevaddr)
{
    prevaddr = newprevaddr;
}

void Node::setnextaddr(Node *newnextaddr)
{
    nextaddr = newnextaddr;
}

Node *Node::getprevaddr()
{
    return prevaddr;
}

Node *Node::getnextaddr()
{
    return nextaddr;
}