#include "Person.h"

#include <iostream>
using namespace std;

/* Person */
Person::Person() // Constructor
{
    name = "";
    height = 0;
    age = 0;
}

Person::Person(string n, int h, int a) // Input parameters for constructor
{
    name = n;
    height = h;
    age = a;
}

Person::~Person() // Destructor Person
{
}

void Person::showPersonInfo() // Show Person information
{
    cout << "Person : " << name << " , Height : " << height << " , Age : " << age << endl;
}

/* Student */

Student::Student() : Person() // Constructor Student
{
    id = 0;
    grade = 0;
}

Student::Student(string name, int height, int age, int i, int g) : Person(name, height, age) // Input parameters for Student
{
    id = i;
    grade = g;
}

Student::~Student() // Destructor Student
{
}

void Student::showStudentInfo() // Show Student information
{
    showPersonInfo();
    cout << "ID : " << id << ", Grade : " << grade << endl;
}

/* Teacher */
Teacher::Teacher() : Person() // Constructor teacher
{
    subject = "";
}
Teacher::Teacher(string name, int height, int age, string s) : Person(name, height, age) // Input parametor for Teacher
{
    subject = s;
}

Teacher::~Teacher() // Destructor Teacher
{
}

void Teacher::showTeacherInfo() // Show Teacher information
{
    showPersonInfo();
    cout << "Subject : " << subject << endl;
}

string Teacher::getSubject() // Get the subject of the teacher
{
    return subject;
}

void Teacher::setSubject(string newSubject) // Set the subject of the teacher
{
    subject = newSubject;
}