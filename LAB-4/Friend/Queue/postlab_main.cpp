#include <iostream>
#include "Node.h"
#include "Queue.h"
using namespace std;

int main(){
    Queue rowEVEN , rowODD ;
    int array[] = {5,6,8,9,2,7,1} , arrsize = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < arrsize ; i++){
        Node *temp = new Node;
        temp->setvalue(array[i]);
        if(array[i] % 2 == 0){
            rowEVEN.enqueue(temp);
        } else if (array[i] % 2 == 1){
            rowODD.enqueue(temp);
        }

        if (rowEVEN.getsize() > 0 && rowODD.getsize() > 0){
            if(rowEVEN.peek() > rowODD.peek() && rowEVEN.getsize() > 1){
                rowEVEN.de2en();
            } else if(rowEVEN.peek() < rowODD.peek() && rowODD.getsize() > 1){
                rowODD.de2en();
            }
        }
    cout << "ROW EVEN : " << endl;
    rowEVEN.print();
    cout << "ROW EVEN : " << endl;
    rowODD.print();
    }
    
    return 0 ;
}
