// Q1 (vi). Merge 2 sorted Linked Lists into a single sorted Linked List
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

// Merges two sorted lists (list1 and list2) and returns the head of merged sorted list
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* mergedHead = NULL;

    if (list1->data <= list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }

    Node* tail = mergedHead;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return mergedHead;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, val;

    cout << "Enter number of elements in first sorted list: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements in ascending order: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertEnd(list1, val);
    }

    cout << "Enter number of elements in second sorted list: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements in ascending order: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertEnd(list2, val);
    }

    cout << "First list -> ";
    display(list1);
    cout << "Second list -> ";
    display(list2);

    Node* merged = mergeSortedLists(list1, list2);

    cout << "Merged sorted list -> ";
    display(merged);

    return 0;
}
