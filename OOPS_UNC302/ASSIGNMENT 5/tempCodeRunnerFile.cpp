#include <iostream>
using namespace std;

class Complex {
private:
	double real, imag;

public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	friend Complex operator+(const Complex &a, const Complex &b);
	friend Complex operator-(const Complex &a, const Complex &b);
	friend Complex operator*(const Complex &a, const Complex &b);
	friend Complex operator/(const Complex &a, const Complex &b);

	void display() const {
		cout << real << (imag >= 0 ? " + " : " - ") << (imag >= 0 ? imag : -imag) << "i";
	}
};

// Friend function implementations (outside the class)
Complex operator+(const Complex &a, const Complex &b) {
	return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex &a, const Complex &b) {
	return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(const Complex &a, const Complex &b) {
	return Complex(a.real * b.real - a.imag * b.imag,
				   a.real * b.imag + a.imag * b.real);
}

Complex operator/(const Complex &a, const Complex &b) {
	double denom = b.real * b.real + b.imag * b.imag;
	if (denom == 0) {
		cout << "  Error: division by (0 + 0i)! Returning (0,0).\n";
		return Complex(0, 0);
	}
	double r = (a.real * b.real + a.imag * b.imag) / denom;
	double i = (a.imag * b.real - a.real * b.imag) / denom;
	return Complex(r, i);
}

int main() {
	Complex c1(5, 3), c2(2, 4);

	cout << "c1 = "; c1.display(); cout << "\n";
	cout << "c2 = "; c2.display(); cout << "\n\n";

	Complex sum = c1 + c2;
	cout << "c1 + c2 = "; sum.display(); cout << "\n";

	Complex diff = c1 - c2;
	cout << "c1 - c2 = "; diff.display(); cout << "\n";

	Complex prod = c1 * c2;
	cout << "c1 * c2 = "; prod.display(); cout << "\n";

	Complex quot = c1 / c2;
	cout << "c1 / c2 = "; quot.display(); cout << "\n";

	Complex zero(0, 0);
	Complex badDiv = c1 / zero;
	cout << "c1 / (0+0i) = "; badDiv.display(); cout << "\n";

	return 0;
}
