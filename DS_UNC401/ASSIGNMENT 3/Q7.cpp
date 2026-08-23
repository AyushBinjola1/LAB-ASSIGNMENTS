// Q1 (vii). Concatenate 2 Linked Lists
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

// Appends list2 to the end of list1 and returns the head of concatenated list
Node* concatenateLists(Node* list1, Node* list2) {
    if (list1 == NULL)
        return list2;

    Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    return list1;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, val;

    cout << "Enter number of elements in first list: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertEnd(list1, val);
    }

    cout << "Enter number of elements in second list: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insertEnd(list2, val);
    }

    cout << "First list -> ";
    display(list1);
    cout << "Second list -> ";
    display(list2);

    Node* result = concatenateLists(list1, list2);

    cout << "Concatenated list -> ";
    display(result);

    return 0;
}
