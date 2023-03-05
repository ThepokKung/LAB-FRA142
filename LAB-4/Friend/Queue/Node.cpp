#include <iostream>
#include "Node.h"
using namespace std;

Node::Node()
{
    value = 0;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int newvalue, Node *newprev, Node *newnext)
{
    value = newvalue;
    next = newnext;
    prev = newprev;
}

void Node::setprev(Node *newprev)
{
    prev = newprev;
}

Node *Node::getprev()
{
    return prev;
}

void Node::setnext(Node *newnext)
{
    next = newnext;
}

Node *Node::getnext()
{
    return next;
}

void Node::setvalue(int newvalue)
{
    value = newvalue;
}

int Node::getvalue()
{
    return value ;
}

void Node::Info() {
    cout << "N : " << next << endl;
    cout << "P : " << prev << endl;
}