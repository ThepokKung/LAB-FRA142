#include "Person.h"
#include <iostream>

using namespace std;

int main()
{
    /* EX1 */
    Person pok = Person("Pok", 172, 18);
    Student tin = Student("tin", 170, 18, 6519, 10);
    pok.showPersonInfo();
    tin.showStudentInfo();

    /* EX2 */
    Teacher Blink = Teacher("Blink", 175, 30, "Programing");
    Blink.showTeacherInfo();
    return 0;
}