#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    Node n1 = Node(1, NULL, NULL);
    Node n2 = Node(2, NULL, NULL);
    Node n3 = Node(3, NULL, NULL);
    Node n4 = Node(4, NULL, NULL);
    Node n5 = Node(5, NULL, NULL);

    LinkedList list = LinkedList();
    list.insert(&n1, 0);
    list.insert(&n2, 1);
    list.insert(&n3, 2);
    list.insert(&n4, 3);
    list.insert(&n5, 4);
    // list.append(&n6);
    list.print();
    // cout << "********************************" << endl;
    // list.printFormtail();
    // cout << n3-> << endl;

    cout << "********************************" << endl;
    // list.printHeadandTail();
    /*
    list.remove(0);
    list.print();
    cout << "********************************" << endl;
    list.remove(0);
    list.print();
    cout << "********************************" << endl;
    list.remove(0);
    list.print();
    cout << "********************************" << endl;
        */
    return 0;
}