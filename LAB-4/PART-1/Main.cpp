#include "Person.h"
#include <iostream>

using namespace std;

int main()
{
    /* EX1 */
    Person pok = Person("Pok", 172, 18);
    Student tin = Student("Tin", 180, 20, 6505, 10);
    pok.showPersonInfo();
    tin.showStudentInfo();
    /* EX2 */
    Teacher Blink = Teacher("Blinkimon", 175, 30, "Programming");
    Blink.setSubject("Math");
    Blink.showTeacherInfo();

    /* Test */
    // Student Test = Student();
    // Teacher Test2 = Teacher();
    // Test.showStudentInfo();
    // Test2.showTeacherInfo();
    return 0;
}