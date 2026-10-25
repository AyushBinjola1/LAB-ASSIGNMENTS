// Q2: Dijkstra's algorithm - shortest path from a source to a destination
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
 
const int INF = 1000000000;
 
int main() {
    int N, M;
    cout << "Enter number of vertices N and edges M: ";
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);      // (neighbour, weight)
    cout << "Enter " << M << " edges (u v weight):\n";
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < 0) {
            cout << "Negative weights are not allowed in Dijkstra\n";
            return 0;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});                   // undirected graph
    }
    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;
    if (src < 1 || src > N) {
        cout << "Source " << src << " does not exist (vertices are 1 to " << N << ")\n";
        return 0;
    }
 
    vector<int> dist(N + 1, INF), parent(N + 1, 0);
    vector<bool> done(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
 
    cout << "\nDijkstra from vertex " << src << ":\n";
    int step = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (done[u]) continue;                      // outdated heap entry
        done[u] = true;
        cout << "  Step " << ++step << ": pick vertex " << u
             << " (distance " << d << ")\n";
        for (size_t k = 0; k < adj[u].size(); k++) {
            int v = adj[u][k].first, w = adj[u][k].second;
            if (!done[v] && d + w < dist[v]) {      // relaxation
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
                cout << "      relax (" << u << ", " << v << "): dist[" << v
                     << "] = " << dist[v] << "\n";
            }
        }
    }
 
    // Build the path to a vertex by following the parent links backwards
    auto pathTo = [&](int t) {
        vector<int> path;
        for (int x = t; x != 0; x = parent[x]) path.push_back(x);
        reverse(path.begin(), path.end());
        return path;
    };
 
    auto printPath = [&](const vector<int> &p) {
        for (size_t k = 0; k < p.size(); k++) {
            cout << p[k];
            if (k + 1 < p.size()) cout << " -> ";
        }
    };
 
    cout << "\nShortest distances from vertex " << src << ":\n";
    cout << left << setw(8) << "Vertex" << setw(10) << "Distance" << "Path\n";
    for (int v = 1; v <= N; v++) {
        cout << left << setw(8) << v;
        if (dist[v] == INF) { cout << setw(10) << "INF" << "unreachable\n"; continue; }
        cout << setw(10) << dist[v];
        printPath(pathTo(v));
        cout << "\n";
    }
 
    cout << "\n";
    if (dest < 1 || dest > N)
        cout << "Destination " << dest << " does not exist in this graph "
             << "(vertices are 1 to " << N << ")\n";
    else if (dist[dest] == INF)
        cout << "There is no path from " << src << " to " << dest << "\n";
    else {
        cout << "Shortest path from " << src << " to " << dest << ": ";
        printPath(pathTo(dest));
        cout << "\nTotal cost = " << dist[dest] << "\n";
    }
    return 0;
}
