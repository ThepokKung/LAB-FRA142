#include "LinkedList.h"

int main(){
    Node *A = new Node(1, NULL);
    Node *B = new Node(2, NULL);
    Node *C = new Node(3, NULL);
    Node *D = new Node(4, NULL);

    // A->setNext(B);
    // B->setNext(C);
    // C->setNext(D);
    // D->setValue(10);

    // Node *temp = A;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << temp->getValue() << endl;
    //     temp = temp->getNext();
    // }
    
    LinkedList list = LinkedList();
    list.insert(A,0);
    list.insert(B,1);
    list.insert(C,2);
    list.insert(D,3);

    Node *X = list.remove(2);
    
    cout << "Remove value is " << X->getValue() << endl;

    list.print();

    
}