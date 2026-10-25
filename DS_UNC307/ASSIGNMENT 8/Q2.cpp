// Q2: DFS and BFS to count the connected components of an undirected graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int N;
vector<vector<int>> adj;       // adjacency matrix, vertices 1..N
 
// DFS from vertex u: visits every vertex reachable from u (recursive)
void dfs(int u, vector<bool> &visited, vector<int> &order) {
    visited[u] = true;
    order.push_back(u);
    for (int v = 1; v <= N; v++)
        if (adj[u][v] == 1 && !visited[v])
            dfs(v, visited, order);
}
 
// BFS from vertex s: visits every vertex reachable from s using a queue
void bfs(int s, vector<bool> &visited, vector<int> &order) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v = 1; v <= N; v++)
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;      // mark on insertion: each vertex is queued once
                q.push(v);
            }
    }
}
 
void printComponent(int id, const vector<int> &order) {
    cout << "  Component " << id << ": ";
    for (size_t k = 0; k < order.size(); k++)
        cout << order[k] << (k + 1 < order.size() ? " " : "");
    cout << "\n";
}
 
int main() {
    cout << "Enter number of vertices N: ";
    cin >> N;
    adj.assign(N + 1, vector<int>(N + 1, 0));
    cout << "Enter the " << N << " x " << N << " adjacency matrix:\n";
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> adj[i][j];
 
    // ---- Connected components using DFS ----
    vector<bool> visited(N + 1, false);
    int dfsCount = 0;
    cout << "\nDFS traversal (vertices of each component in the order visited):\n";
    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            vector<int> order;
            dfs(u, visited, order);
            dfsCount++;
            printComponent(dfsCount, order);
        }
    }
    cout << "Number of connected components (DFS) = " << dfsCount << "\n";
 
    // ---- Connected components using BFS ----
    visited.assign(N + 1, false);
    int bfsCount = 0;
    cout << "\nBFS traversal (vertices of each component in the order visited):\n";
    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            vector<int> order;
            bfs(u, visited, order);
            bfsCount++;
            printComponent(bfsCount, order);
        }
    }
    cout << "Number of connected components (BFS) = " << bfsCount << "\n";
 
    cout << "\nBoth methods give the same answer: "
         << (dfsCount == bfsCount ? "YES" : "NO") << "\n";
    return 0;
}
