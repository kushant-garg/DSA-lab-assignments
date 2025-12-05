#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unionSet(int parent[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    parent[b] = a;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[100];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[j].w < edges[i].w) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }

    int parent[100];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Kruskal MST edges:\n";

    int cost = 0;
    for (int i = 0; i < e; i++) {
        if (findParent(parent, edges[i].u) != findParent(parent, edges[i].v)) {
            cout << edges[i].u << " -- " << edges[i].v << " : " << edges[i].w << "\n";
            cost += edges[i].w;
            unionSet(parent, edges[i].u, edges[i].v);
        }
    }

    cout << "Total cost = " << cost;
}
