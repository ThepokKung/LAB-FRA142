#include "LinkedList.h"

// #define DEBUG

LinkedList::LinkedList() // constructor
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::insert(Node *newNode, int pos) // insert to linked list
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
#ifdef DEBUG
        cout << "YOUR POS INPUT " << pos << " INSERT CASE SIZE = 0" << endl;
#endif
    }
    else if (pos > size or abs(pos) > size) // Size position overloaded
    {
#ifdef DEBUG
        cout << "YOUR POS INPUT " << pos << " INSERT ERROR POSITION OVERLOAD" << endl;
#endif
    }
    else if (size != 0) // Have size in linked list
    {
        if (pos == 0) // Input position == 0 but have size in linked list
        {
            newNode->setNext(head);
            newNode->setPrev(nullptr);
            head->setPrev(newNode);
            head = newNode;
            size++;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " INSERT CASE POSSITION = 0" << endl;
#endif
        }
        else if (pos == size) // Input position == size. It's don't add to last it second to last.

        {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            newNode->setNext(nullptr);
            tail = newNode;
            size++;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " INSERT CASE POSSITION = SIZE" << endl;
#endif
        }
        else if (pos > 0 or pos < size) // Input position > 0 or pos < size. Insert in middle of linked list
        {
            Node *temp = head;                // Starting for head position
            for (int i = 0; i < pos - 1; i++) // Loop to position (-1 for Goto perv position)
            {
                temp = temp->getNext(); // Next head loop
            }
            Node *temp2 = temp->getNext(); // Next position to temp for add to newNode
            temp->setNext(newNode);
            newNode->setPrev(temp);
            newNode->setNext(temp2);
            temp2->setPrev(newNode);
            size++;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " INSERT CASE MIDDELE" << endl;
#endif
        }
        if (pos < 0) // Position < 0 (-)
        {
            if (abs(pos) == 1)
            {
                Node *temp = tail->getPrev(); // In pos =1, it's start for tail and Go next position is Prev for tail
                temp->setNext(newNode);
                newNode->setPrev(temp);
                newNode->setNext(tail);
                tail->setPrev(newNode);
                size++;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE POSSITION = -1" << endl;
#endif
            }
            else if (abs(pos) < size) // Position < size or insert pos to Middle
            {
                Node *temp = tail; // Start form tail
                for (int i = 0; i < abs(pos) - 1; i++)
                {
                    temp = temp->getPrev(); // Go Prev to position at you want
                }
                Node *tempPrev = temp->getPrev(); // Save Prev postion
                tempPrev->setNext(newNode);
                newNode->setPrev(tempPrev);
                newNode->setNext(temp);
                temp->setPrev(newNode);
                size++;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE ABS(POS)MIDDLE " << endl;
#endif
            }
            else if (abs(pos) == size) // Position == size is add to head
            {
                newNode->setNext(head);
                newNode->setPrev(nullptr);
                head->setPrev(newNode);
                head = newNode;
                size++;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " INSERT CASE ABS(POS) POSSITION = SIZE" << endl;
#endif
            }
        }
    }
    else
    {
#ifdef DEBUG
        cout << "YOUR POS INPUT " << pos << " ERROR INSERT POSITION UNKNOW" << endl;
#endif
    }
}

void LinkedList::remove(int pos)
{
    Node *forShow = nullptr;
    bool removeReal = true;
    if (size == 0) // Call remove but don't enoune size check
    {
#ifdef DEBUG
        cout << "YOUR POS INPUT " << pos << " ERROR CASE SIZE = 0" << endl;
        removeReal = false;
#endif
    }
    else if (pos >= size or abs(pos) > size) // Position is oversize
    {
        {
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " ERROR REMOVE POSITION >= SIZE" << endl;
            removeReal = false;
#endif
        }
    }
    else if (size != 0) // Have size in linkedList
    {
        if (pos == 0) // Remove Head
        {
            Node *temp = head->getNext();
            temp->setPrev(nullptr);
            head->setNext(nullptr);
            forShow = temp;
            head = temp;
            size--;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " REMOVE CASE POS = 0" << endl;
#endif
        }
        else if (pos == size - 1) // Remove for tail (size -1 because Likedlist start from 0 )
        {
            Node *temp = tail->getPrev();
            temp->setNext(NULL);
            tail->setNext(nullptr);
            tail->setPrev(nullptr);
            forShow = tail;
            tail = temp;
            size--;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " REMOVE CASE POS = SIZE" << endl;
#endif
        }
        else if (pos > 0 or pos < size) // Remove Middle Position
        {
            Node *temp = head;
            for (int i = 0; i < pos; i++) // Loop to input position
            {
                temp = temp->getNext(); // Goto input position
            }
            Node *tempPrev = temp->getPrev();
            Node *tempNext = temp->getNext();
            temp->setNext(nullptr);
            temp->setPrev(nullptr);
            forShow = temp;
            tempPrev->setNext(tempNext);
            tempNext->setPrev(tempPrev);
            size--;
#ifdef DEBUG
            cout << "YOUR POS INPUT " << pos << " REMOVE CASE MIDDLE " << endl;
#endif
        }
        else if (pos < 0)
        {
            if (abs(pos) == 1) // Remove tail node
            {
                Node *temp = tail->getPrev();
                tail->setPrev(nullptr);
                tail->setNext(nullptr);
                temp->setNext(nullptr);
                forShow = tail;
                tail = temp;
                size--;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " REMOVE CASE ABS(POS) = -1" << endl;
#endif
            }
            else if (abs(pos) < size) // Remove middle node
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
                forShow = temp;
                tempPrev->setPrev(tempNext);
                tempNext->setNext(tempPrev);
                size--;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " REMOVE CASE ABS(POS)MIDDLE " << endl;
#endif
            }
            else if (abs(pos) == size) // Remove head
            {
                Node *temp = head->getNext();
                temp->setPrev(nullptr);
                head->setNext(nullptr);
                forShow = head;
                head = temp;
                size--;
#ifdef DEBUG
                cout << "YOUR POS INPUT " << pos << " (ABS) -> " << abs(pos) << " REMOVE CASE (ABS)POS = SIZE" << endl;
#endif
            }
        }
    }
    else
    {
#ifdef DEBUG
        cout << "YOUR POS INPUT " << pos << " ERROR REMOVE POSITION UNKNOW" << endl;
        removeReal = false;
#endif
    }
#ifdef DEBUG
    if (removeReal == true)
    {
        cout << "Remove : " << forShow->getValue() << ", Remove addr : " << forShow << endl;
    }
#endif
}

void LinkedList::append(Node *newNode)
{
    tail->setNext(newNode);
    newNode->setPrev(tail);
    newNode->setNext(nullptr);
    tail = newNode;
    size++;
#ifdef DEBUG
    cout << "APPEND CASE" << endl;
#endif
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