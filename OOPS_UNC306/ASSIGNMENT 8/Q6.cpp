#include <iostream>
using namespace std;
 
class Calculator {
public:
    int add(int a, int b) {
        cout << "  add(int, int) chosen    -> ";
        return a + b;
    }
    double add(double a, double b) {
        cout << "  add(double, double) chosen -> ";
        return a + b;
    }
};
 
// Separate class used only to demonstrate ambiguity
class MixedCalc {
public:
    double add(int a, double b) { return a + b; }
    double add(double a, int b) { return a + b; }
};
 
class Animal {
public:
    virtual void speak() { cout << "  Animal::speak()" << endl; }
    void label() { cout << "  Animal::label()" << endl; }
    virtual ~Animal() = default;
};
 
class Dog : public Animal {
public:
    void speak() override { cout << "  Dog::speak()" << endl; }
    void label() { cout << "  Dog::label()" << endl; }   // redefines (hides) label()
};
 
class BadDog : public Animal {
public:
    //X void speak(int) override;   // does not override: signature differs
};
 
int main() {
    Calculator calc;
    cout << "Overload resolution:" << endl;
    cout << calc.add(2, 3) << endl;               // exact match: int, int
    cout << calc.add(2.5, 3.5) << endl;           // exact match: double, double
    cout << calc.add(2.5f, 1.5f) << endl;         // float -> double (promotion)
    short s1 = 4, s2 = 5;
    cout << calc.add(s1, s2) << endl;             // short -> int (promotion)
    //X calc.add(5, 2.5);             // ambiguous: int->double vs double->int conversions
 
    MixedCalc mc;
    cout << mc.add(1, 2.5) << endl;               // exact for add(int, double)
    //X mc.add(1, 2);                 // ambiguous: each overload needs one conversion
 
    Dog dog;
    Animal* ap = &dog;
    cout << "\nThrough Animal* (points to a Dog):" << endl;
    ap->speak();                                  // dynamic binding -> Dog::speak
    ap->label();                                  // static binding  -> Animal::label
 
    cout << "\nThrough Dog object:" << endl;
    dog.speak();
    dog.label();
    return 0;
}
