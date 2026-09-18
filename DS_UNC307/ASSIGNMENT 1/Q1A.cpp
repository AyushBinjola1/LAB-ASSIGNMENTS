#include <iostream>
using namespace std;

int sumRange(int first, int last)
{
    int sum = 0;

    for (int i = first; i <= last; i++)
    {
        sum += i;
    }

    return sum;
}

int main()
{
    int first, last;

    cout << "Enter the first number: ";
    cin >> first;

    cout << "Enter the last number: ";
    cin >> last;

    cout << "\nThe sum from " << first << " to " << last
         << " is = " << sumRange(first, last);

    return 0;
}
