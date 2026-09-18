#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void runCase(const string& label, int lowRange, int highRange, int size = 100000) {
    srand(42); // fixed seed for reproducibility
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (highRange - lowRange + 1) + lowRange;

    vector<int> arrCopy = arr;

    clock_t start = clock();
    quickSort(arrCopy, 0, arrCopy.size() - 1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    bool isSorted = is_sorted(arrCopy.begin(), arrCopy.end());

    cout << label << "\n";
    cout << "  Range              : [" << lowRange << ", " << highRange << "]\n";
    cout << "  Array size         : " << size << "\n";

    cout << "  First 10 (unsorted): [";
    for (int i = 0; i < 10; i++) cout << arr[i] << (i < 9 ? ", " : "");
    cout << "]\n";

    cout << "  First 10 (sorted)  : [";
    for (int i = 0; i < 10; i++) cout << arrCopy[i] << (i < 9 ? ", " : "");
    cout << "]\n";

    cout << "  Last 10 (sorted)   : [";
    for (int i = size - 10; i < size; i++) cout << arrCopy[i] << (i < size - 1 ? ", " : "");
    cout << "]\n";

    cout << "  Correctly sorted?  : " << (isSorted ? "true" : "false") << "\n";
    cout << "  Time taken         : " << timeTaken << " seconds\n\n";
}

int main() {
    runCase("A. Random elements from range [1, 100]", 1, 100);
    runCase("B. Random elements from range [1, 10000000]", 1, 10000000);
    return 0;
}
