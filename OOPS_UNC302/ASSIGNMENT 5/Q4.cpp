#include <iostream>
using namespace std;

class Complex {
private:
	double real, imag;

public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) {}

	double getReal() const { return real; }
	double getImag() const { return imag; }

	void display() const {
		cout << real << (imag >= 0 ? " + " : " - ") << (imag >= 0 ? imag : -imag) << "i";
	}
};

class ComplexOperations {
public:
	// Overload 1: add two integers (differs by number of args from #2)
	int operate(int a, int b) {
		cout << "operate(int,int) called with a=" << a << ", b=" << b << " -> ";
		return a + b;
	}

	// Overload 2: add three integers (differs by NUMBER of arguments)
	int operate(int a, int b, int c) {
		cout << "operate(int,int,int) called with a=" << a << ", b=" << b << ", c=" << c << " -> ";
		return a + b + c;
	}

	// Overload 3: multiply two real values (differs by DATA TYPE)
	double operate(double a, double b) {
		cout << "operate(double,double) called with a=" << a << ", b=" << b << " -> ";
		return a * b;
	}

	// Overload 4: add two Complex objects
	Complex operate(const Complex &a, const Complex &b) {
		cout << "operate(Complex,Complex) called -> ";
		return Complex(a.getReal() + b.getReal(), a.getImag() + b.getImag());
	}

	// Overload 5: multiply Complex by integer, Complex first
	Complex operate(const Complex &a, int k) {
		cout << "operate(Complex,int) called with k=" << k << " -> ";
		return Complex(a.getReal() * k, a.getImag() * k);
	}

	// Additional overload: same types as #5 but PARAMETER ORDER reversed
	Complex operate(int k, const Complex &a) {
		cout << "operate(int,Complex) called with k=" << k << " -> ";
		return Complex(a.getReal() * k, a.getImag() * k);
	}

	// INVALID overload (would not compile) - shown only as a comment:
	// double operate(int a, int b) { return a + b; }
	// This is invalid because it has the EXACT same parameter list
	// (int, int) as the first overload above; only the return type differs,
	// and return type alone is never used by the compiler to distinguish
	// overloaded functions.
};

int main() {
	ComplexOperations ops;

	int r1 = ops.operate(3, 4);
	cout << r1 << "\n";

	int r2 = ops.operate(3, 4, 5);
	cout << r2 << "\n";

	double r3 = ops.operate(2.5, 4.0);
	cout << r3 << "\n";

	Complex c1(1, 2), c2(3, 4);
	Complex r4 = ops.operate(c1, c2);
	r4.display();
	cout << "\n";

	Complex r5 = ops.operate(c1, 3);
	r5.display();
	cout << "\n";

	Complex r6 = ops.operate(3, c1); // reversed parameter order
	r6.display();
	cout << "\n";

	return 0;
}
