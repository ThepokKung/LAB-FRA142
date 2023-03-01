#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *next;

public:
    Node();
    Node(int newValue, Node *newNext);
    void print();
    int getValue();
    void setValue(int newValue);
    Node* getNext();
    void setNext(Node *newNext);
};

#endif