#include <iostream>
#include <string>
using namespace std;
 
class Vehicle {                                  // interface 1: fuel information
public:
    virtual string fuelType() = 0;
    virtual ~Vehicle() = default;
};
 
class Printable {                                // interface 2: printable details
public:
    virtual void printDetails() = 0;
    virtual ~Printable() = default;
};
 
class Car : public Vehicle, public Printable {
public:
    string fuelType() override { return "Petrol"; }
    void printDetails() override {
        cout << "Car   : 4 wheels, fuel = " << fuelType() << endl;
    }
};
 
class Bike : public Vehicle, public Printable {
public:
    string fuelType() override { return "Petrol (mixed oil)"; }
    void printDetails() override {
        cout << "Bike  : 2 wheels, fuel = " << fuelType() << endl;
    }
};
 
class Truck : public Vehicle, public Printable {
public:
    string fuelType() override { return "Diesel"; }
    void printDetails() override {
        cout << "Truck : 6 wheels, fuel = " << fuelType() << endl;
    }
};
 
// Implements only ONE of the two interfaces -> still abstract
class Moped : public Vehicle, public Printable {
public:
    string fuelType() override { return "Petrol"; }
    // printDetails() is not implemented
};
 
int main() {
    Car car;
    Bike bike;
    Truck truck;
 
    Vehicle* vehicles[] = { &car, &bike, &truck };
    Printable* printables[] = { &car, &bike, &truck };
 
    cout << "Through Vehicle* pointers:" << endl;
    for (Vehicle* v : vehicles) {
        cout << "  Fuel type: " << v->fuelType() << endl;
    }
 
    cout << "\nThrough Printable* pointers:" << endl;
    for (Printable* p : printables) {
        p->printDetails();
    }
 
    //X Moped moped;        // abstract: printDetails() is still pure virtual
    return 0;
}
