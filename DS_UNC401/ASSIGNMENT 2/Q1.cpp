#include <iostream>
using namespace std;

class Array
{
private:
	int A[100];
	int size;
	int length;

public:
	Array()
	{
		size = 100;
		length = 0;
	}

	void create()
	{
		cout << "Enter number of elements: ";
		cin >> length;

		cout << "Enter elements:\n";
		for (int i = 0; i < length; i++)
			cin >> A[i];
	}

	void Display()
	{
		cout << "Array: ";
		for (int i = 0; i < length; i++)
			cout << A[i] << " ";
		cout << endl;
	}

	void Append(int x)
	{
		if (length < size)
			A[length++] = x;
	}

	void Insert(int index, int x)
	{
		if (index >= 0 && index <= length)
		{
			for (int i = length; i > index; i--)
				A[i] = A[i - 1];

			A[index] = x;
			length++;
		}
	}

	int Delete(int index)
	{
		if (index >= 0 && index < length)
		{
			int x = A[index];
			for (int i = index; i < length - 1; i++)
				A[i] = A[i + 1];
			length--;
			return x;
		}
		return -1;
	}

	int LinearSearch(int key)
	{
		for (int i = 0; i < length; i++)
		{
			if (A[i] == key)
				return i;
		}
		return -1;
	}

	int BinarySearch(int key)
	{
		int low = 0, high = length - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (A[mid] == key)
				return mid;
			else if (key < A[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}

		return -1;
	}

	int Get(int index)
	{
		if (index >= 0 && index < length)
			return A[index];
		return -1;
	}

	void Set(int index, int x)
	{
		if (index >= 0 && index < length)
			A[index] = x;
	}

	int Max()
	{
		int max = A[0];

		for (int i = 1; i < length; i++)
		{
			if (A[i] > max)
				max = A[i];
		}

		return max;
	}

	int Min()
	{
		int min = A[0];

		for (int i = 1; i < length; i++)
		{
			if (A[i] < min)
				min = A[i];
		}
		return min;
	}

	void Reverse()
	{
		int i = 0;
		int j = length - 1;

		while (i < j)
		{
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}

	void LeftShift()
	{
		for (int i = 0; i < length - 1; i++)
			A[i] = A[i + 1];

		A[length - 1] = 0;
	}

	void RightShift()
	{
		for (int i = length - 1; i > 0; i--)
			A[i] = A[i - 1];

		A[0] = 0;
	}

	void LeftRotate()
	{
		int first = A[0];

		for (int i = 0; i < length - 1; i++)
			A[i] = A[i + 1];

		A[length - 1] = first;
	}

	void RightRotate()
	{
		int last = A[length - 1];

		for (int i = length - 1; i > 0; i--)
			A[i] = A[i - 1];

		A[0] = last;
	}
};

int main()
{
	Array arr;
	arr.create();

	cout << "\nOriginal ";
	arr.Display();

	arr.Append(100);
	cout << "\nAfter Append(100): ";
	arr.Display();

	arr.Insert(2, 50);
	cout << "After Insert(50 at 2nd Index): ";
	arr.Display();

	arr.Delete(3);
	cout << "After Delete(index 3): ";
	arr.Display();

	cout << "Linear Search 50 = Index "
		 << arr.LinearSearch(50) << endl;

	cout << "\n(Binary Search works only on sorted array.)\n";
	cout << "Binary Search 2 = Index "
		 << arr.BinarySearch(2) << endl;

	cout << "Get(2) = "
		 << arr.Get(2) << endl;

	arr.Set(2, 99);
	cout << "After Set(2,99): ";
	arr.Display();

	cout << "Maximum = "
		 << arr.Max() << endl;

	cout << "Minimum = "
		 << arr.Min() << endl;

	arr.Reverse();
	cout << "After Reverse: ";
	arr.Display();

	arr.LeftShift();
	cout << "After Left Shift: ";
	arr.Display();

	arr.RightShift();
	cout << "After Right Shift: ";
	arr.Display();

	arr.LeftRotate();
	cout << "After Left Rotate: ";
	arr.Display();

	arr.RightRotate();
	cout << "After Right Rotate: ";
	arr.Display();

	return 0;
}
