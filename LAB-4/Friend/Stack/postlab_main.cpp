#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;

int main()
{
    Stack stack;
    int array[] = {1, 2, 3, 0, 4, 5}, arrsize = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < arrsize; i++)
    {
        Node *temp = new Node;
        temp->setvalue(array[i]);
        if (array[i] == 0)
        {
            Node *temppop = new Node;
            temppop = stack.pop();
            stack.push(temp);
            stack.push(temppop);
        }
        else
        {
            stack.push(temp);
        }
    }
    stack.print();
}