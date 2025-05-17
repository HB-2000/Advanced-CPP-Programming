#include <iostream>
#include <string>
using namespace std;

// Base Class with Virtual Functions
class Animal {
public:
    // Virtual function for movement with default implementation
    virtual void move() const {
        cout << "This animal moves in a generic way." << endl;
    }
    // Virtual function for display with default implementation
    virtual void display() const {
        cout << "Animal: Generic animal" << endl;
    }
    // Virtual destructor
    virtual ~Animal() {}
};

// Derived Class: Bird
class Bird : public Animal {
private:
    string species;
    double wingSpan;
public:
    Bird(string s, double ws) : species(s), wingSpan(ws) {}
    void move() const override {
        cout << species << " is flying with wings." << endl;
    }
    void display() const override {
        cout << "Bird: Species = " << species
             << ", Wing Span = " << wingSpan << " meters" << endl;
    }
};

// Derived Class: Fish
class Fish : public Animal {
private:
    string species;
    double swimSpeed;
public:
    Fish(string s, double ss) : species(s), swimSpeed(ss) {}
    void move() const override {
        cout << species << " is swimming in water." << endl;
    }
    void display() const override {
        cout << "Fish: Species = " << species
             << ", Swim Speed = " << swimSpeed << " km/h" << endl;
    }
};

// Derived Class: Mammal
class Mammal : public Animal {
private:
    string species;
    double runSpeed;
public:
    Mammal(string s, double rs) : species(s), runSpeed(rs) {}
    void move() const override {
        cout << species << " is running on land." << endl;
    }
    void display() const override {
        cout << "Mammal: Species = " << species
             << ", Run Speed = " << runSpeed << " km/h" << endl;
    }
};

// Derived Class: Reptile
class Reptile : public Animal {
private:
    string species;
    bool isVenomous;
public:
    Reptile(string s, bool v) : species(s), isVenomous(v) {}
    void move() const override {
        cout << species << " is crawling on the ground." << endl;
    }
    void display() const override {
        cout << "Reptile: Species = " << species
             << ", Venomous = " << (isVenomous ? "Yes" : "No") << endl;
    }
};

int main() {
    // Can instantiate base class since it's not abstract
    Animal genericAnimal;

    // Array of pointers to Animal
    Animal* animals[] = {
        new Bird("Eagle", 2.0),
        new Fish("Salmon", 10.0),
        new Mammal("Cheetah", 120.0),
        new Reptile("Snake", true),
        new Animal() // Adding a generic animal
    };

    cout << "Animals Information and Movement:\n";
    for (int i = 0; i < 5; i++) {
        animals[i]->display();
        animals[i]->move();
        cout << endl;
        delete animals[i]; // Clean up memory
    }

    return 0;
}