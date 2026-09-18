#include <iostream>
using namespace std;

int main()
{
	char ch = 'm';

	cout << "Character = " << ch << endl;
	cout << "ASCII Value = " << (int)ch << endl;
	cout << "Previous Character = " << (char)(ch - 1) << endl;
	cout << "Next Character = " << (char)(ch + 1) << endl;
	cout << "Uppercase Character = " << (char)(ch - 32) << endl;
	cout << "ASCII Difference = " << ('m' - 'M') << endl;
	cout << "ch + 5 = " << ch + 5 << endl;
	cout << "(char)(ch + 5) = " << (char)(ch + 5) << endl;

	return 0;
}
