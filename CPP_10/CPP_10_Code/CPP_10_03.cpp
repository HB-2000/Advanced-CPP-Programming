#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(const string& n, int i) : name(n), id(i) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    virtual ~Person() {}
};

class Student : public Person {
private:
    double gpa;
public:
    Student(const string& n, int i, double g) : Person(n, i), gpa(g) {}
    void displayInfo() const override {
        cout << "Student - Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
    }
};

class Professor : public Person {
private:
    string department;
public:
    Professor(const string& n, int i, const string& d) : Person(n, i), department(d) {}
    void displayInfo() const override {
        cout << "Professor - Name: " << name << ", ID: " << id << ", Department: " << department << endl;
    }
};

int main() {
    Person* people[] = { new Student("Hassan", 1001, 3.8), new Professor("Dr. Ahmadi", 2001, "Computer Science") };
    for (int i = 0; i < 2; i++) {
        people[i]->displayInfo();
        delete people[i];
    }
    return 0;
}