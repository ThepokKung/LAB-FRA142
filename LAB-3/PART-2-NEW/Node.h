#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node
{
private:
    int value;
    Node *prev;
    Node *next;

public:
    Node(); // default constructor
    Node(int newValue, Node *newPrev, Node *newNext);
    /* Getter */
    int getValue();
    Node *getPrev();
    Node *getNext();
    /* Setter */
    void setValue(int newValue);
    void setPrev(Node *newPrev);
    void setNext(Node *newNext);
};

#endif