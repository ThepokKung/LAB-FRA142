#include <iostream>
#include "Node.h"
#include "Queue.h"
using namespace std;

int main(){
    Queue Q ;
    Node
    n1 = Node(10,nullptr,nullptr),
    n2 = Node(20,nullptr,nullptr),
    n3 = Node(30,nullptr,nullptr),
    n4 = Node(40,nullptr,nullptr),
    n5 = Node(50,nullptr,nullptr),
    n6 = Node(60,nullptr,nullptr);

    Q.enqueue(&n1);
    Q.enqueue(&n2);
    Q.enqueue(&n3);
    Q.print();
    Q.dequeue();
    Q.print();
    cout << "peek Queue : " << Q.peek() << endl;
    return 0 ;
}