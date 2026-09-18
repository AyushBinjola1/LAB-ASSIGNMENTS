#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a = 173;
	int b = 91;

	cout << "a = " << a << " = " << bitset<8>(a) << endl;
	cout << "b = " << b << " = " << bitset<8>(b) << endl;

	cout << "a & b = " << (a & b) << endl;
	cout << "a | b = " << (a | b) << endl;
	cout << "a ^ b = " << (a ^ b) << endl;
	cout << "~a = " << ~a << endl;
	cout << "~b = " << ~b << endl;
	cout << "a << 2 = " << (a << 2) << endl;
	cout << "b >> 3 = " << (b >> 3) << endl;

	return 0;
}
