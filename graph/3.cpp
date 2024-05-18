#include<bits/stdc++.h>
#include<list>
using namespace std;
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    //hr connected node k liye recursive call
    for(auto i:adj[node]){
        if(!visited[i])
        dfs(i,visited,adj,component);
    }
}
vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>>&edges)
{
    //prepare adjList
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}
void printAdj(unordered_map<int,set<int>>&adjList){
    for(auto i:adjList){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the no of edges"<<endl;
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>u>>v;
        edges.push_back({u,v});
    }
     vector<vector<int>> ans=depthFirstSearch(n,m,edges);
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        for(auto it2:it)
        cout<<it2<<" ";
    cout<<endl;
    }
    return 0;
}