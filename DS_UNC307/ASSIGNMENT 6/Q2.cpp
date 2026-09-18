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

// ---------- Quick Sort ----------
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

// ---------- Merge Sort (with splitting & merging trace) ----------
vector<int> merge(const vector<int>& left, const vector<int>& right, int depth) {
    vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) result.push_back(left[i++]);
        else result.push_back(right[j++]);
    }
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);

    string indent(depth * 2, ' ');
    cout << indent << "Merging  : ";
    printArr(left);
    cout << " + ";
    printArr(right);
    cout << " -> ";
    printArr(result);
    cout << "\n";
    return result;
}

vector<int> mergeSort(vector<int> arr, int depth = 0) {
    if (arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector<int> leftHalf(arr.begin(), arr.begin() + mid);
    vector<int> rightHalf(arr.begin() + mid, arr.end());

    string indent(depth * 2, ' ');
    cout << indent << "Splitting: ";
    printArr(arr);
    cout << " -> ";
    printArr(leftHalf);
    cout << " | ";
    printArr(rightHalf);
    cout << "\n";

    vector<int> leftSorted = mergeSort(leftHalf, depth + 1);
    vector<int> rightSorted = mergeSort(rightHalf, depth + 1);
    return merge(leftSorted, rightSorted, depth);
}

int main() {
    vector<int> inputArray = {45, 12, 78, 34, 23, 90, 11, 67, 56, 29};

    cout << "Input Array: ";
    printArr(inputArray);
    cout << "\n";

    cout << "\nA. Quick Sort\n";
    vector<int> qsArr = inputArray;
    quickSort(qsArr, 0, qsArr.size() - 1);
    cout << "Sorted Array: ";
    printArr(qsArr);
    cout << "\n";

    cout << "\nB. Merge Sort (with splitting & merging steps)\n";
    vector<int> result = mergeSort(inputArray);
    cout << "\nFinal Sorted Array: ";
    printArr(result);
    cout << "\n";

    return 0;
}
