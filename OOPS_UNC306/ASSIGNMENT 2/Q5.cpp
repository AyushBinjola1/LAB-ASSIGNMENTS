#include <iostream>
using namespace std;

int main()
{
	bool flag = true;
	char ch = 'A';
	short s = 120;
	int i = 5000;
	long l = 100000L;
	float f = 12.34f;
	double d = 123.456789;

	cout << "Data Type\tValue\t\tSize (Bytes)" << endl;

	cout << "bool\t\t" << flag << "\t\t" << sizeof(flag) << endl;
	cout << "char\t\t" << ch << "\t\t" << sizeof(ch) << endl;
	cout << "short\t\t" << s << "\t\t" << sizeof(s) << endl;
	cout << "int\t\t" << i << "\t\t" << sizeof(i) << endl;
	cout << "long\t\t" << l << "\t" << sizeof(l) << endl;
	cout << "float\t\t" << f << "\t\t" << sizeof(f) << endl;
	cout << "double\t\t" << d << "\t" << sizeof(d) << endl;

	return 0;
}
