#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    long nationalID;
public:
    // سازنده
    Person(string name, long nationalID) {
        this->name = name;
        this->nationalID = nationalID;
    }
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

class Student {
private:
    string name;
    long nationalID;
    int studentId;
public:
    // سازنده
    Student(string name, long nationalID, int studentId) {
        this->name = name;
        this->nationalID = nationalID;
        this->studentId = studentId;
    }
    void setName(string name) {
        this->name = name;
    }
    void setNationalID(long nationalID) {
        this->nationalID = nationalID;
    }
    void setStudentId(int studentId) {
        this->studentId = studentId;
    }
    string getName() {
        return name;
    }
    long getNationalID() {
        return nationalID;
    }
    int getStudentId() {
        return studentId;
    }
    void display() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "National ID: " << nationalID << endl;
        cout << "Student ID: " << studentId << endl;
    }
};

class Teacher {
private:
    string name;
    long nationalID;
    int teacherId;
public:
    // سازنده
    Teacher(string name, long nationalID, int teacherId) {
        this->name = name;
        this->nationalID = nationalID;
        this->teacherId = teacherId;
    }
    void setName(string name) {
        this->name = name;
    }
    void setNationalID(long nationalID) {
        this->nationalID = nationalID;
        this->teacherId = teacherId;
    }
    void setTeacherId(int teacherId) {
        this->teacherId = teacherId;
    }
    string getName() {
        return name;
    }
    long getNationalID() {
        return nationalID;
    }
    int getTeacherId() {
        return teacherId;
    }
    void display() {
        cout << "Teacher Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "National ID: " << nationalID << endl;
        cout << "Teacher ID: " << teacherId << endl;
    }
};

int main() {
    // استفاده از سازنده‌ها برای ایجاد اشیا
    Person p("Hossein", 3040);
    p.display();
    cout << endl;

    Student s("Zahra", 5678, 9814);
    s.display();
    cout << endl;

    Teacher t("Ali", 1234, 567);
    t.display();

    return 0;
}