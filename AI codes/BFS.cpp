#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    // Reading edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // BFS
    vector<bool> visited(n, false);
    queue<int> q;

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    cout << "\nBFS Traversal: ";
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
    return 0;
}
