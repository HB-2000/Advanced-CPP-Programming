#include <iostream>
#include <ostream>
#include<string>
using namespace std;
class Person {
private:
    string name;
    long natinalID;
    public:
    void setName(string name) {
        this->name = name;
    }
    void setNatinalID(long natinalID) {
        this->natinalID = natinalID;
    }
    string getName() {
        return name;
    }
    long getNatinalID() {
        return natinalID;
    }
    void display() {
        cout << name << endl;
        cout << natinalID << endl;
    }
};

class Student :public Person{
    private:
    int studentId;
    public:
    void setStudentId(int studentId) {
        this->studentId = studentId;
    }
    int getStudentId() {
        return studentId;
    }
    void display() {
        cout << getName() << endl;
        cout << getNatinalID() << endl;
        cout << studentId << endl;
    }
};

int main() {
    Person p;
    p.setName("Hossein");
    p.setNatinalID(3040);
    p.display();

    Student s;
    s.setName("Zahra");
    s.setNatinalID(5678);
    s.setStudentId(9814);
    s.display();
}