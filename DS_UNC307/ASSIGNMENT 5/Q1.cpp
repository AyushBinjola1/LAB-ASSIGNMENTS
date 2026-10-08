#include <iostream>
using namespace std;
 
class LinearQueue {
    int *arr;
    int front, rear, capacity;
public:
    LinearQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    ~LinearQueue() { delete[] arr; }
 
    bool isFull()  { return rear == capacity - 1; }
    bool isEmpty() { return front > rear; }
 
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }
        arr[++rear] = x;
        cout << x << " inserted into queue." << endl;
    }
 
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << arr[front++] << " removed from queue." << endl;
        if (front > rear) {          // queue became empty: reset indices
            front = 0;
            rear = -1;
        }
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (front -> rear): ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
 
// Demonstration of the implementation
void demo() {
    cout << "===== DEMONSTRATION =====" << endl;
    LinearQueue q(3);
    q.dequeue();                 // underflow
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);               // overflow
    q.display();
    cout << "Is full?  " << (q.isFull() ? "Yes" : "No") << endl;
    q.dequeue();
    q.display();
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "=========================\n" << endl;
}
 
// Menu-driven main
int main() {
    demo();
    int size, choice, val;
    cout << "Enter size of queue: ";
    cin >> size;
    LinearQueue q(size);
    do {
        cout << "\n--- LINEAR QUEUE MENU ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Check isFull\n"
             << "4. Check isEmpty\n5. Display\n6. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isFull() ? "Queue is FULL" : "Queue is NOT full") << endl; break;
            case 4: cout << (q.isEmpty() ? "Queue is EMPTY" : "Queue is NOT empty") << endl; break;
            case 5: q.display(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
