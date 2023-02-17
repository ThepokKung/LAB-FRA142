#include <iostream>
using namespace std;

class Person
{
private:
    int id;
    int age = 10;

public:
    void setId(int newId) { id = newId; }
    int getId() const { return id; } // returns the id of the person
    int getAge() const { return age; } // returns the age of the person
};