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
    virtual void display() { // virtual برای پشتیبانی از چندریختی
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "National ID: " << nationalID << endl;
        cout << "Student ID: " << studentId << endl;
    }
};

class GraduateStudent : public Student {
private:
    string thesisTitle;
public:
    // سازنده
    GraduateStudent(string name, long nationalID, int studentId, string thesisTitle)
        : Student(name, nationalID, studentId) {
        this->thesisTitle = thesisTitle;
    }
    void setThesisTitle(string thesisTitle) {
        this->thesisTitle = thesisTitle;
    }
    string getThesisTitle() {
        return thesisTitle;
    }
    void display() override {
        cout << "Graduate Student Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "National ID: " << getNationalID() << endl;
        cout << "Student ID: " << getStudentId() << endl;
        cout << "Thesis Title: " << thesisTitle << endl;
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

    GraduateStudent gs("Sara", 7890, 1234, "Machine Learning Algorithms");
    gs.display();
    cout << endl;


    return 0;
}