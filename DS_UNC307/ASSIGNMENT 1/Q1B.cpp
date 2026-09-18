#include <iostream>
using namespace std;

int smallestN(int goal)
{
    int sum = 0;
    int n = 0;

    while (sum < goal)
    {
        n++;
        sum += n;
    }

    return n;
}

int main()
{
    int goal;

    cout << "Enter the goal value: ";
    cin >> goal;

    cout << "Smallest value of n = " << smallestN(goal);

    return 0;
}
