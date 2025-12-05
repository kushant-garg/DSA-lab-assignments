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

    int selected[100] = {0};
    selected[0] = 1;

    int edges = 0, cost = 0;

    cout << "Prim MST edges:\n";

    while (edges < n - 1) {
        int minimum = 999999, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && adj[i][j] && adj[i][j] < minimum) {
                        minimum = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " -- " << y << " : " << minimum << "\n";
        cost += minimum;
        selected[y] = 1;
        edges++;
    }

    cout << "Total cost = " << cost;
}
