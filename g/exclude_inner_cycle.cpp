#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> prepAdjL(int m) {
    map<int, set<int>> adjL;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].insert(v);
        adjL[v].insert(u);
    }
    return adjL;
}

// Helper function to store cycles
void storeCycle(vector<int>& cycle, set<set<int>>& allCycles) {
    set<int> uniqueCycle(cycle.begin(), cycle.end());
    allCycles.insert(uniqueCycle);
}

void findAllCyclesUtil(int u, int parent, map<int, set<int>>& adj, vector<int>& path, vector<bool>& visited, set<set<int>>& allCycles) {
    visited[u] = true;
    path.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            findAllCyclesUtil(v, u, adj, path, visited, allCycles);
        } else if (v != parent) {
            // Found a cycle
            auto it = find(path.begin(), path.end(), v);
            if (it != path.end()) {
                vector<int> cycle(it, path.end());
                cycle.push_back(v);
                storeCycle(cycle, allCycles);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

void findAllCycles(map<int, set<int>>& adjL, set<set<int>>& allCycles) {
    vector<bool> visited(adjL.size(), false);
    vector<int> path;
    
    for (auto& node : adjL) {
        if (!visited[node.first]) {
            findAllCyclesUtil(node.first, -1, adjL, path, visited, allCycles);
        }
    }
}

bool isSubset(const set<int>& cycle1, const set<int>& cycle2) {
    return includes(cycle2.begin(), cycle2.end(), cycle1.begin(), cycle1.end());
}

int countUniqueCycles(set<set<int>>& allCycles) {
    vector<set<int>> cycles(allCycles.begin(), allCycles.end());

    // Sort cycles by size in descending order
    sort(cycles.begin(), cycles.end(), [](const set<int>& a, const set<int>& b) {
        return a.size() > b.size();
    });

    vector<bool> included(cycles.size(), true);
    for (size_t i = 0; i < cycles.size(); i++) {
        if (!included[i]) continue;
        for (size_t j = i + 1; j < cycles.size(); j++) {
            if (isSubset(cycles[j], cycles[i])) {
                included[j] = false;
            }
        }
    }

    int uniqueCycleCount = 0;
    for (bool inc : included) {
        if (inc) uniqueCycleCount++;
    }

    return uniqueCycleCount;
}

void cycleDetection(map<int, set<int>> adjL) {
    set<set<int>> allCycles;
    findAllCycles(adjL, allCycles);
    int uniqueCycles = countUniqueCycles(allCycles);
    cout << uniqueCycles << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    map<int, set<int>> adjL = prepAdjL(m);
    cycleDetection(adjL);
    return 0;
}
