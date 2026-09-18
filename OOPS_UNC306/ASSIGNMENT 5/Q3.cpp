#include <iostream>
using namespace std;

class DynamicArray {
private:
	int *data;
	int size;

public:
	// Default constructor - empty array
	DynamicArray() {
		size = 0;
		data = nullptr;
		cout << "[Default Constructor] empty array created\n";
	}

	// Parameterized constructor
	DynamicArray(int n) {
		if (n < 0) {
			cout << "[Parameterized Constructor] Invalid size " << n << ", creating empty array\n";
			size = 0;
			data = nullptr;
		} else {
			size = n;
			data = (size > 0) ? new int[size] : nullptr;
			for (int i = 0; i < size; i++) data[i] = 0;
			cout << "[Parameterized Constructor] allocated array of size " << size << "\n";
		}
	}

	// Copy constructor - DEEP copy
	DynamicArray(const DynamicArray &other) {
		size = other.size;
		if (size > 0) {
			data = new int[size];
			for (int i = 0; i < size; i++) data[i] = other.data[i];
			cout << "[Copy Constructor] deep-copied array of size " << size << "\n";
		} else {
			data = nullptr;
			cout << "[Copy Constructor] copied empty array\n";
		}
	}

	// Destructor
	~DynamicArray() {
		cout << "[Destructor] releasing array of size " << size << "\n";
		delete[] data;
	}

	void set(int index, int value) {
		if (index < 0 || index >= size) {
			cout << "  Error: index " << index << " out of bounds (size=" << size << ")\n";
			return;
		}
		data[index] = value;
	}

	void display() const {
		cout << "  [ ";
		for (int i = 0; i < size; i++) cout << data[i] << " ";
		cout << "]\n";
	}
};

int main() {
	cout << "Creating original array of size 5:\n";
	DynamicArray original(5);
	for (int i = 0; i < 5; i++) original.set(i, i + 1);
	cout << "original: ";
	original.display();

	cout << "\nCopying original into 'copy' via copy constructor:\n";
	DynamicArray copy(original);

	cout << "\nModifying only 'copy' (setting all elements to 99):\n";
	for (int i = 0; i < 5; i++) copy.set(i, 99);

	cout << "\nAfter modification:\n";
	cout << "original: ";
	original.display();
	cout << "copy:     ";
	copy.display();

	cout << "\nTesting invalid size and invalid index:\n";
	DynamicArray bad(-2);
	bad.set(0, 10);        // out-of-bounds on empty array, handled safely
	original.set(50, 10);  // out-of-bounds index, handled safely

	cout << "\nEnd of main(), destructors will now fire:\n";
	return 0;
}
