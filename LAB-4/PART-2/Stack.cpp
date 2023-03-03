#include "Stack.h"

// #define DEBUG

Stack::Stack() : LinkedList() // Constructor Stack
{
#ifdef DEBUG
    cout << "Call Stack constructor" << endl;
#endif
}

Stack::~Stack() // Destructor Stack
{
#ifdef DEBUG
    cout << "Call Stack destructor" << endl;
#endif
}

void Stack::push(Node *newNode) // Push Stack
{
    append(newNode);
#ifdef DEBUG
    cout << "Call Stack push" << endl;
#endif
}

Node *Stack::pop()
{
#ifdef DEBUG
    cout << "Call Stack pop" << endl;
#endif
    int deleter = getsize() - 1;
    return remove(deleter);
}

Node *Stack::peek()
{
#ifdef DEBUG
    cout << "Call Stack peek" << endl;
#endif
    return getTail();
}