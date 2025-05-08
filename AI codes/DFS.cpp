#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    vector<bool> visited(n, false);
    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    dfs(start, adj, visited);
    cout << endl;

    return 0;
}
