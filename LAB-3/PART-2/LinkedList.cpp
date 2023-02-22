#include "LinkedList.h"

LinkedList::LinkedList() // constructor
{
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedList::insert(Node *newNode, int pos)
{
    if (size == 0)
    {
        head = newNode;
        tail = newNode;
        head->setNext(NULL);
        head->setPrev(NULL);
        tail->setNext(NULL);
        tail->setPrev(NULL);
        size++;
        cout << "INSERT CASE SIZE = 0" << endl;
    }
    else if (pos > size or pos < 0)
    {
        {
            cout << "ERROR POSITION ERROR" << endl;
        }
    }
    else if (size != 0)
    {
        if (pos == 0)
        {
            newNode->setNext(head);
            newNode->setPrev(nullptr);
            head->setPrev(newNode);
            head = newNode;
            size++;
            cout << "INSERT CASE POSSITION = 0" << endl;
        }
        else if (pos == size)
        {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            newNode->setNext(nullptr);
            tail = newNode;
            size++;
            cout << "INSERT CASE POSSITION = SIZE" << endl;
        }
        else if (pos > 0 or pos < size)
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->getNext();
            }
            Node *temp2 = temp->getNext();
            temp->setNext(newNode);
            newNode->setPrev(temp);
            newNode->setNext(temp2);
            temp2->setPrev(newNode);
            size++;
            cout << "INSERT CASE MIDDELE" << endl;
        }
    }
    else
    {
        cout << "ERROR INSERT POSITION ERROR" << endl;
    }
}

void LinkedList::remove(int pos)
{
    if (size == 0)
    {
        cout << "ERROR CASE SIZE = 0" << endl;
    }
    else if (pos > size or pos < 0)
    {
        {
            cout << "ERROR REMOVE POSITION ERROR" << endl;
        }
    }
    else if (size == pos)
    {
        cout << "ERROR REMOVE POSITION ERROR" << endl;
    }
    else if (size != 0)
    {
        if (pos == 0)
        {
            Node *temp = head->getNext();
            temp->setPrev(NULL);
            head = temp;
            size--;
            cout << "REMOVE CASE POS = 0" << endl;
        }
        else if (pos == size - 1)
        {
            Node *temp = tail->getPrev();
            temp->setNext(NULL);
            tail = temp;
            size--;
            cout << "REMOVE CASE POS = SIZE" << endl;
        }
        else if (pos > 0 or pos < size)
        {
            Node *temp = head;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->getNext();
            }
            Node *tempPrev = temp->getPrev();
            Node *tempNext = temp->getNext();
            tempPrev->setNext(tempNext);
            tempNext->setPrev(tempPrev);
            size--;
            cout << "REMOVE CASE MIDDLE " << endl;
        }
    }
    else
    {
        cout << "ERROR REMOVE POSITION ERROR" << endl;
    }
}

void LinkedList::print()
{
    Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " Value : " << temp->getValue() << " Addr : " << temp << " Prev -> " << temp->getPrev() << " Next -> " << temp->getNext() << endl;
        temp = temp->getNext();
    }
}

void LinkedList::printFormtail()
{
    // cout << "PRINT HEAD" << endl;
    Node *temp = tail;
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " Value : " << temp->getValue() << " Addr : " << temp << " Prev -> " << temp->getPrev() << " Next -> " << temp->getNext() << endl;
        temp = temp->getPrev();
    }
}

void LinkedList::printHeadandTail()
{
    cout << "Head " << head << endl;
    cout << "Tail " << tail << endl;
}

void LinkedList::append(Node *newNode)
{
    tail->setNext(newNode);
    newNode->setPrev(tail);
    newNode->setNext(nullptr);
    tail = newNode;
    size++;
    cout << "APPEND CASE" << endl;
}