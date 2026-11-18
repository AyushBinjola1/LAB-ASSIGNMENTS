#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
 
Node* buildTree(const vector<string>& values) {
    if (values.empty() || values[0] == "null") return nullptr;
    Node* root = new Node(stoi(values[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)values.size()) {
        Node* current = q.front(); q.pop();
        if (values[i] != "null") {
            current->left = new Node(stoi(values[i]));
            q.push(current->left);
        }
        i++;
        if (i < (int)values.size()) {
            if (values[i] != "null") {
                current->right = new Node(stoi(values[i]));
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}
 
int checkHeight(Node* root) {
    if (!root) return 0;
    int left = checkHeight(root->left);
    int right = checkHeight(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}
 
bool isComplete(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool gap = false;
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (!node) gap = true;
        else {
            if (gap) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}
 
bool isFull(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (!root->left || !root->right) return false;
    return isFull(root->left) && isFull(root->right);
}
 
int leftDepth(Node* root) {
    int d = 0;
    while (root) { d++; root = root->left; }
    return d;
}
 
bool perfectAtDepth(Node* root, int depth, int level = 1) {
    if (!root) return true;
    if (!root->left && !root->right) return level == depth;
    if (!root->left || !root->right) return false;
    return perfectAtDepth(root->left, depth, level + 1) &&
           perfectAtDepth(root->right, depth, level + 1);
}
 
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
 
int main() {
    int n;
    cout << "Number of entries: ";
    cin >> n;
    vector<string> values(n);
    cout << "Enter level-order values (null for a missing child):\n";
    for (int i = 0; i < n; i++) cin >> values[i];
    Node* root = buildTree(values);
    cout << "Balanced: " << (checkHeight(root) != -1 ? "Yes" : "No") << '\n';
    cout << "Complete: " << (isComplete(root) ? "Yes" : "No") << '\n';
    cout << "Full: " << (isFull(root) ? "Yes" : "No") << '\n';
    cout << "Perfect: " << (perfectAtDepth(root, leftDepth(root)) ? "Yes" : "No") << '\n';
    deleteTree(root);
}
