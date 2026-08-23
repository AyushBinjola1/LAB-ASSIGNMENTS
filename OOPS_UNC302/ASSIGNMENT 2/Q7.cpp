#include <iostream>
using namespace std;

int main()
{
	int a = 29;
	int b = 8;
	double c = 17.625;

	cout << a / b << endl;
	cout << (double)a / b << endl;
	cout << (double)(a / b) << endl;
	cout << (int)c << endl;
	cout << a + c << endl;

	char ch = 'R';

	cout << ch + 5 << endl;
	cout << (char)(ch + 5) << endl;

	return 0;
}
