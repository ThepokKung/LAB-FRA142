#include <iostream>
#include "LinkedList.h"

using namespace std;

bool DEBUGNODE = false; // debug

int main()
{
    Node n1 = Node(1, nullptr, nullptr);
    Node n2 = Node(2, nullptr, nullptr);
    Node n3 = Node(3, nullptr, nullptr);
    Node n4 = Node(4, nullptr, nullptr);
    Node n5 = Node(5, nullptr, nullptr);

    LinkedList list = LinkedList();
    list.insert(&n1, 0);
    list.insert(&n2, 1);
    list.insert(&n3, 2);
    list.insert(&n4, 0);
    list.insert(&n5, 2);
    list.print();

    list.remove(0);
    list.remove(3);
    list.print();

    list.printHeadandTail();
    
    if (DEBUGNODE == true)
    {
        cout << "********************************" << endl;
        cout << " Value " << n1.getValue() << ", Nowaddr -> " << &n1 << ", Prev -> " << n1.getPrev() << ", Next -> " << n1.getNext() << endl;
        cout << " value " << n2.getValue() << ", Nowaddr -> " << &n2 << ", Prev -> " << n2.getPrev() << ", Next -> " << n2.getNext() << endl;
        cout << " value " << n3.getValue() << ", Nowaddr -> " << &n3 << ", Prev -> " << n3.getPrev() << ", Next -> " << n3.getNext() << endl;
        cout << " value " << n4.getValue() << ", Nowaddr -> " << &n4 << ", Prev -> " << n4.getPrev() << ", Next -> " << n4.getNext() << endl;
        cout << " value " << n5.getValue() << ", Nowaddr -> " << &n5 << ", Prev -> " << n5.getPrev() << ", Next -> " << n5.getNext() << endl;
        cout << "********************************" << endl;
    }

    return 0;
}