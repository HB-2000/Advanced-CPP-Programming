#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    long nationalID;
public:
    void setName(string name) {
        this->name = name;
    }
    void setNationalID(long nationalID) {
        this->nationalID = nationalID;
    }
    string getName() {
        return name;
    }
    long getNationalID() {
        return nationalID;
    }
     void display() {
        cout << "Name: " << name << endl;
        cout << "National ID: " << nationalID << endl;
    }
};

class Student : public Person {
private:
    int studentId;
public:
    void setStudentId(int studentId) {
        this->studentId = studentId;
    }
    int getStudentId() {
        return studentId;
    }
    void display()  {
        cout << "Student Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "National ID: " << getNationalID() << endl;
        cout << "Student ID: " << studentId << endl;
    }
};

class Teacher : public Person {
private:
    int teacherId;
public:
    void setTeacherId(int teacherId) {
        this->teacherId = teacherId;
    }
    int getTeacherId() {
        return teacherId;
    }
    void display()  {
        cout << "Teacher Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "National ID: " << getNationalID() << endl;
        cout << "Teacher ID: " << teacherId << endl;
    }
};

int main() {
    Person p;
    p.setName("Hossein");
    p.setNationalID(3040);
    p.display();
    cout << endl;

    Student s;
    s.setName("Zahra");
    s.setNationalID(5678);
    s.setStudentId(9814);
    s.display();
    cout << endl;

    Teacher t;
    t.setName("Ali");
    t.setNationalID(1234);
    t.setTeacherId(567);
    t.display();

    return 0;
}