#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList()
{
    first = nullptr;
    last = nullptr;
    size = 0;
}

void LinkedList::showfl()
{
    cout << "first :" << first->getValue() << endl;
    cout << "last :" << last->getValue() << endl;
}

void LinkedList::show()
{
    Node *temp = first;
    for (int i = 0; i < size; i++)
    {
        cout << temp->getValue();
        temp = temp->getnextaddr();
        if (i != size - 1)
        {
            cout << " <-> ";
        }
    }
    cout << endl;
}

void LinkedList::printpok()
{
    Node *temp = first;
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " Value : " << temp->getValue() << " Addr : " << temp << " Prev -> " << temp->getprevaddr() << " Next -> " << temp->getnextaddr() << endl;
        temp = first->getnextaddr();
    }
}

int LinkedList::insert(Node *newNode, int pos)
{
    if (size == 0)
    {
        first = newNode;
        last = newNode;
        first->setnextaddr(nullptr);
        first->setprevaddr(nullptr);
        last->setnextaddr(nullptr);
        last->setprevaddr(nullptr);
        size++;
        return 0;
    }

    else if (pos > size or pos < 0)
    {
        cout << "error newNode pos :" << pos << endl;
        return 1;
    }

    else if (size != 0)
    {
        if (pos == 0)
        {
            newNode->setnextaddr(first);
            newNode->setprevaddr(nullptr);
            first->setprevaddr(newNode);
            first = newNode;
            size++;
            return 0;
        }

        else if (pos == size)
        {
            last->setnextaddr(newNode);
            newNode->setprevaddr(last);
            newNode->setnextaddr(nullptr);
            last = newNode;
            size++;
            return 0;
        }
        else if (pos > 0 or pos < size)
        {
            Node *temp1 = first;
            for (int i = 0; i < pos - 1; i++)
            {
                temp1 = temp1->getnextaddr();
            }
            Node *temp2 = temp1->getnextaddr();
            temp1->setnextaddr(newNode);
            newNode->setprevaddr(temp1);
            newNode->setnextaddr(temp2);
            temp2->setprevaddr(newNode);
            size++;
        }
    }
    return 0;
}

int LinkedList::remove(int pos) // update remove(invert)
{
    if (pos < 0) // check invert remove
    {
        int abspos = pos * -1; // absolute of pos
        if (abspos > size)     // check out of range
        {
            cout << "error pos :" << pos << endl;
            return 1;
        }
        else if (abspos == 1) // check pos from last
        {
            Node *temp = last->getprevaddr();
            temp->setnextaddr(nullptr);
            last->setprevaddr(nullptr);
            last = temp;
            size--;
        }
        else if (abspos == size) // check pos at first
        {
            Node *temp = first->getnextaddr();
            first->setnextaddr(nullptr);
            temp->setprevaddr(nullptr);
            first = temp;
            size--;
        }
        else // check pos between first and last
        {
            Node *temp2 = last;
            pos *= -1;
            for (int i = 0; i < pos - 2; i++)
            {
                temp2 = temp2->getprevaddr();
            }
            Node *removenode = temp2->getprevaddr();
            Node *temp1 = temp2->getprevaddr()->getprevaddr();
            temp1->setnextaddr(temp2);
            temp2->setprevaddr(temp1);
            removenode->setnextaddr(nullptr);
            removenode->setprevaddr(nullptr);
            size--;
        }
    }

    else if (pos > size - 1)
    {
        cout << "error remove pos :" << pos << endl;
        return 1;
    }
    else if (pos == 0)
    {
        Node *temp = first->getnextaddr();
        first->setnextaddr(nullptr);
        temp->setprevaddr(nullptr);
        first = temp;
        size--;
        return 0;
    }
    else if (pos == size - 1)
    {
        Node *temp = last->getprevaddr();
        last->setprevaddr(nullptr);
        temp->setnextaddr(nullptr);
        last = temp;
        size--;
        return 0;
    }
    else if (pos > 0 or pos < size)
    {
        Node *temp1 = first;
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp1->getnextaddr();
        }
        Node *temp2 = temp1->getnextaddr()->getnextaddr();
        Node *removenode = temp1->getnextaddr();
        temp1->setnextaddr(temp2);
        temp2->setprevaddr(temp1);
        removenode->setnextaddr(nullptr);
        removenode->setprevaddr(nullptr);
        size--;
        return 0;
    }
    return 0;
}