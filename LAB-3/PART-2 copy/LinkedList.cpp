#include "LinkedList.h"

LinkedList::LinkedList() // constructor
{
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedList::insert(Node *newNode, int pos)
{
    if (pos == 0)
    {
        head = newNode; 
        tail = newNode;
        size++;
        cout << "case 0 " << endl;
    }
    else if (pos < size && pos > 0)
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->getNext();
        }
        Node *temp2 = temp->getNext();
        temp->setNext(newNode);
        newNode->setNext(temp2);
        temp2->setPrev(newNode);
        newNode->setPrev(temp);
        size++;
        cout << "case 1 " << endl;
    }
    else if (pos == size)
    {
        Node *temp = tail;
        temp->setNext(newNode);
        // newNode->setNext(NULL);
        newNode->setPrev(temp);
        tail = newNode;
        size++;
        cout << "case 2 " << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
}

void LinkedList::remove(int pos)
{
    Node *value = new Node();
    if (pos == 0)
    {
        value = head;
        head = head->getNext();
        head->setPrev(NULL);
        size--;
    }
    else if (pos < size - 1 && pos > 0)
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->getNext();
        }
        Node *A = temp->getNext();
        value = A;
        temp->setNext(A->getNext());
        temp->getNext()->setPrev(temp);
        size--;
    }
    else if (pos == size - 1)
    {
        Node *temp = tail;
        value = temp->getPrev();
        tail = temp->getPrev();
        temp->getPrev()->setNext(NULL);
        size--;
    }
    else
    {
        cout << "Error" << endl;
    }
}


void LinkedList::print()
{
     Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " Value : " << temp->getValue() << " Addr : " << temp <<" Prev -> " << temp->getPrev() << " Next -> " << temp->getNext() << endl;
        temp = temp->getNext();
    }
}
