// Program to Debug (contains logical and syntax errors):
//
// #include <iostream>
// using namespace std;
//
// int main()
// {
// 	int a = 157;
// 	int b = 23;
//
// 	cout << "Addition = " << a - b << endl;
//
// 	cout << "Integer Division = " << (double)a / b << endl;
//
// 	cout << "Floating Division = " << (double)(a / b) << endl;
//
// 	char ch = "m";
//
// 	cout << "ASCII Value = " << ch << endl;
//
// 	cout << "Next Character = " << ch + 1 << endl;
//
// 	return 0;
// }

// Corrected Program:
#include <iostream>
using namespace std;

int main()
{
	int a = 157;
	int b = 23;

	cout << "Addition = " << a + b << endl;
	cout << "Integer Division = " << a / b << endl;
	cout << "Floating Division = " << (double)a / b << endl;

	char ch = 'm';

	cout << "ASCII Value = " << (int)ch << endl;
	cout << "Next Character = " << (char)(ch + 1) << endl;

	return 0;
}
