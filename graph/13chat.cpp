#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return (a[2] < b[2]);
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < edges.size(); i++) {
        cout << "Edge " << i << ": " << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
    }
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v) {
            cout<<"hi "<< minWeight<<" hi"<<endl;
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m);  // Initialize the edges vector with the correct size

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
    }

    // Debug print to confirm edges are read correctly
    // for (int i = 0; i < edges.size(); i++) {
    //     cout << "Edge " << i << ": " << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
    // }

    int result = minimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree Weight: " << result << endl;

    return 0;
}
