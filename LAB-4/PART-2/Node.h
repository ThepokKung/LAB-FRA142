#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *next;
    Node *prev;

public:
    Node();                                           // default constructor
    Node(int newValue, Node *newPrev, Node *newNext); // constructor
    void printValue();
    void printNext();
    void printAll();
    /* Getter */
    Node *getNext();
    int getValue();
    Node *getPrev();
    /* Setter */
    void setValue(int newValue);
    void setNext(Node *newNext);
    void setPrev(Node *newPrev);
};

#endif // NODE_H
