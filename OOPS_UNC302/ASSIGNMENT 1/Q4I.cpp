#include<iostream>
using namespace std;
int main(){
	for(int i=1 ;i<=5 ; i++){
		for(int k=1;k<=5-i;k++){
			cout <<" ";
		}
		for(int m=1;m<=i;m++){
			cout<<"*";
			for(int l=1;l<i;l++){
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
	for(int i=4 ;i>=1 ; i--){
		for(int k=1;k<=5-i;k++){
			cout <<" ";
		}
		for(int m=1;m<=i;m++){
			cout<<"*";
			for(int l=1;l<i;l++){
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
