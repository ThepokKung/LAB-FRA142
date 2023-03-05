#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

// #define NODETEMP
// #define EX3
// #define EX4
// #define POSTLAB_1
#define POSTLAB_2

int main()
{
#ifdef NODETEMP
    Node n1 = Node(1, nullptr, nullptr);
    Node n2 = Node(2, nullptr, nullptr);
    Node n3 = Node(3, nullptr, nullptr);
    Node n4 = Node(4, nullptr, nullptr);
    Node n5 = Node(5, nullptr, nullptr);
#endif

/* EX 3 */
#ifdef EX3
    Stack stack = Stack();
    // stack.printAll();
    Node *temp = new Node;
    stack.push(&n1);
    stack.push(&n2);
    temp = stack.pop();
    // cout << "It's pop : " << stack.pop() << endl;
    stack.push(&n3);
    stack.push(&n4);
    cout << "It's pop : " << stack.pop() << endl;
    stack.peek();
    cout << "POP : " << temp->getValue() << endl;
    stack.print();
    cout << "****************************************************************" << endl;
#endif

/* EX 4 */
#ifdef EX4
    Queue queue = Queue();
    queue.enqueue(&n1);
    queue.enqueue(&n2);
    queue.enqueue(&n3);
    cout << "It's dequeue : " << queue.dequeue() << endl;
    queue.enqueue(&n4);
    queue.enqueue(&n5);

    cout << "It's dequeue : " << queue.dequeue() << endl;
    cout << "It's dequeue : " << queue.dequeue() << endl;
    // cout << "It's dequeue : " << queue.dequeue() << endl;
    queue.enqueue(&n1);
    queue.enqueue(&n2);
    queue.enqueue(&n3);
    queue.peek();
    queue.print();
#endif

#ifdef POSTLAB_1
    /*
        Node card1 = Node(1, nullptr, nullptr);
        Node card2 = Node(2, nullptr, nullptr);
        Node card3 = Node(3, nullptr, nullptr);
        Node card4 = Node(4, nullptr, nullptr);
        Node card5 = Node(5, nullptr, nullptr);
        Node card6 = Node(0, nullptr, nullptr);

        Stack desk1 = Stack();
        desk1.push(&card5);
        desk1.push(&card4);
        desk1.push(&card6);
        desk1.push(&card3);
        desk1.push(&card2);
        desk1.push(&card1);

        desk1.print();
        // cout << "Size : " << desk1.getsize() << endl;

        */

    /* [1,2,3,0,4,5] */
    // Stack desk2 = Stack();
    /*
    int count = desk1.getsize();
    cout << "Desk1 Size : " << count << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Round : " << i << ", Size : " << desk1.getsize() << ", Start" << endl;
        desk1.print();
        Node *pop = desk1.pop();
        pop->printAll();
        if (pop->getValue() == 0)
        {
            cout << "It's Zero!" << endl;
        }
        else if (pop->getValue() != 0)
        {
            desk2.push(pop);
        }
        cout << "Value : " << pop->getValue() << endl;
        cout << "Count : " << i << endl;
        cout << "END " << endl;
    }

    desk2.print();
    cout << "Size : " << desk2.getsize() << endl;
    */
    Stack newDesk = Stack();
    int card[] = {1, 2, 3, 0, 4, 5};
    int deskSize = sizeof(card) / sizeof(int);
    for (int i = 0; i < deskSize; i++)
    {
        cout << "Card : " << i << " -> " << card[i] << endl;
        Node *temp = new Node;
        temp->setValue(card[i]);
        if (card[i] == 0)
        {
            Node *temp2 = new Node;
            temp2 = newDesk.pop();
            newDesk.push(temp);
            newDesk.push(temp2);
        }
        else if (card[i] != 0)
        {
            newDesk.push(temp);
        }
        else
        {
            cout << "Error: " << endl;
            return 0;
        }
    }
    newDesk.print();
#endif

#ifdef POSTLAB_2
    Queue row2 = Queue(); // คู่่
    Queue row3 = Queue(); // คี่
    int row1[] = {5, 6, 8, 9, 2, 7, 1};
    int sizeRow1 = sizeof(row1) / sizeof(int);
    for (int i = 0; i < sizeRow1; i++)
    {
        Node *temp = new Node;
        temp->setValue(row1[i]);
        if (row1[i] % 2 == 0) // คี่
        {
            row2.enqueue(temp);
        }
        else if (row1[i] % 2 != 0)
        {
            row3.enqueue(temp);
        }
        if (row2.getsize() > 0 && row3.getsize() > 0)
        {
            if (row2.peek()->getValue() > row3.peek()->getValue() && row2.getsize() > 1)
            {
                Node *temp = new Node;
                int tempInt = row2.dequeue()->getValue();
                temp->setValue(tempInt);
                row2.enqueue(temp);
            }
            else if (row2.peek()->getValue() < row3.peek()->getValue() && row3.getsize() > 1)
            {
                Node *temp = new Node;
                int tempInt = row3.dequeue()->getValue();
                temp->setValue(tempInt);
                row3.enqueue(temp);
            }
        }
    }
    cout << "Row 2 -> " << endl;
    row2.print();
    cout << "Row 3 -> " << endl;
    row3.print();
#endif
    return 0;
}