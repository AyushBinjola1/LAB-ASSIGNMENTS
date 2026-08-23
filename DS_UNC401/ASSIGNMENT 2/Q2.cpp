#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void Merge(int A[], int n, int B[], int m)
{
	int C[100];
	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
	{
		if (A[i] < B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}

	while (i < n)
		C[k++] = A[i++];

	while (j < m)
		C[k++] = B[j++];

	cout << "\nMerged Array: ";
	for (int x = 0; x < k; x++)
		cout << C[x] << " ";
	cout << endl;
}

void Union(int A[], int n, int B[], int m)
{
	int C[100];
	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
	{
		if (A[i] < B[j])
		{
			if (k == 0 || C[k - 1] != A[i])
				C[k++] = A[i];
			i++;
		}
		else if (B[j] < A[i])
		{
			if (k == 0 || C[k - 1] != B[j])
				C[k++] = B[j];
			j++;
		}
		else
		{
			if (k == 0 || C[k - 1] != A[i])
				C[k++] = A[i];
			i++;
			j++;
		}
	}

	while (i < n)
	{
		if (k == 0 || C[k - 1] != A[i])
			C[k++] = A[i];
		i++;
	}

	while (j < m)
	{
		if (k == 0 || C[k - 1] != B[j])
			C[k++] = B[j];
		j++;
	}

	cout << "\nUnion: ";
	for (int x = 0; x < k; x++)
		cout << C[x] << " ";
	cout << endl;
}

void Intersection(int A[], int n, int B[], int m)
{
	int C[100];
	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
	{
		if (A[i] < B[j])
			i++;
		else if (B[j] < A[i])
			j++;
		else
		{
			if (k == 0 || C[k - 1] != A[i])
				C[k++] = A[i];
			i++;
			j++;
		}
	}

	cout << "\nIntersection: ";
	for (int x = 0; x < k; x++)
		cout << C[x] << " ";
	cout << endl;
}

int main()
{
	int A[100], B[100];
	int n, m;

	cout << "Enter size of first array: ";
	cin >> n;

	cout << "Enter elements of first array:\n";
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << "\nEnter size of second array: ";
	cin >> m;

	cout << "Enter elements of second array:\n";
	for (int i = 0; i < m; i++)
		cin >> B[i];

	// Check Sorted
	if (isSorted(A, n))
		cout << "\nFirst array is Sorted.";
	else
		cout << "\nFirst array is NOT Sorted.";

	if (isSorted(B, m))
		cout << "\nSecond array is Sorted.";
	else
		cout << "\nSecond array is NOT Sorted.";

	// Perform operations
	Merge(A, n, B, m);
	Union(A, n, B, m);
	Intersection(A, n, B, m);

	return 0;
}
