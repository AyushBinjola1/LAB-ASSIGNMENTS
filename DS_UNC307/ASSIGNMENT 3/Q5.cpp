// Q1 (v). Check if a Linked List is sorted
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
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

bool isSorted(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data)
            return false;
        temp = temp->next;
    }
    return true;
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertEnd(head, val);
    }

    display(head);

    if (isSorted(head))
        cout << "The list is sorted (ascending order)" << endl;
    else
        cout << "The list is NOT sorted" << endl;

    return 0;
}
