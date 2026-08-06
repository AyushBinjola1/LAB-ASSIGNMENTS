#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[])
{
    for (int i = 0; i < n1; i++) result[i] = arr1[i];
    for (int i = 0; i < n2; i++) result[n1 + i] = arr2[i];
}

int main()
{
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter " << n1 << " elements: ";
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter " << n2 << " elements: ";
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    int result[n1 + n2];
    mergeArrays(arr1, n1, arr2, n2, result);

    cout << "Merged array: ";
    for (int i = 0; i < n1 + n2; i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
