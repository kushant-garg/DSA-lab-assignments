#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[100][100];
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[100], visited[100];

    for (int i = 0; i < n; i++) {
        dist[i] = 999999;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int c = 0; c < n - 1; c++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << "\n";
}
