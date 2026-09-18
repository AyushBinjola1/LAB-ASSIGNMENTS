#include <iostream>
using namespace std;

class Item {
private:
    int number;
    static int count;   // shared by all objects

public:
    void getdata(int a) {
        number = a;
        count++;
    }

    void getcount() {
        cout << "Shared count: " << count << endl;
    }

    void display() {
        cout << "Item value: " << number << endl;
    }
};

int Item::count = 0;   // static member defined/initialized outside the class

int main() {
    Item i1, i2, i3, i4;

    // called in a non-sequential object order: i3, i1, i4, i2
    i3.getdata(30);
    i3.display(); i3.getcount();

    i1.getdata(10);
    i1.display(); i1.getcount();

    i4.getdata(40);
    i4.display(); i4.getcount();

    i2.getdata(20);
    i2.display(); i2.getcount();

    cout << "\nCalling getcount() through different objects:\n";
    i1.getcount();
    i2.getcount();
    i3.getcount();
    i4.getcount();

    return 0;
}
