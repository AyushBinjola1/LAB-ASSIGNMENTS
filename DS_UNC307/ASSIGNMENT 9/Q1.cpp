// Q1: Minimum Spanning Tree using Prim's and Kruskal's algorithms
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
 
struct Edge { int u, v, w; };
 
// Heap item for Prim: reach vertex 'v' from 'from' at cost 'w'
struct Item {
    int w, v, from;
    bool operator>(const Item &o) const { return w > o.w; }
};
 
// ---------------- Prim's algorithm (starts from vertex 'start') ----------------
typedef vector<vector<pair<int, int>>> AdjList;     // adj[u] = list of (v, weight)
 
long long prim(int N, const AdjList &adj, int start, vector<Edge> &mst) {
    vector<bool> inTree(N + 1, false);
    priority_queue<Item, vector<Item>, greater<Item>> pq;   // min-heap on edge weight
    pq.push({0, start, 0});
    long long total = 0;
    int step = 0;
    while (!pq.empty()) {
        Item cur = pq.top();
        pq.pop();
        if (inTree[cur.v]) continue;            // vertex already in the tree: skip
        inTree[cur.v] = true;
        if (cur.from != 0) {                    // the first vertex has no edge
            mst.push_back({cur.from, cur.v, cur.w});
            total += cur.w;
            cout << "  Step " << ++step << ": add edge (" << cur.from << ", " << cur.v
                 << ") weight " << cur.w << "\n";
        }
        for (size_t k = 0; k < adj[cur.v].size(); k++)
            if (!inTree[adj[cur.v][k].first])
                pq.push({adj[cur.v][k].second, adj[cur.v][k].first, cur.v});
    }
    return total;
}
 
// ---------------- Disjoint set (Union-Find) used by Kruskal ----------------
vector<int> parent, rnk;
int findSet(int x) {
    if (parent[x] != x) parent[x] = findSet(parent[x]);   // path compression
    return parent[x];
}
bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;                   // same set: the edge would form a cycle
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}
 
// ---------------- Kruskal's algorithm ----------------
long long kruskal(int N, vector<Edge> edges, vector<Edge> &mst) {
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        if (a.w != b.w) return a.w < b.w;
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });
    parent.assign(N + 1, 0);
    rnk.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) parent[i] = i;
    long long total = 0;
    for (size_t k = 0; k < edges.size(); k++) {
        Edge e = edges[k];
        cout << "  Edge (" << e.u << ", " << e.v << ") weight " << e.w << ": ";
        if (unionSet(e.u, e.v)) {
            mst.push_back(e);
            total += e.w;
            cout << "accepted\n";
        } else {
            cout << "rejected (forms a cycle)\n";
        }
        if ((int)mst.size() == N - 1) break;    // a spanning tree has N-1 edges
    }
    return total;
}
 
void printMST(const vector<Edge> &mst, long long total) {
    cout << "  MST edges: ";
    for (size_t k = 0; k < mst.size(); k++) {
        cout << "(" << mst[k].u << ", " << mst[k].v << ")";
        if (k + 1 < mst.size()) cout << " ";
    }
    cout << "\n  Total weight = " << total << "\n";
}
 
int main() {
    int N, M;
    cout << "Enter number of vertices N and edges M: ";
    cin >> N >> M;
    vector<Edge> edges;
    AdjList adj(N + 1);
    cout << "Enter " << M << " edges (u v weight):\n";
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});               // undirected graph
    }
 
    cout << "\nPrim's algorithm (start vertex 1):\n";
    vector<Edge> mstP;
    long long totalP = prim(N, adj, 1, mstP);
    if ((int)mstP.size() != N - 1) {
        cout << "  The graph is not connected, so it has no spanning tree.\n";
        return 0;
    }
    printMST(mstP, totalP);
 
    cout << "\nKruskal's algorithm (edges in increasing order of weight):\n";
    vector<Edge> mstK;
    long long totalK = kruskal(N, edges, mstK);
    printMST(mstK, totalK);
 
    cout << "\nBoth algorithms give an MST of weight " << totalP
         << (totalP == totalK ? " (they agree)" : " (MISMATCH)") << "\n";
    return 0;
}
