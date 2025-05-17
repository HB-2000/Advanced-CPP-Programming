#include <iostream>
using namespace std;

class Animal { //کلاس والد
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal { // کلاس فرزند
public:
    void bark() {
        cout << "Woof! Woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // فراخوانی متد از کلاس والد
    myDog.bark(); // فراخوانی متد از کلاس فرزند
    return 0;
}