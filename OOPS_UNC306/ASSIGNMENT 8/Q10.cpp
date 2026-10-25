#include <iostream>
#include <iomanip>
using namespace std;
 
const double PI = 3.14159265358979323846;
 
class Shape {
public:
    virtual double area() = 0;                 // pure virtual function
    virtual ~Shape() = default;
};
 
class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() override { return PI * radius * radius; }
    double circumference() const { return 2 * PI * radius; }   // Circle-only method
};
 
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override { return width * height; }
};
 
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() override { return 0.5 * base * height; }
};
 
class Trapezoid : public Shape {
    double base1, base2, height;
public:
    Trapezoid(double a, double b, double h) : base1(a), base2(b), height(h) {}
    double area() override { return 0.5 * (base1 + base2) * height; }
};
 
class Incomplete : public Shape {};            // area() not implemented: still abstract
 
int main() {
    Circle c(7);
    Rectangle r(5, 4);
    Triangle t(6, 3);
    Trapezoid z(4, 6, 5);
 
    Shape* shapes[] = { &c, &r, &t, &z };
    const char* names[] = { "Circle", "Rectangle", "Triangle", "Trapezoid" };
 
    cout << fixed << setprecision(2);
    for (int i = 0; i < 4; i++) {
        cout << setw(10) << left << names[i] << " area = " << shapes[i]->area() << endl;
    }
 
    //X Shape s;                       // Shape is abstract
    //X Incomplete inc;                // Incomplete did not implement area()
    //X shapes[0]->circumference();    // Shape has no member circumference()
    cout << "Circle circumference (through Circle object) = " << c.circumference() << endl;
    return 0;
}
