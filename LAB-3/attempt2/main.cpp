#include "Node.cpp"
#include "LinkedList.cpp"

int main()
{
    Node head(50);
    Node node1(10);
    Node node2(20);
    Node node3(30);
    Node tail(999);

    LinkedList ll(&head, &tail);
    ll.insert(&node1, 1);
    ll.insert(&node2, 2);
    ll.insert(&node3, 3);

    // ll.remove(3);

    ll.printList();
    Node node = head;

    // cout<< head.getValue() << endl;
    // cout<< tail.getValue() << endl;

    // cout << ll.getHead()->getValue() << endl;
    // cout << ll.getTail()->getValue() << endl;
    return 0;
}
