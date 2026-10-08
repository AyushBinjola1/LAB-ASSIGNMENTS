#include <iostream>
using namespace std;
 
struct Node {
    int data;
    int priority;     // smaller number = higher priority
};
 
class PriorityQueue {
    Node *arr;
    int count, capacity;
public:
    PriorityQueue(int size) : count(0), capacity(size) { arr = new Node[size]; }
    ~PriorityQueue() { delete[] arr; }
 
    bool isFull()  { return count == capacity; }
    bool isEmpty() { return count == 0; }
 
    // Insert in sorted position: the highest-priority element stays at the
    // front (index 0) ... lowest priority at the end. Equal priorities keep
    // FIFO order.
    void enqueue(int x, int p) {
        if (isFull()) {
            cout << "Priority Queue Overflow! Cannot insert " << x << endl;
            return;
        }
        int i = count - 1;
        while (i >= 0 && arr[i].priority > p) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1].data = x;
        arr[i + 1].priority = p;
        count++;
        cout << x << " (priority " << p << ") inserted." << endl;
    }
 
    // Remove the highest-priority element (the one at index 0)
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << arr[0].data << " (priority " << arr[0].priority << ") removed." << endl;
        for (int i = 1; i < count; i++) arr[i - 1] = arr[i];
        count--;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        cout << "Priority Queue (highest priority first):" << endl;
        for (int i = 0; i < count; i++)
            cout << "  Data: " << arr[i].data << "  Priority: " << arr[i].priority << endl;
    }
};
 
void demo() {
    cout << "===== DEMONSTRATION =====" << endl;
    PriorityQueue pq(4);
    pq.dequeue();                // underflow
    pq.enqueue(50, 3);
    pq.enqueue(60, 1);
    pq.enqueue(70, 2);
    pq.enqueue(80, 1);
    pq.enqueue(90, 5);           // overflow
    pq.display();
    cout << "Is full?  " << (pq.isFull() ? "Yes" : "No") << endl;
    pq.dequeue();
    pq.dequeue();
    pq.display();
    cout << "Is empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;
    cout << "=========================\n" << endl;
}
 
int main() {
    demo();
    int size, choice, val, pr;
    cout << "Enter size of priority queue: ";
    cin >> size;
    PriorityQueue pq(size);
    do {
        cout << "\n--- PRIORITY QUEUE MENU ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Check isFull\n"
             << "4. Check isEmpty\n5. Display\n6. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value and priority (smaller = higher priority): ";
                cin >> val >> pr;
                pq.enqueue(val, pr);
                break;
            case 2: pq.dequeue(); break;
            case 3: cout << (pq.isFull() ? "Queue is FULL" : "Queue is NOT full") << endl; break;
            case 4: cout << (pq.isEmpty() ? "Queue is EMPTY" : "Queue is NOT empty") << endl; break;
            case 5: pq.display(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
