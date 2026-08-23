#include <iostream>
using namespace std;

void SingleMissing(int A[], int n)
{
	int diff = A[0];

	for (int i = 0; i < n; i++)
	{
		if (A[i] - i != diff)
		{
			cout << "Missing Element = " << i + diff << endl;
			return;
		}
	}
}

void MultipleMissing(int A[], int n)
{
	int diff = A[0];

	cout << "Missing Elements: ";

	for (int i = 0; i < n; i++)
	{
		while (A[i] - i > diff)
		{
			cout << i + diff << " ";
			diff++;
		}
	}
	cout << endl;
}

void DuplicateSorted(int A[], int n)
{
	cout << "Duplicates in Sorted Array: ";

	int lastDuplicate = -1;

	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] == A[i + 1] && A[i] != lastDuplicate)
		{
			cout << A[i] << " ";
			lastDuplicate = A[i];
		}
	}
	cout << endl;
}

void DuplicateUnsorted(int A[], int n)
{
	cout << "Duplicates in Unsorted Array:\n";

	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] != -1)
		{
			int count = 1;

			for (int j = i + 1; j < n; j++)
			{
				if (A[i] == A[j])
				{
					count++;
					A[j] = -1;
				}
			}

			if (count > 1)
				cout << A[i] << " occurs " << count << " times\n";
		}
	}
}

void PairSumUnsorted(int A[], int n, int k)
{
	cout << "Pairs with Sum " << k << ":\n";

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] + A[j] == k)
				cout << A[i] << " + " << A[j] << " = " << k << endl;
		}
	}
}

void PairSumSorted(int A[], int n, int k)
{
	cout << "Pairs with Sum " << k << " (Sorted):\n";

	int i = 0;
	int j = n - 1;

	while (i < j)
	{
		if (A[i] + A[j] == k)
		{
			cout << A[i] << " + " << A[j] << " = " << k << endl;
			i++;
			j--;
		}
		else if (A[i] + A[j] < k)
			i++;
		else
			j--;
	}
}

void MaxMin(int A[], int n)
{
	int max = A[0];
	int min = A[0];

	for (int i = 1; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];

		if (A[i] < min)
			min = A[i];
	}

	cout << "Maximum = " << max << endl;
	cout << "Minimum = " << min << endl;
}

int main()
{

	int A[] = {6, 7, 8, 9, 11, 12, 13};
	int n = sizeof(A) / sizeof(A[0]);

	SingleMissing(A, n);

	int B[] = {3, 4, 5, 7, 8, 10, 11, 14};
	int m = sizeof(B) / sizeof(B[0]);

	MultipleMissing(B, m);

	int C[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
	int p = sizeof(C) / sizeof(C[0]);

	DuplicateSorted(C, p);

	int D[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7, 8};
	int q = sizeof(D) / sizeof(D[0]);

	DuplicateUnsorted(D, q);

	int E[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
	int r = sizeof(E) / sizeof(E[0]);

	PairSumUnsorted(E, r, 10);

	int F[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
	int s = sizeof(F) / sizeof(F[0]);

	PairSumSorted(F, s, 15);

	int G[] = {5, 8, 3, 9, 2, 10, 1};
	int t = sizeof(G) / sizeof(G[0]);

	MaxMin(G, t);

	return 0;
}
