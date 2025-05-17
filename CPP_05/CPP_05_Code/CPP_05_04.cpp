#include <iostream>
using namespace std;

class Person {
private:
    string name;

protected:
    int age;

public:
    int id;
};

class Student : public Person {
private:
    int studentId;

public:
    void display() {
        cout << studentId << endl;
        //cout << name;
        cout << age;
    }
};


int main() {
    return 0;
}
