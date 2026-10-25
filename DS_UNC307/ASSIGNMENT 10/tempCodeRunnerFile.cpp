// Q2: BST traversals and deletion of a node
#include <iostream>
#include <string>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};
 
// Insert a key into the BST (duplicates are ignored)
Node *insert(Node *root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}
 
// ---------- (a) Traversals ----------
void inorder(Node *r) {                 // Left -> Root -> Right
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}
void preorder(Node *r) {                // Root -> Left -> Right
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}
void postorder(Node *r) {               // Left -> Right -> Root
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}
 
Node *findMin(Node *r) {                // leftmost node of a subtree
    while (r->left) r = r->left;
    return r;
}
 
// ---------- (b) Delete a node, keeping the BST property ----------
// 'verbose' prints which case was used; it is false for the inner deletion in case 3.
Node *deleteNode(Node *root, int key, bool verbose, bool &found) {
    if (!root) return NULL;
    if (key < root->data) {
        root->left = deleteNode(root->left, key, verbose, found);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key, verbose, found);
    } else {
        found = true;
        if (!root->left && !root->right) {                       // Case 1: leaf
            if (verbose)
                cout << "Case 1: " << key << " is a leaf node, it is simply removed\n";
            delete root;
            return NULL;
        }
        if (!root->left || !root->right) {                       // Case 2: one child
            Node *child = root->left ? root->left : root->right;
            if (verbose)
                cout << "Case 2: " << key << " has one child (" << child->data
                     << "), the child takes its place\n";
            delete root;
            return child;
        }
        // Case 3: two children -> copy the inorder successor (smallest key of the
        // right subtree) into this node, then delete the successor from that subtree
        Node *succ = findMin(root->right);
        if (verbose)
            cout << "Case 3: " << key << " has two children, replaced by its "
                 << "inorder successor " << succ->data << "\n";
        root->data = succ->data;
        bool dummy = false;
        root->right = deleteNode(root->right, succ->data, false, dummy);
    }
    return root;
}
 
void printTree(Node *r, int space = 0) {   // rotated 90 degrees: right subtree on top
    if (!r) return;
    printTree(r->right, space + 6);
    cout << string(space, ' ') << r->data << "\n";
    printTree(r->left, space + 6);
}
void freeTree(Node *r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}
 
int main() {
    // The BST of the figure, built by inserting the keys in this order
    int keys[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 67};
    Node *root = NULL;
    for (int k : keys) root = insert(root, k);
 
    cout << "BST (rotated 90 degrees, right subtree on top):\n";
    printTree(root);
 
    cout << "\nInorder   : ";
    inorder(root);
    cout << "\nPreorder  : ";
    preorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    cout << "\n";
 
    int K;
    cout << "\nEnter the key K to delete: ";
    cin >> K;
    bool found = false;
    root = deleteNode(root, K, true, found);
    if (!found) cout << "Key " << K << " is not present in the BST, nothing deleted\n";
 
    cout << "\nBST after deletion:\n";
    printTree(root);
    cout << "\nInorder traversal after deletion: ";
    inorder(root);
    cout << "\n";
    freeTree(root);
    return 0;
}
