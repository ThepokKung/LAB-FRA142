#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    Node *n1 = new Node(1, nullptr, nullptr);
    Node *n2 = new Node(2, nullptr, nullptr);
    Node *n3 = new Node(3, nullptr, nullptr);

    LinkedList list = LinkedList();
    list.insert(n1, 0);
    list.insert(n2, 1);
    list.insert(n3, 2);

    list.print();
    cout << "Re" << endl;
    list.printRe();
}