#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    /* data */
public:
    string name;
    int height;
    int age;
    Person();
    Person(string n, int h, int a);
    ~Person();
    void showPersonInfo();
};

class Student : public Person
{
private:
    /* data */
public:
    int id;
    int grade;
    Student();
    Student(string name, int height, int age, int i, int g);
    ~Student();
    void showStudentInfo();
};

class Teacher : public Person
{
private:
    string subject;

public:
    Teacher();
    Teacher(string name, int height, int age, string s);
    ~Teacher();
    string getSubject();
    void setSubject(string newSubject);
    void showTeacherInfo(); // Show teacher info
};

#endif
