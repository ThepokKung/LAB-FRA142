#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node *next;

public:
    Node(); // default constructor
    Node(int newValue, Node *newNext); // constructor
    void printValue();
    void printNext();
    void printAll();
    // Getter
    Node* getNext();
    int getValue();
    // Setter
    void setValue(int newValue);
    void setNext(Node *newNext);
};

#endif // NODE_H
