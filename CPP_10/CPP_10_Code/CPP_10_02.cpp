#include<iostream>
using namespace std;
class Employee {
protected:
    string name;
public:
    Employee(const string& n) : name(n) {}
    virtual double calculateSalary() const {
        return 0.0;
    }
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    Manager(const string& n) : Employee(n) {}
    double calculateSalary() const override {
        return 5000.0;
    }
};

class Developer : public Employee {
public:
    Developer(const string& n) : Employee(n) {}
    double calculateSalary() const override {
        return 4000.0;
    }
};

int main() {
    Employee* employees[] = { new Manager("Ali"), new Developer("Sara") };
    for (int i = 0; i < 2; i++) {
        cout << employees[i]->calculateSalary() << endl;
        delete employees[i];
    }
    return 0;
}