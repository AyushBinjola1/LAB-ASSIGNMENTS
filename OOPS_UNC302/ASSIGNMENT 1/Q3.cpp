#include<iostream>
using namespace std;
int main(){
	char ch;
	int num1 , num2 , result;
	cout << " Enter 1st number:"<< endl;
	cin >> num1;
	cout << " Enter 2nd  number:"<< endl;
	cin >> num2;
	cout << "Enter your choice:"<< endl;
	cout << "+ : for Addition"<< endl;
	cout << "- : for Subtraction"<< endl;
	cout << "* : for Multiplication"<< endl;
	cout << "/ : for Division"<< endl;
	cout << "% : for Modulo"<< endl;
	cin >> ch;
	switch (ch){
	case '+':
	result=num1+num2;
	cout << result;
	break;
	case '-':
	result=num1-num2;
	cout << result;
	break;
	case '*':
	result=num1*num2;
	cout << result;
	break;
	case '/':
	if(num2!=0){
	result=num1/num2;
	cout << result;
	break;
	}
	else{
	 cout<< "division by zero is not possible";
	 break;
	}
	case '%':
	if(num2!=0){
	result=num1%num2;
	cout << result;
	break;
	}
	else{
	 cout<< "division by zero is not possible";
	 break;
	}
	return 0;
	}
}
