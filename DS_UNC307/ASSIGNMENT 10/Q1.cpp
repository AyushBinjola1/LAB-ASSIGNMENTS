// Q1: Checking binary tree types (Balanced, Complete, Full, Perfect)
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};
 
bool isNumber(const string &s) {
    size_t i = (s.size() > 1 && (s[0] == '-' || s[0] == '+')) ? 1 : 0;
    if (i >= s.size()) return false;
    for (; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}
 
// ---------- (a) Build the tree by level order insertion ----------
// Values are placed level by level, left to right: each node taken from the
// queue receives the next two values as its left and right child.
// The word "null" leaves a position empty.
Node *buildLevelOrder(const vector<string> &tok) {
    if (tok.empty() || tok[0] == "null") return NULL;
    Node *root = new Node(atoi(tok[0].c_str()));
    queue<Node *> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < tok.size()) {
        Node *cur = q.front();
        q.pop();
        if (i < tok.size()) {                       // left child
            if (tok[i] != "null") {
                cur->left = new Node(atoi(tok[i].c_str()));
                q.push(cur->left);
            }
            i++;
        }
        if (i < tok.size()) {                       // right child
            if (tok[i] != "null") {
                cur->right = new Node(atoi(tok[i].c_str()));
                q.push(cur->right);
            }
            i++;
        }
    }
    return root;
}
 
int height(Node *r) {                               // height in nodes (empty tree = 0)
    if (!r) return 0;
    return 1 + max(height(r->left), height(r->right));
}
int countNodes(Node *r) {
    return r ? 1 + countNodes(r->left) + countNodes(r->right) : 0;
}
 
// ---------- (b) Balanced: at EVERY node the subtree heights differ by <= 1 ----------
// Returns the height of the subtree, or -1 as soon as an unbalanced node is found.
int balancedHeight(Node *r, string &why) {
    if (!r) return 0;
    int hl = balancedHeight(r->left, why);
    if (hl == -1) return -1;
    int hr = balancedHeight(r->right, why);
    if (hr == -1) return -1;
    if (abs(hl - hr) > 1) {
        why = "node " + to_string(r->data) + " has left height " + to_string(hl) +
              " and right height " + to_string(hr);
        return -1;
    }
    return 1 + max(hl, hr);
}
bool isBalanced(Node *r, string &why) { return balancedHeight(r, why) != -1; }
 
// ---------- Complete: all levels full except the last (filled left to right) ------
// Level order traversal: once an empty position is seen, no node may follow it.
bool isComplete(Node *r, string &why) {
    queue<Node *> q;
    q.push(r);
    bool seenEmpty = false;
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        if (!cur) { seenEmpty = true; continue; }
        if (seenEmpty) {
            why = "node " + to_string(cur->data) + " comes after an empty position";
            return false;
        }
        q.push(cur->left);
        q.push(cur->right);
    }
    return true;
}
 
// ---------- Full: every node has either 0 or 2 children ----------
bool isFull(Node *r, string &why) {
    if (!r) return true;
    if (!r->left && !r->right) return true;
    if (r->left && r->right) return isFull(r->left, why) && isFull(r->right, why);
    why = "node " + to_string(r->data) + " has only one child";
    return false;
}
 
// ---------- Perfect: every internal node has 2 children, leaves on one level ------
// A tree of height h is perfect exactly when it has 2^h - 1 nodes.
bool isPerfect(Node *r, string &why) {
    int h = height(r), n = countNodes(r);
    long long need = (1LL << h) - 1;
    if (n == need) return true;
    why = to_string(n) + " nodes, but a perfect tree of height " + to_string(h) +
          " needs " + to_string(need);
    return false;
}
 
void printTree(Node *r, int space = 0) {            // rotated 90 degrees, right on top
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
void report(const char *name, bool ok, const string &why, const char *yesNote) {
    if (ok) cout << name << "YES  (" << yesNote << ")\n";
    else cout << name << "NO   (" << why << ")\n";
}
 
int main() {
    int n;
    cout << "Enter number of array elements: ";
    cin >> n;
    vector<string> tok(n);
    cout << "Enter the elements (type null for an empty position):\n";
    for (int i = 0; i < n; i++) {
        cin >> tok[i];
        if (tok[i] != "null" && !isNumber(tok[i])) {
            cout << "Invalid element: " << tok[i] << "\n";
            return 0;
        }
    }
 
    Node *root = buildLevelOrder(tok);
    if (!root) {
        cout << "\nThe tree is empty.\n";
        return 0;
    }
    cout << "\nTree built by level order insertion";
    cout << " (rotated 90 degrees, right on top):\n";
    printTree(root);
    cout << "\nNodes = " << countNodes(root) << ", Height = " << height(root) << "\n\n";
 
    string w1, w2, w3, w4;
    report("Balanced : ", isBalanced(root, w1), w1, "subtree heights differ by <= 1");
    report("Complete : ", isComplete(root, w2), w2, "no gaps in level order");
    report("Full     : ", isFull(root, w3), w3, "every node has 0 or 2 children");
    report("Perfect  : ", isPerfect(root, w4), w4, "n = 2^h - 1");
    freeTree(root);
    return 0;
}
