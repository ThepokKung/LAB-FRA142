#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;

int main(){
    Stack stack ;
    Node
    n1 = Node(10,nullptr,nullptr),
    n2 = Node(20,nullptr,nullptr),
    n3 = Node(30,nullptr,nullptr),
    n4 = Node(40,nullptr,nullptr),
    n5 = Node(50,nullptr,nullptr),
    n6 = Node(60,nullptr,nullptr);

    stack.push(&n1);
    stack.push(&n2);
    stack.push(&n3);
    stack.print();
    cout << stack.pop() << endl;
    stack.print();
    cout << "The peek stack : " << stack.peek() << endl ;
    return 0 ;
}