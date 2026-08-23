// Q1 (iv). Delete an element from a Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteElement(Node*& head, int key) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Element " << key << " deleted" << endl;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            cout << "Element " << key << " deleted" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Element " << key << " not found in the list" << endl;
}

int main() {
    Node* head = NULL;
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertEnd(head, val);
    }

    display(head);

    cout << "Enter key to delete: ";
    cin >> key;
    deleteElement(head, key);

    display(head);

    return 0;
}
