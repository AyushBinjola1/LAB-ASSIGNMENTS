#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area()
    {
        return length * width;
    }

    double perimeter()
    {
        return 2 * (length + width);
    }
};

int main()
{
    double l, w;
    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;

    Rectangle rect(l, w);

    cout << "Area = " << rect.area() << endl;
    cout << "Perimeter = " << rect.perimeter() << endl;

    return 0;
}
