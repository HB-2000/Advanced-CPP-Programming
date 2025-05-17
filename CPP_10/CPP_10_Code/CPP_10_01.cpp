#include<iostream>
using namespace std;

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    virtual double area() const  {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    virtual double area() const  {
        return width * height;
    }
};

int main() {
    Shape *s;
    Circle c(1.0);
    s = &c;
    cout << s->area() << endl;
    Rectangle r(1.0, 2.0);
    s = &r;
    cout << s->area() << endl;

    return 0;
}