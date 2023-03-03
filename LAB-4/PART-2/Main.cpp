#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

#define EX3
#define EX4

int main()
{
    Node n1 = Node(1, nullptr, nullptr);
    Node n2 = Node(2, nullptr, nullptr);
    Node n3 = Node(3, nullptr, nullptr);
    Node n4 = Node(4, nullptr, nullptr);
    Node n5 = Node(5, nullptr, nullptr);

/* EX 3 */
#ifdef EX3
    Stack stack = Stack();
    // stack.printAll();
    stack.push(&n1);
    stack.push(&n2);
    stack.push(&n3);
    stack.push(&n4);
    cout << "It's pop : " << stack.pop() << endl;
    stack.peek();
    stack.print();
    cout << "****************************************************************" << endl;
#endif

/* EX 4 */
#ifdef EX4
    Queue queue = Queue();
    queue.enqueue(&n1);
    queue.enqueue(&n2);
    queue.enqueue(&n3);
    queue.enqueue(&n4);
    queue.enqueue(&n5);
    cout << "It's dequeue : " << queue.dequeue() << endl;
    queue.peek();
    queue.print();
#endif
    return 0;
}