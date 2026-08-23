// Q1 (x). Create a Doubly Linked List, insert into it, and reverse it
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

// Inserts a new node after a given position (1-indexed)
void insertAtPosition(Node*& head, int val, int position) {
    Node* newNode = createNode(val);

    if (position == 1 || head == NULL) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void displayForward(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List (forward): ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseDLL(Node* head) {
    Node* temp = NULL;
    Node* curr = head;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main() {
    Node* head = NULL;
    int n, val, pos;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertEnd(head, val);
    }

    displayForward(head);

    cout << "Enter value to insert: ";
    cin >> val;
    cout << "Enter position to insert at: ";
    cin >> pos;
    insertAtPosition(head, val, pos);

    cout << "After insertion: ";
    displayForward(head);

    head = reverseDLL(head);

    cout << "After reversal: ";
    displayForward(head);

    return 0;
}
