#include <iostream>
#include <cmath>
using namespace std;

// Abstract Class with Pure Virtual Function
class Shape {
public:
    // Pure virtual function for area
    virtual double area() const = 0;
    // Pure virtual function for perimeter
    virtual double perimeter() const = 0;
    // Virtual function for display
    virtual void display() const = 0;
    // Virtual destructor
    virtual ~Shape() {}
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * PI * radius;
    }
    void display() const override {
        cout << "Circle: Radius = " << radius
             << ", Area = " << area()
             << ", Perimeter = " << perimeter() << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void display() const override {
        cout << "Rectangle: Width = " << width
             << ", Height = " << height
             << ", Area = " << area()
             << ", Perimeter = " << perimeter() << endl;
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
private:
    double side1, side2, side3; // Three sides of the triangle
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    double area() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double perimeter() const override {
        return side1 + side2 + side3;
    }
    void display() const override {
        cout << "Triangle: Sides = " << side1 << ", " << side2 << ", " << side3
             << ", Area = " << area()
             << ", Perimeter = " << perimeter() << endl;
    }
};

// Derived Class: Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
    double perimeter() const override {
        return 4 * side;
    }
    void display() const override {
        cout << "Square: Side = " << side
             << ", Area = " << area()
             << ", Perimeter = " << perimeter() << endl;
    }
};

int main() {
    // Cannot instantiate abstract class
    // Shape shape; // This will cause a compilation error

    // Array of pointers to Shape
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4, 6),
        new Triangle(3, 4, 5),
        new Square(4)
    };

    cout << "Shapes Information:\n";
    for (int i = 0; i < 4; i++) {
        shapes[i]->display();
        delete shapes[i]; // Clean up memory
    }

    return 0;
}