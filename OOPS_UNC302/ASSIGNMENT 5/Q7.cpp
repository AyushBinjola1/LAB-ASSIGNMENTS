#include <iostream>
using namespace std;

class Counter {
private:
	int count;

public:
	Counter(int c = 0) : count(c) {}

	// Prefix ++c : increments then returns reference to updated object
	Counter& operator++() {
		++count;
		return *this;
	}

	// Postfix c++ : dummy int parameter marks it as postfix.
	// Must save the ORIGINAL value before modifying, and return it by value.
	Counter operator++(int) {
		Counter temp = *this; // save current (old) state
		count++;
		return temp;          // return the old value
	}

	// Prefix --c
	Counter& operator--() {
		--count;
		return *this;
	}

	// Postfix c--
	Counter operator--(int) {
		Counter temp = *this;
		count--;
		return temp;
	}

	int getValue() const { return count; }

	void display() const {
		cout << "count = " << count;
	}
};

int main() {
	Counter c(5);
	cout << "Initial c: "; c.display(); cout << "\n\n";

	Counter a = ++c; // prefix increment
	cout << "a = ++c  -> a "; a.display();
	cout << " | c "; c.display(); cout << "\n\n";

	Counter b = c++; // postfix increment
	cout << "b = c++  -> b "; b.display();
	cout << " | c "; c.display(); cout << "\n\n";

	a = --c; // prefix decrement
	cout << "a = --c  -> a "; a.display();
	cout << " | c "; c.display(); cout << "\n\n";

	b = c--; // postfix decrement
	cout << "b = c--  -> b "; b.display();
	cout << " | c "; c.display(); cout << "\n";

	return 0;
}
