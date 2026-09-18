#include <bits/stdc++.h>
using namespace std;

void printArr(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

vector<int> bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    return arr;
}

vector<int> selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
    return arr;
}

vector<int> insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main() {
    vector<int> inputArray = {56, 21, 84, 13, 42, 7, 68, 31};

    cout << "Input Array: ";
    printArr(inputArray);
    cout << "\n";

    cout << "A. Bubble Sort   : ";
    printArr(bubbleSort(inputArray));
    cout << "\n";

    cout << "B. Selection Sort: ";
    printArr(selectionSort(inputArray));
    cout << "\n";

    cout << "C. Insertion Sort: ";
    printArr(insertionSort(inputArray));
    cout << "\n";

    return 0;
}
