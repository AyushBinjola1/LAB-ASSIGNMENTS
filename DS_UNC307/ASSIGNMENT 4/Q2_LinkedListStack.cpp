// Q2. Stack implementation using Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;
    int size;
    int maxSize;

public:
    LinkedListStack(int capacity = 100) {
        top = nullptr;
        size = 0;
        maxSize = capacity;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isFull() {
        return size == maxSize;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListStack s(100);
    int choice, value;

    do {
        cout << "\n--- Linked List Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. IsFull\n6. Display\n7. Exit\n";
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
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
