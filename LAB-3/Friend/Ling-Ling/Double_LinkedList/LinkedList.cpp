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
        size += 1; 
    }
    else if (pos == size){
        Node *temp = head;
        for (int i = 0; i < size-1; i++)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setNext(NULL);
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
        size -= 1;
        // cout << "case 2";
    }
    else if (pos == size-1){
        Node *temp = head;
        for (int i = 0; i < size-2; i++)
        {
            temp = temp->getNext();
        }
        value = temp->getNext();
        tail = temp;
        temp->setNext(NULL);
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

void LinkedList::printpok()
{
    Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " Value : " << temp->getValue() << " Addr : " << temp <<" Next -> " << temp->getNext() << endl;
        temp = head->getNext();
        cout << "TEMP NEXT : " << temp->getValue() <<
    }
}