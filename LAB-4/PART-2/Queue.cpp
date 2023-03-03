#include "Queue.h"

// #define DEBUG

Queue::Queue() : LinkedList()
{
#ifdef DEBUG
    cout << "CALL QUEUE CONSTRUTORS " << endl;
#endif
}

Queue::~Queue()
{
#ifdef DEBUG
    cout << "CALL QUEUE DECONSTRUTORS " << endl;
#endif
}

void Queue::enqueue(Node *newNode)
{
    append(newNode);
#ifdef DEBUG
    cout << "CALL ENQUEUE " << endl;
#endif
}

Node *Queue::dequeue()
{
#ifdef DEBUG
    cout << "CALL DEQUEUE " << endl;
#endif
    return remove(0);
}

Node *Queue::peek()
{
#ifdef DEBUG
    cout << "CALL PEEK " << endl;
#endif
    return getHead();
}