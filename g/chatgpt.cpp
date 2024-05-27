#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> prepAdjL(int edges) {
    map<int, set<int>> adjL;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].insert(v);
    }
    return adjL;
}

bool isCyclicDFS(map<int, set<int>> &adjL, map<int, bool> &visited, map<int, bool> &dfs_visited, int node, int &count) {
    visited[node] = true;
    dfs_visited[node] = true;
    bool hasCycle = false;

    for (auto &it : adjL[node]) {
        if (!visited[it]) {
            if (isCyclicDFS(adjL, visited, dfs_visited, it, count)) {
                hasCycle = true;
            }
        } else if (dfs_visited[it]) {
            hasCycle = true;
        }
    }

    dfs_visited[node] = false; // Unmark the node in the current path
    return hasCycle;
}

void isCyclic(map<int, set<int>> &adjL) {
    map<int, bool> visited;
    map<int, bool> dfs_visited;
    int count = 0;

    for (auto &it : adjL) {
        int node = it.first;
        if (!visited[node]) {
            if (isCyclicDFS(adjL, visited, dfs_visited, node, count)) {
                count++;
            }
        }
    }
    cout << "Number of cycles: " << count << endl;
}

int main() {
    int edges;
    cin >> edges;
    map<int, set<int>> adjL = prepAdjL(edges);
    isCyclic(adjL);
    return 0;
}
