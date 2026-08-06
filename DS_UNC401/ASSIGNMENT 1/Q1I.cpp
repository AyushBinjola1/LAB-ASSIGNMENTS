#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    if (n == 0) return 0;
    int distinctCount = 1;
    for (int i = 1; i < n; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < distinctCount; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            arr[distinctCount] = arr[i];
            distinctCount++;
        }
    }
    return distinctCount;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
