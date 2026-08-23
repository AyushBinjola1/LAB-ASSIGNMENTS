#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int marks = 78;
	int &result = marks;

	cout << "Before modification:" << endl;
	cout << "marks = " << marks << endl;
	cout << "result = " << result << endl;

	cout << "Address of marks = " << &marks << endl;
	cout << "Address of result = " << &result << endl;

	result = 95;

	cout << "\nAfter modification:" << endl;
	cout << "marks = " << marks << endl;
	cout << "result = " << result << endl;

	int x, y;

	cout << "\nEnter two numbers: ";
	cin >> x >> y;

	cout << "Before Swap: x = " << x << ", y = " << y << endl;

	swap(x, y);

	cout << "After Swap: x = " << x << ", y = " << y << endl;

	return 0;
}
