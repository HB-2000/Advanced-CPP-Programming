#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog  {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
    void bark() {
        cout << "Woof! Woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();
    myDog.bark();
    return 0;
}