#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    long nationalID;
    int studentId;
public:
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
    void setName(string name) {
        this->name = name;
    }
    void setNationalID(long nationalID) {
        this->nationalID = nationalID;
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

class TeacherAssistant : public Student, public Teacher {
private:
    int assistantId;
public:
    void setAssistantId(int assistantId) {
        this->assistantId = assistantId;
    }
    int getAssistantId() {
        return assistantId;
    }
    void display() {
        cout << "Teacher Assistant Information:" << endl;
        // استفاده از Student::getName و Student::getNationalID برای رفع ابهام
        cout << "Name: " << Student::getName() << endl;
        cout << "National ID: " << Student::getNationalID() << endl;
        cout << "Student ID: " << getStudentId() << endl;
        cout << "Teacher ID: " << getTeacherId() << endl;
        cout << "Assistant ID: " << assistantId << endl;
    }
};

int main() {
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
    cout << endl;

    TeacherAssistant ta;
    ta.Student::setName("Maryam"); // استفاده از Student::setName برای رفع ابهام
    ta.Student::setNationalID(9012); // استفاده از Student::setNationalID برای رفع ابهام
    ta.setStudentId(4321);
    ta.setTeacherId(789);
    ta.setAssistantId(101);
    ta.display();

    return 0;
}