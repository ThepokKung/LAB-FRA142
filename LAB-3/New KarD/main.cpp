#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    Node n1 = Node(1, NULL, NULL);
    Node n2 = Node(2, NULL, NULL);
    Node n3 = Node(3, NULL, NULL);
    Node n4 = Node(4, NULL, NULL);
    Node n5 = Node(5, NULL, NULL);
    // cout << n1.getValue() << endl;

    LinkedList l1 = LinkedList();
    l1.insert(&n1, 0);
    l1.insert(&n2, 1);
    l1.insert(&n3, 2);
    // l1.insert(&n4, 2);
    // l1.insert(&n5, 4);
    // l1.show();
    l1.printpok();
    /*
    // cout << &n3 << endl;
    // cout << n1.getprevaddr();
    // cout << n3.getprevaddr();
    // l1.remove(3);
    // l1.show();
    // cout << n2.getprevaddr() << endl;
    // cout << n2.getnextaddr() << endl;
    l1.remove(-1);
    l1.show();
    l1.remove(-2);
    l1.show();
    l1.remove(-3);
    l1.show();
    l1.showfl();
    cout << n1.getprevaddr() << endl;
    cout << n2.getnextaddr() << endl;
    */
    return 0;
}
// size (-pos) checked
// use getprevaddr() checked
