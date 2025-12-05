#include <iostream>
using namespace std;

int adj[100][100];
int visited[100];
int n;

void dfs(int node) {
    cout << node << " ";
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < 100; i++)
        visited[i] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    cout << "DFS: ";
    dfs(start);
}
