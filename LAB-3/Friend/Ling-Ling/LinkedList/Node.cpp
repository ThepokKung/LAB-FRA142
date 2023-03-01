#include "Node.h"

Node::Node(){
    value = 0;
    prev = NULL;
    next = NULL;
}

Node::Node(int newValue, Node *newPrev, Node *newNext){
    value = newValue;
    prev = newPrev;
    next = newNext;
}

int Node::getValue(){
    return value;
}

void Node::setValue(int newValue){
    value = newValue;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setPrev(Node *newPrev){
    prev = newPrev;
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node *newNext){
    next = newNext;
}