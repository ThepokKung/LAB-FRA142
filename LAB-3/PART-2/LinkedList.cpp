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
        head = newNode; //
        tail = newNode;
        newNode->setNext(NULL);
        newNode->setPrev(NULL);
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
        Node *temp = tail;
        temp->setNext(newNode);
        newNode->setNext(NULL);
        newNode->setPrev(temp);
        tail = newNode;
        size++;
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
        cout << "Case : pos == 0" << endl;
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
        cout << "Value : " << i << " -> " << temp->getValue() << endl;
        temp = head->getNext();
    }
}
