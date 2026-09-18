#include <iostream>
using namespace std;

class Rectangle {
private:
	double length, width;

public:
	Rectangle() {
		length = 0;
		width = 0;
		cout << "[Default Constructor]   this=" << this << "  (l=0, w=0)\n";
	}

	Rectangle(double l, double w) {
		length = l;
		width = w;
		cout << "[Param Constructor]     this=" << this << "  (l=" << l << ", w=" << w << ")\n";
	}

	Rectangle(const Rectangle &other) {
		length = other.length;
		width = other.width;
		cout << "[Copy Constructor]      this=" << this << "  (copied from " << &other << ")\n";
	}

	~Rectangle() {
		cout << "[Destructor]             this=" << this << "  (l=" << length << ", w=" << width << ")\n";
	}

	void display() const {
		cout << "  Rectangle at " << this << " -> length=" << length << ", width=" << width << "\n";
	}
};

int main() {
	cout << "Entering main()\n";
	Rectangle mainObj(8, 4);        // object 1, created in main
	mainObj.display();

	Rectangle copiedObj(mainObj);   // object 2, copy of mainObj
	copiedObj.display();

	{
		cout << "\nEntering nested block\n";
		Rectangle nestedObj(2, 2);   // object 3, local to nested block
		nestedObj.display();
		cout << "Leaving nested block\n";
	} // nestedObj destroyed here

	cout << "\nBack in main(), before main() ends\n";
	cout << "Leaving main()\n";
	return 0;
} // mainObj and copiedObj destroyed here, in reverse order of creation
