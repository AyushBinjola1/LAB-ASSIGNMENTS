// Q1. Stack implementation using arrays
#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

class ArrayStack {
private:
    Stack stack;

public:
    ArrayStack() {
        stack.top = -1;
    }

    bool isFull() {
        return stack.top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return stack.top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        stack.data[++stack.top] = value;
        cout << value << " pushed to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        return stack.data[stack.top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return stack.data[stack.top];
    }

    int stackTop() {
        return peek();
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = stack.top; i >= 0; i--) {
            cout << stack.data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack s;
    int choice, value;

    do {
        cout << "\n--- Array Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. IsFull\n6. StackTop\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2: {
                int popped = s.pop();
                if (popped != -1)
                    cout << "Popped value: " << popped << endl;
                break;
            }
            case 3: {
                int top = s.peek();
                if (top != -1)
                    cout << "Top value: " << top << endl;
                break;
            }
            case 4:
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 6: {
                int top = s.stackTop();
                if (top != -1)
                    cout << "Stack top element: " << top << endl;
                break;
            }
            case 7:
                s.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
