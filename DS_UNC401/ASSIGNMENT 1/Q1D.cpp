#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
int main() 
{
    int num;
    cout<<"Enter your number : ";
    cin>>num;
    if(isPrime(num)) cout << num << " is Prime." <<endl;
    else cout << num << " is not Prime." << endl;
    return 0;
}