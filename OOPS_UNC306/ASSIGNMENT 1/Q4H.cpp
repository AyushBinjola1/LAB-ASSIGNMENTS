#include <iostream>
using namespace std;
int main() {
	int n = 5;
	int i, j,k;
	for (i = 1; i<=2*n-1; i++) {

		int stars,space;
		if (i <= n)
			stars = 10-2*i;
		else
			stars = 2*i-10;

		for (j = 1; j <= stars; j++) {
			cout << " ";
		}
		if (i <= n)
			space = (i + 1) / 2;
		else
			space = (2 * n - i + 1) / 2;

		for (k = 1; k <= space; k++) {
			cout << "* ";
			if (k != space)
				cout << "  ";
		}

		cout << endl;
	}
	return 0;
}
