#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

LinkedList::LinkedList(Node *newHead, Node *newTail)
{
    head = newHead;
    tail = newTail;
    head->setNext(tail);
    size = 2;
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::setHead(Node *newHead)
{
    head = newHead;
}

Node* LinkedList::getTail()
{
    return tail;
}

void LinkedList::setTail(Node *newTail)
{
    tail = newTail;
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::setSize(int newSize)
{
    size = newSize;
}

void LinkedList::insert(Node *newNode, int pos)
{
    Node *temp;
    Node *run = head;

    if (size - 1 < pos || pos < 0)
    {
        cout << "error out of linked" << endl;
    }
    else
    {
        if (pos == 0) // add head
        {
            newNode->setNext(head);
            head = newNode;
            size++;
        }

        else if (pos == size) // add tail
        {
            while (run->getNext() != NULL)
            {
                run = run->getNext();
            }
            
            run->setNext(newNode);
            tail = newNode;
            size++;
        }

        else // add pos
        {
            for (int i = 1; i < pos; i++)
            {
                run = run->getNext();
            }
            temp = run;
            temp = temp->getNext();
            run->setNext(newNode);
            newNode->setNext(temp);
            size++;
        }
    }
}

Node* LinkedList::remove(int pos)
{
    Node *temp;
    Node *run = head;
    if (size - 1 < pos || pos < 0)
    {
        cout << "error out of linked" << endl;
    }

    else
    {
        if (pos == 0) // remove head
        {
            temp = head->getNext();
            head->setNext(NULL);
            head = temp;
            size--;
        }

        else if (pos + 1 == size) // remove tail
        {
            while (run->getNext() != NULL)
            {
                temp = run;
                run = run->getNext();
            }
            temp->setNext(NULL);
            tail = temp;
            size--;
        }
        else // remove pos
        {
            for (int i = 1; i < pos; i++)
            {
                run = run->getNext();
            }
            temp = run;
            run = run->getNext()->getNext();
            temp->getNext()->setNext(NULL);
            temp->setNext(run);
            size--;
        }
    }
}

void LinkedList::printList()
{
    Node *run = head;
    while (run != NULL)
    {
        cout << " " << run->getValue();
        run = run->getNext();
    }
    cout << endl;

}