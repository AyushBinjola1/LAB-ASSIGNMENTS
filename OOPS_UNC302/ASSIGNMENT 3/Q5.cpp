#include <iostream>
using namespace std;
 
void findMinMax(int arr[], int n, int *minimum, int *maximum);
void calculateStats(int arr[], int n, double &average, int &evenCount, int &oddCount);
 
int main() {
    int n;
    cout << "Enter number of integers (at least 6): ";
    cin >> n;
 
    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
 
    int minVal, maxVal;
    double avg;
    int evenCount, oddCount;
 
    // addresses passed for pointer output parameters
    findMinMax(arr, n, &minVal, &maxVal);
    // variables passed directly for reference output parameters
    calculateStats(arr, n, avg, evenCount, oddCount);
 
    cout << "\n--- Statistics ---\n";
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Average: " << avg << endl;
    cout << "Even Count: " << evenCount << endl;
    cout << "Odd Count: " << oddCount << endl;
 
    return 0;
}
 
void findMinMax(int arr[], int n, int *minimum, int *maximum) {
    *minimum = arr[0];
    *maximum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *minimum) *minimum = arr[i];
        if (arr[i] > *maximum) *maximum = arr[i];
    }
}
 
void calculateStats(int arr[], int n, double &average, int &evenCount, int &oddCount) {
    int sum = 0;
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] % 2 == 0) evenCount++;
        else oddCount++;
    }
    average = (double)sum / n;
}
