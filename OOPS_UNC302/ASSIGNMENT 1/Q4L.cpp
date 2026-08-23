#include<iostream>
using namespace std;
int main(){
	int l=1,j;
	for(int i=4 ;i>=1 ; i--){
		for ( j=1 ; j<i ; j++){
			cout << " ";
		}
		l=5-i;
		for(int k=4;k>=i;k--){
			cout <<l;
			l++;
		}
		cout << endl;
	}
	return 0;
}
