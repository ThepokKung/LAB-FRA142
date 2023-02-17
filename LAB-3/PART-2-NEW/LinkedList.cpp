#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::insert(Node *newNode, int pos)
{
    if (pos == 0)
    {
        head = newNode;
        tail = newNode;
        newNode->setNext(nullptr);
        newNode->setPrev(nullptr);
        size++;
    }
    else if (pos < size && pos > 0)
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->getNext();
        }
        Node *A = temp->getNext();
        temp->setNext(newNode);
        newNode->setNext(A);
        A->setPrev(newNode);
        newNode->setPrev(temp);
        size++;
    }
    else if (pos == size)
    {
        Node *Temp = tail;
        Temp->setNext(newNode);
        newNode->setNext(nullptr);
        newNode->setPrev(Temp);
        tail = newNode;
        size++;
    }
    else {
        cout << "Error" << endl;
    }
}

Node* LinkedList::remove(int pos){
    Node* value = new Node();
    if (pos == 0)
    {
        value = head;
        head = head->getNext();
        head->setPrev(NULL);
        size--;
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
        size--;
    }
    else if (pos == size-1){
        Node *temp = tail;
        value = temp->getPrev();
        tail = temp->getPrev();
        temp->getPrev()->setNext(NULL);
        size--;
    }
    else{
        cout << "Error" << endl;
    }
    return value;
};

void LinkedList::print(){
    Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << "Value : "<< i << " -> " << temp->getValue() << endl;
        temp = temp->getNext();
    }
}

void LinkedList::printRe(){
    Node *temp = tail;
    for(int i = 0; i < size; i++){
        cout << "Value : "<< i << " -> " << temp->getValue() << endl;
        temp = temp->getPrev();
    }
}
