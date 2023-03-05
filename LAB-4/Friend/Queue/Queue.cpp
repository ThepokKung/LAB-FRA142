#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue():LinkedList()
{}

Queue::~Queue()
{}

void Queue::enqueue(Node *newNode)
{
    insert(newNode,getsize());
}

Node *Queue::dequeue()
{
    Node *temp = gethead();
    remove(0);
    return temp;
}

int Queue::peek()
{
    Node *temp = gethead();
    return temp->getvalue() ;
}

void Queue::de2en()
{
    Node *temp = dequeue();
    enqueue(temp);
}