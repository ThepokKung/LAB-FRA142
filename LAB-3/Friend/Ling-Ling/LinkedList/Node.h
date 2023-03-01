#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
class Node
{
private:
    int value;
    Node *prev;
    Node *next;

public:
    Node();
    Node(int newValue, Node *newPrev, Node *newNext);
    int getValue();
    void setValue(int newValue);
    Node* getNext();
    void setNext(Node *newNext);
    Node* getPrev();
    void setPrev(Node *newPrev);
};

#endif