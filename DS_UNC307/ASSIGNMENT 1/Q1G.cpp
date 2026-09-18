#include <iostream>
using namespace std;

int indexOfLargest(int arr[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
    return maxIndex;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int idx = indexOfLargest(arr, n);
    cout << "Largest element is " << arr[idx] << " at index " << idx << endl;

    return 0;
}
