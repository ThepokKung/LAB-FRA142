#include "LinkedList.h"

LinkedList::LinkedList() // constructor
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DEBUGLINKLIST = true; // DEBUGLINKLIST

void LinkedList::insert(Node *newNode, int pos)
{
    if (size == 0) // First Nodes
    {
        head = newNode;
        tail = newNode;
        head->setNext(nullptr);
        head->setPrev(nullptr);
        tail->setNext(nullptr);
        tail->setPrev(nullptr);
        size++;
        if (DEBUGLINKLIST == true)
        {
            cout << "YOUR POS INPUT " << pos << " INSERT CASE SIZE = 0" << endl;
        }
    }
    else if (pos > size or abs(pos) > size)
    {
        {
            if (DEBUGLINKLIST == true)
            {
                cout << "YOUR POS INPUT " << pos << " INSERT ERROR POSITION OVERLOAD" << endl;
            }
        }
    }
    else if (size != 0)
    {
        if (pos < 0) // Position < 0 (-)
        {
            if (abs(pos) == 1)
            {
                Node *temp = tail->getPrev();
                temp->setNext(newNode);
                newNode->setPrev(temp);
                newNode->setNext(tail);
                tail->setPrev(newNode);
                size++;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE POSSITION = -1" << endl;
                }
            }
            else if (abs(pos) < size) //Position < size 
            {
                Node *temp = tail;
                for (int i = 0; i < abs(pos) - 1; i++)
                {
                    temp = temp->getPrev();
                }
                Node *tempPrev = temp->getPrev();
                tempPrev->setNext(newNode);
                newNode->setPrev(tempPrev);
                newNode->setNext(temp);
                temp->setPrev(newNode);
                size++;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE ABS(POS)MIDDLE " << endl;
                }
            }
            else if (abs(pos) == size)
            {
                newNode->setNext(head);
                newNode->setPrev(nullptr);
                head->setPrev(newNode);
                head = newNode;
                size++;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE ABS(POS) POSSITION = SIZE" << endl;
                }
            }
        }
        else if (pos > 0)
        {
            if (pos == 0)
            {
                newNode->setNext(head);
                newNode->setPrev(nullptr);
                head->setPrev(newNode);
                head = newNode;
                size++;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " INSERT CASE POSSITION = 0" << endl;
                }
            }
            else if (pos == size)
            {
                tail->setNext(newNode);
                newNode->setPrev(tail);
                newNode->setNext(nullptr);
                tail = newNode;
                size++;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " INSERT CASE POSSITION = SIZE" << endl;
                }
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
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " INSERT CASE MIDDELE" << endl;
                }
            }
        }
    }
    else
    {
        if (DEBUGLINKLIST == true)
        {
            cout << "YOUR POS INPUT " << pos << " ERROR INSERT POSITION UNKNOW" << endl;
        }
    }
}

void LinkedList::remove(int pos)
{
    if (size == 0)
    {
        if (DEBUGLINKLIST == true)
        {
            cout << "YOUR POS INPUT " << pos << " ERROR CASE SIZE = 0" << endl;
        }
    }
    else if (pos >= size or abs(pos) > size)
    {
        {
            if (DEBUGLINKLIST == true)
            {
                cout << "YOUR POS INPUT " << pos << " ERROR REMOVE POSITION >= SIZE" << endl;
            }
        }
    }
    else if (size != 0)
    {
        if (pos < 0)
        {
            if (abs(pos) == 1)
            {
                Node *temp = tail->getPrev();
                tail->setPrev(nullptr);
                tail->setNext(nullptr);
                temp->setNext(nullptr);
                tail = temp;
                size--;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " REMOVE CASE ABS(POS) = -1" << endl;
                }
            }
            else if (abs(pos) < size)
            {
                Node *temp = tail;
                for (int i = 0; i < abs(pos) - 1; i++)
                {
                    temp = temp->getPrev();
                }
                Node *tempPrev = temp->getNext();
                Node *tempNext = temp->getPrev();
                temp->setNext(nullptr);
                temp->setPrev(nullptr);
                tempPrev->setPrev(tempNext);
                tempNext->setNext(tempPrev);
                size--;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " REMOVE CASE ABS(POS)MIDDLE " << endl;
                }
            }
            else if (abs(pos) == size)
            {
                Node *temp = head->getNext();
                temp->setPrev(nullptr);
                head->setNext(nullptr);
                head = temp;
                size--;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " REMOVE CASE (ABS)POS = SIZE" << endl;
                }
            }
        }
        else if (pos > 0)
        {
            if (pos == 0)
            {
                Node *temp = head->getNext();
                temp->setPrev(NULL);
                head = temp;
                size--;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " REMOVE CASE POS = 0" << endl;
                }
            }
            else if (pos == size - 1)
            {
                Node *temp = tail->getPrev();
                temp->setNext(NULL);
                tail = temp;
                size--;
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " REMOVE CASE POS = SIZE" << endl;
                }
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
                if (DEBUGLINKLIST == true)
                {
                    cout << "YOUR POS INPUT " << pos << " REMOVE CASE MIDDLE " << endl;
                }
            }
        }
    }
    else
    {
        if (DEBUGLINKLIST == true)
        {
            cout << "YOUR POS INPUT " << pos << " ERROR REMOVE POSITION UNKNOW" << endl;
        }
    }
}

void LinkedList::append(Node *newNode)
{
    tail->setNext(newNode);
    newNode->setPrev(tail);
    newNode->setNext(nullptr);
    tail = newNode;
    size++;
    if (DEBUGLINKLIST == true)
    {
        cout << "APPEND CASE" << endl;
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