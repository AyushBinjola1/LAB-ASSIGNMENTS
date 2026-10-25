#include <iostream>
#include <string>
using namespace std;
 
class Vehicle {
protected:
    string brand;
};
 
class Car : public Vehicle {
protected:
    int speed;
};
 
class ElectricCar : public Car {
private:
    int batteryLife;
public:
    void setDetails(string b, int s, int life) {
        brand = b;          // from Vehicle (two levels up)
        speed = s;          // from Car (one level up)
        batteryLife = life;
    }
    void display() const {
        cout << "Brand        : " << brand << endl;
        cout << "Speed        : " << speed << " km/h" << endl;
        cout << "Battery Life : " << batteryLife << " hours" << endl;
    }
};
 
int main() {
    ElectricCar ec;
    ec.setDetails("Tesla", 200, 12);
    cout << "--- Electric Car Details ---" << endl;
    ec.display();
    // ec.speed = 100;  // ERROR: 'speed' is protected
    return 0;
}
