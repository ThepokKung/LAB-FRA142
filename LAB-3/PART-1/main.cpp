#include <iostream>
#include "Node.h"

using namespace std;

int main(){
    Node n1 = Node();
    Node n2 = Node(2,NULL);
    n1.printValue();
    n2.printValue();

    n1.setValue(20);
    n1.printValue();

    n1.setNext(&n2);
    n1.printValue();
    cout << "================================" << endl;
    cout << n1.getNext() -> getValue() << endl;
    cout << "================================" << endl;
    n1.printAll();
    return 0;
}