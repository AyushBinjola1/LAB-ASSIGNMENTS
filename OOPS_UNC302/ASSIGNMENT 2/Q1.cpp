#include <iostream>
using namespace std;

int main () {

	int a = 157;
	int b = 23;

	cout << "Addition = 		" << a+b << endl;
	cout << "Subtraction = 	" << a-b << endl;
	cout << "Multiplication = " << a*b << endl;
	cout << "Integer Division = " << a/b << endl;
	cout << "Floating Division = " << (float)a/b << endl;
	cout << "Remainder = " << a%b << endl;
	cout << endl << endl;
	cout << "157 / 23 = 		" << a/b << endl;
	cout << "(double)157 / 23 = " << (double)157 / 23 << endl;
	cout << "(double)(157 / 23) = " << (double)(157 / 23) << endl;
	cout << "157 / (double)23 = " << 157 / (double)23 << endl;

	return 0;
}
