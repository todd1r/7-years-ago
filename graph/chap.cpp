#include<bits/stdc++.h>
using namespace std;

map<int, set<int>> prepAdjL(int edges) {
    map<int, set<int>> adjL;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].insert(v);  // Directed edge u -> v
    }
    return adjL;
}

void printAdjL(map<int, set<int>> &adjL) {
    for (auto &it : adjL) {
        cout << it.first << "->";
        for (auto &it2 : it.second)
            cout << it2 << " ";
        cout << endl;
    }
}

void TOPO(map<int, set<int>> &adjL, map<int, bool> &visited, stack<int> &s, int node) {
    visited[node] = 1;
    for (auto &it : adjL[node]) {
        if (!visited[it])
            TOPO(adjL, visited, s, it);
    }
    s.push(node);
}

void topo(map<int, set<int>> &adjL) {
    map<int, bool> visited;
    stack<int> s;
    for (auto &it : adjL) {
        if (!visited[it.first]) {
            TOPO(adjL, visited, s, it.first);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int edges;
    cin >> edges;
    map<int, set<int>> adjL = prepAdjL(edges);
    printAdjL(adjL);

    topo(adjL);
}
