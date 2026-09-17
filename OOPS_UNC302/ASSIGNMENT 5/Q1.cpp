#include <iostream>
using namespace std;

class Rectangle {
private:
	double length, width;

public:
	// Default constructor
	Rectangle() {
		length = 0;
		width = 0;
		cout << "[Default Constructor] called -> length=0, width=0\n";
	}

	// Parameterized constructor
	Rectangle(double l, double w) {
		if (l < 0 || w < 0) {
			cout << "[Parameterized Constructor] Invalid dimensions, defaulting to 0\n";
			length = 0;
			width = 0;
		} else {
			length = l;
			width = w;
			cout << "[Parameterized Constructor] called -> length=" << l << ", width=" << w << "\n";
		}
	}

	// Copy constructor
	Rectangle(const Rectangle &other) {
		length = other.length;
		width = other.width;
		cout << "[Copy Constructor] called -> copied length=" << length << ", width=" << width << "\n";
	}

	double area() const { return length * width; }
	double perimeter() const { return 2 * (length + width); }

	void display() const {
		cout << "  Length=" << length << ", Width=" << width
			 << ", Area=" << area() << ", Perimeter=" << perimeter() << "\n";
	}
};

int main() {
	cout << "Creating r1 (default constructor):\n";
	Rectangle r1;
	r1.display();

	cout << "\nCreating r2 (parameterized constructor):\n";
	Rectangle r2(10, 5);
	r2.display();

	cout << "\nCreating r3 (copy constructor from r2):\n";
	Rectangle r3(r2);
	r3.display();

	cout << "\nCreating r4 (parameterized constructor with invalid dimensions):\n";
	Rectangle r4(-3, 5);
	r4.display();

	return 0;
}
