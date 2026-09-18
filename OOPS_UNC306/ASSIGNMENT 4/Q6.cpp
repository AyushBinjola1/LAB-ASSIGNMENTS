#include <iostream>
using namespace std;

class Item {
private:
    int number;
    static int count;
    static long long totalValue;

public:
    void getdata(int a) {
        number = a;
        count++;
        totalValue += a;
    }

    static void getcount() {
        cout << "Registered items: " << count << endl;
    }

    static double getAverage() {
        if (count == 0) {
            cout << "No items registered yet - average undefined!\n";
            return 0.0;
        }
        return (double)totalValue / count;
    }
};

int Item::count = 0;              // static data members defined outside the class
long long Item::totalValue = 0;

int main() {
    Item i1, i2, i3, i4, i5;

    i1.getdata(100);
    i2.getdata(250);
    i3.getdata(0);     // includes a zero value
    i4.getdata(75);
    i5.getdata(325);

    Item::getcount();                                   // called without any object
    cout << "Average value: " << Item::getAverage() << endl;

    return 0;
}
