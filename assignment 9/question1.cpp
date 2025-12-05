#include <iostream>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    int adj[100][100] = {0};
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    int visited[100] = {0};
    int queue[100], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS: ";

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
