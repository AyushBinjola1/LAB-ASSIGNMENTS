#include <iostream>
#include <stdexcept>
using namespace std;
 
// Simple fixed-capacity stack
class Stack {
    int *arr;
    int top, capacity;
public:
    Stack(int size) : top(-1), capacity(size) { arr = new int[size]; }
    ~Stack() { delete[] arr; }
 
    bool isEmpty() const { return top == -1; }
    bool isFull()  const { return top == capacity - 1; }
    int  size()    const { return top + 1; }
 
    void push(int x) {
        if (isFull()) throw overflow_error("Stack Overflow");
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) throw underflow_error("Stack Underflow");
        return arr[top--];
    }
};
 
// Queue built from two stacks: forward (input) and reverse (output)
class QueueUsingStacks {
    Stack forward, reverse;
    int capacity;
public:
    QueueUsingStacks(int size) : forward(size), reverse(size), capacity(size) {}
 
    bool isEmpty() const { return forward.isEmpty() && reverse.isEmpty(); }
    bool isFull()  const { return forward.size() + reverse.size() == capacity; }
 
    // O(1): always push onto the forward stack
    void enqueue(int x) {
        if (isFull()) throw overflow_error("Queue Overflow: cannot enqueue " + to_string(x));
        forward.push(x);
    }
 
    // Amortised O(1): shift elements only when reverse stack is empty
    int dequeue() {
        if (isEmpty()) throw underflow_error("Queue Underflow: queue is empty");
        if (reverse.isEmpty()) {
            while (!forward.isEmpty())
                reverse.push(forward.pop());
        }
        return reverse.pop();
    }
};
 
int main() {
    int size, choice, val;
    cout << "Enter capacity of queue: ";
    cin >> size;
    QueueUsingStacks q(size);
 
    do {
        cout << "\n--- QUEUE USING TWO STACKS ---\n"
             << "1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        try {
            switch (choice) {
                case 1:
                    cout << "Enter value: "; cin >> val;
                    q.enqueue(val);
                    cout << val << " enqueued." << endl;
                    break;
                case 2:
                    cout << q.dequeue() << " dequeued." << endl;
                    break;
                case 3:
                    cout << (q.isFull() ? "Queue is FULL" : "Queue is NOT full") << endl;
                    break;
                case 4:
                    cout << (q.isEmpty() ? "Queue is EMPTY" : "Queue is NOT empty") << endl;
                    break;
                case 5: cout << "Exiting..." << endl; break;
                default: cout << "Invalid choice!" << endl;
            }
        } catch (const exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    } while (choice != 5);
    return 0;
}
