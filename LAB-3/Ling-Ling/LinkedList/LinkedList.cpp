#include "LinkedList.h"

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedList::insert(Node *newNode, int pos){
    if (pos == 0)
    {
        head = newNode;
        tail = newNode;
        newNode->setNext(NULL);
        newNode->setPrev(NULL);
        size += 1; 
    }
    else if (pos < size && pos > 0){
        Node *temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->getNext();
        }
        Node *A = temp->getNext();
        temp->setNext(newNode);
        newNode->setNext(A);
        A->setPrev(newNode);
        newNode->setPrev(temp);
        size += 1; 
    }
    else if (pos == size){
        Node *temp = tail;
        temp->setNext(newNode);
        newNode->setNext(NULL);
        newNode->setPrev(temp);
        tail = newNode;
        size += 1;
    } 
    else{
        cout << "position is not in scope" << endl;
    }
}

Node* LinkedList::remove(int pos){
    Node* value = new Node();
    if (pos == 0)
    {
        value = head;
        head = head->getNext();
        head->setPrev(NULL);
        size -= 1;
        // cout << "case 1";
    }
    else if (pos < size-1 && pos > 0)
    {
        Node *temp = head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->getNext();
        }
        Node *A = temp->getNext();
        value = A;
        temp->setNext(A->getNext());
        temp->getNext()->setPrev(temp);
        size -= 1;
        // cout << "case 2";
    }
    else if (pos == size-1){
        Node *temp = tail;
        value = temp->getPrev();
        tail = temp->getPrev();
        temp->getPrev()->setNext(NULL);
        size -= 1;
        // cout << "case 3";
    }
    else{
        cout << "position is not in scope" << endl;
    }
    return value;
};


void LinkedList::print(){
    Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << temp->getValue() << endl;
        temp = temp->getNext();
    }
}

void LinkedList::printReverse(){
    Node *temp = tail;
    for (int i = 0; i < size; i++)
    {
        cout << temp->getValue() << endl;
        temp = temp->getPrev();
    }
}