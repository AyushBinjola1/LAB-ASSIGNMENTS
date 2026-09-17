#include <iostream>
using namespace std;

class DynamicVector {
private:
	int *data;
	int size;

public:
	// Default constructor
	DynamicVector() {
		size = 0;
		data = nullptr;
		cout << "[Default Constructor] empty vector\n";
	}

	// Parameterized constructor: allocate n elements, init to 0
	DynamicVector(int n) {
		size = (n > 0) ? n : 0;
		data = (size > 0) ? new int[size] : nullptr;
		for (int i = 0; i < size; i++) data[i] = 0;
		cout << "[Parameterized Constructor] size=" << size << "\n";
	}

	// Copy constructor: deep copy
	DynamicVector(const DynamicVector &other) {
		size = other.size;
		data = (size > 0) ? new int[size] : nullptr;
		for (int i = 0; i < size; i++) data[i] = other.data[i];
		cout << "[Copy Constructor] deep-copied size=" << size << "\n";
	}

	// Destructor
	~DynamicVector() {
		cout << "[Destructor] releasing size=" << size << " at " << this << "\n";
		delete[] data;
	}

	// Overload 1: set one indexed element
	void set(int index, int value) {
		if (index < 0 || index >= size) {
			cout << "  Error: index " << index << " out of range\n";
			return;
		}
		data[index] = value;
	}

	// Overload 2: set all elements to the same value
	void set(int value) {
		for (int i = 0; i < size; i++) data[i] = value;
	}

	// Element-wise addition; rejects mismatched sizes
	DynamicVector operator+(const DynamicVector &rhs) const {
		if (size != rhs.size) {
			cout << "  Error: cannot add vectors of different sizes ("
				 << size << " vs " << rhs.size << "). Returning empty vector.\n";
			return DynamicVector();
		}
		DynamicVector result(size);
		for (int i = 0; i < size; i++) result.data[i] = data[i] + rhs.data[i];
		return result;
	}

	// Equality: compares size and every element
	bool operator==(const DynamicVector &rhs) const {
		if (size != rhs.size) return false;
		for (int i = 0; i < size; i++)
			if (data[i] != rhs.data[i]) return false;
		return true;
	}

	// Indexed access with bounds checking
	int& operator[](int index) {
		if (index < 0 || index >= size) {
			cout << "  Error: index " << index << " out of range. Aborting access, returning data[0] guard.\n";
			static int dummy = -1; // safe fallback, avoids illegal memory access
			return dummy;
		}
		return data[index];
	}

	void display() const {
		cout << "  [ ";
		for (int i = 0; i < size; i++) cout << data[i] << " ";
		cout << "]\n";
	}
};

int main() {
	cout << "--- Constructors ---\n";
	DynamicVector v1(4);
	v1.set(0, 1); v1.set(1, 2); v1.set(2, 3); v1.set(3, 4);
	cout << "v1: "; v1.display();

	cout << "\n--- Copy & independence check ---\n";
	DynamicVector v2(v1); // copy constructor
	v2.set(100);          // overload: set all elements to same value
	cout << "v1 (original, unchanged): "; v1.display();
	cout << "v2 (copy, modified):      "; v2.display();

	cout << "\n--- Operator+ : valid addition ---\n";
	DynamicVector v3(4);
	v3.set(0, 10); v3.set(1, 20); v3.set(2, 30); v3.set(3, 40);
	DynamicVector v4 = v1 + v3;
	cout << "v1 + v3 = "; v4.display();

	cout << "\n--- Operator+ : incompatible sizes ---\n";
	DynamicVector v5(2);
	DynamicVector v6 = v1 + v5; // triggers size-mismatch error, returns empty
	cout << "v1 + v5 = "; v6.display();

	cout << "\n--- Operator== before/after modification ---\n";
	DynamicVector v7(v1); // copy of v1
	cout << "v1 == v7 (fresh copy)? " << (v1 == v7 ? "true" : "false") << "\n";
	v7[0] = 999; // operator[]
	cout << "v1 == v7 (after modifying v7[0])? " << (v1 == v7 ? "true" : "false") << "\n";

	cout << "\n--- Operator[] bounds checking ---\n";
	v1[50] = 5; // out-of-range access, handled safely

	cout << "\n--- End of main(): destructors fire now ---\n";
	return 0;
}
