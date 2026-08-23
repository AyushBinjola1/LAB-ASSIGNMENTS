#include <iostream>
using namespace std;
int main() {
	int n = 5;
	int i, j;
	for (i = 1; i <= 2 * n - 1; i++) {
		if (i % 2 == 0)
			cout << "  ";

		int stars;
		if (i <= n)
			stars = (i + 1) / 2;
		else
			stars = (2 * n - i + 1) / 2;

		for (j = 1; j <= stars; j++) {
			cout << "* ";
			if (j != stars)
				cout << "  ";
		}

		cout << endl;
	}
	return 0;
}
