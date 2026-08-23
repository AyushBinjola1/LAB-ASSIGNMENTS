#include <iostream>
using namespace std;

int main()
{
	int x;

	x = 37;
	cout << "Initial Value = " << x << endl;
	cout << "Using x++" << endl;
	cout << "Printed Value = " << x++ << endl;
	cout << "Final Value = " << x << endl << endl;

	x = 37;
	cout << "Using ++x" << endl;
	cout << "Printed Value = " << ++x << endl;
	cout << "Final Value = " << x << endl << endl;

	x = 37;
	cout << "Using x--" << endl;
	cout << "Printed Value = " << x-- << endl;
	cout << "Final Value = " << x << endl << endl;

	x = 37;
	cout << "Using --x" << endl;
	cout << "Printed Value = " << --x << endl;
	cout << "Final Value = " << x << endl;

	return 0;
}
