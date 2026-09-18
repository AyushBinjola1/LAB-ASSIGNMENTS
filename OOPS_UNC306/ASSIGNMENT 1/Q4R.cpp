#include<iostream>
using namespace std;
int main() {
	int n = 8;
	int space,j;
	for(int i = 1; i <= 2*n-1; i++) {
		if(i <= n)
			space = n - i;
		else
			space = i - n;
		for(int s = 1; s <= space; s++)
			cout << " ";
		if(i <= n) {
			for( j = 1; j <= i; j++){
				cout << j;
				if(j!=i){
					cout<<" ";
				}
			}
		}
		else {
			for(int j = 1; j <= 2*n-i; j++){
				cout << j;
				if(j!=i){
					cout<<" ";
				}
			}
		}

		cout << endl;
	}
	return 0;
}
