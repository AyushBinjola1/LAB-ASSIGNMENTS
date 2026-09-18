#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
	double real, imag;

public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	Complex operator+(const Complex &rhs) const {
		return Complex(real + rhs.real, imag + rhs.imag);
	}

	Complex operator-(const Complex &rhs) const {
		return Complex(real - rhs.real, imag - rhs.imag);
	}

	Complex operator*(const Complex &rhs) const {
		return Complex(real * rhs.real - imag * rhs.imag,
					   real * rhs.imag + imag * rhs.real);
	}

	Complex operator/(const Complex &rhs) const {
		double denom = rhs.real * rhs.real + rhs.imag * rhs.imag;
		if (denom == 0) {
			cout << "  Error: division by zero Complex number! Returning (0,0).\n";
			return Complex(0, 0);
		}
		double r = (real * rhs.real + imag * rhs.imag) / denom;
		double i = (imag * rhs.real - real * rhs.imag) / denom;
		return Complex(r, i);
	}

	bool operator==(const Complex &rhs) const {
		return (real == rhs.real) && (imag == rhs.imag);
	}

	double magnitude() const {
		return sqrt(real * real + imag * imag);
	}
	// Note: a parameterless unary operator%() cannot be used for magnitude
	// because % is fixed by the C++ grammar as a BINARY operator; overloading
	// cannot change its arity (number of operands). A unary function-style
	// magnitude() must be used instead.

	void display() const {
		cout << real << (imag >= 0 ? " + " : " - ") << fabs(imag) << "i";
	}
};

int main() {
	Complex c1(3, 4), c2(1, 2);

	cout << "c1 = "; c1.display(); cout << "\n";
	cout << "c2 = "; c2.display(); cout << "\n\n";

	Complex c3 = c1 + c2;
	cout << "c3 = c1 + c2 = "; c3.display(); cout << "\n";

	Complex c4 = c1 - c2;
	cout << "c4 = c1 - c2 = "; c4.display(); cout << "\n";

	Complex c5 = c1 * c2;
	cout << "c5 = c1 * c2 = "; c5.display(); cout << "\n";

	Complex c6 = c1 / c2;
	cout << "c6 = c1 / c2 = "; c6.display(); cout << "\n";

	Complex zero(0, 0);
	Complex c7 = c1 / zero; // division by zero test
	cout << "c7 = c1 / (0+0i) = "; c7.display(); cout << "\n";

	if (c1 == c2)
		cout << "c1 == c2 is TRUE\n";
	else
		cout << "c1 == c2 is FALSE\n";

	cout << "magnitude(c1) = " << c1.magnitude() << "\n";

	return 0;
}
