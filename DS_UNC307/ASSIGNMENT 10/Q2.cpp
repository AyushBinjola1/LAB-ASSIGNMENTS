#include <iostream>
using namespace std;
 
struct Node {
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};
 
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}
 
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}
 
void preorder(Node* root) {
    if (!root) return;
    cout << root->key << ' ';
    preorder(root->left);
    preorder(root->right);
}
 
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << ' ';
}
 
Node* smallest(Node* root) {
    while (root->left) root = root->left;
    return root;
}
 
Node* removeKey(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = removeKey(root->left, key);
    else if (key > root->key) root->right = removeKey(root->right, key);
    else {
        if (!root->left) {
            Node* next = root->right;
            delete root;
            return next;
        }
        if (!root->right) {
            Node* next = root->left;
            delete root;
            return next;
        }
        Node* next = smallest(root->right);
        root->key = next->key;
        root->right = removeKey(root->right, next->key);
    }
    return root;
}
 
void clearTree(Node* root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}
 
int main() {
    int keys[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 67};
    Node* root = nullptr;
    for (int key : keys) root = insert(root, key);
    cout << "Inorder: "; inorder(root); cout << '\n';
    cout << "Preorder: "; preorder(root); cout << '\n';
    cout << "Postorder: "; postorder(root); cout << '\n';
    int k;
    cout << "Enter key to delete: ";
    cin >> k;
    root = removeKey(root, k);
    cout << "Inorder after deletion: "; inorder(root); cout << '\n';
    clearTree(root);
}
