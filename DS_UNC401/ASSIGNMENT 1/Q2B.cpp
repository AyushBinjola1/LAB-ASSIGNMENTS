#include <iostream>
using namespace std;

int maxOfArray(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximum element = " << maxOfArray(arr, n) << endl;

    return 0;
}
