// Q1: Graph representation using Adjacency Matrix and Adjacency List (undirected)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int N, M;
    cout << "Enter number of vertices N and number of edges M: ";
    cin >> N >> M;
 
    // Adjacency matrix (vertices are numbered 1..N, so size is N+1)
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    // Adjacency list: list[u] holds the neighbours of u
    vector<vector<int>> list(N + 1);
 
    cout << "Enter " << M << " edges (u v):\n";
    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v;
        if (u < 1 || u > N || v < 1 || v > N) {
            cout << "Invalid edge (" << u << ", " << v << ") ignored\n";
            continue;
        }
        if (u == v || matrix[u][v] == 1) {
            cout << "Self loop or repeated edge (" << u << ", " << v << ") ignored\n";
            continue;
        }
        // Undirected: store u -> v and v -> u
        matrix[u][v] = 1;
        matrix[v][u] = 1;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    for (int u = 1; u <= N; u++) sort(list[u].begin(), list[u].end());
 
    // ---- Print adjacency matrix ----
    cout << "\nAdjacency Matrix (" << N << " x " << N << "):\n";
    cout << "    ";
    for (int j = 1; j <= N; j++) cout << setw(3) << j;
    cout << "\n";
    for (int i = 1; i <= N; i++) {
        cout << setw(3) << i << " ";
        for (int j = 1; j <= N; j++) cout << setw(3) << matrix[i][j];
        cout << "\n";
    }
 
    // ---- Print adjacency list ----
    cout << "\nAdjacency List:\n";
    for (int u = 1; u <= N; u++) {
        cout << u << " -> ";
        for (size_t k = 0; k < list[u].size(); k++) {
            if (k > 0) cout << " -> ";
            cout << list[u][k];
        }
        if (list[u].empty()) cout << "(no neighbours)";
        cout << "\n";
    }
 
    // Save the matrix so that Q2 can read it as input
    ofstream out("graph_matrix.txt");
    out << N << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) out << matrix[i][j] << (j < N ? " " : "");
        out << "\n";
    }
    out.close();
    cout << "\nMatrix saved in graph_matrix.txt (input for Q2)\n";
    return 0;
}
