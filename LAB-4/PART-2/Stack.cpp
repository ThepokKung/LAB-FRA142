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
    return remove(getsize() - 1);
#ifdef DEBUG
    cout << "Call Stack pop" << endl;
#endif
}

Node *Stack::peek()
{
#ifdef DEBUG
    cout << "Call Stack peek" << endl;
#endif
    return getTail();
}