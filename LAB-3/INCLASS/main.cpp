#include <iostream>
#include "Person.cpp"

using namespace std;

int main(){
    Person p1;
    Person oei;
    
    p1.setId(123455);
    cout << p1.getId() << endl;
    // p1.setId(123);
    // cout << p1.getId() << endl;

    cout << oei.getAge() << endl;
    return 0;
}