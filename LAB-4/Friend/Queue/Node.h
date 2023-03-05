#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node
{
private:
    int value;
    Node *prev ;
    Node *next ;
public:
    Node();
    Node(int newvalue, Node *newprev, Node *newnext);
    void setnext(Node *newnext);
    void setprev(Node *newprev);
    void setvalue(int newvalue);
    Node *getnext();
    Node *getprev();
    int getvalue();
    void Info();
};

#endif