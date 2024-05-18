#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> prepare(int n,int m)
{
    map<int,set<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    return adj;
}
void print(map<int,set<int>> &adj)
{
    cout<<adj.size()<<endl;
    for(auto it:adj)
    {
        cout<<it.first<<"->";
        for(auto it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
void dfs(int i,map<int,set<int>> &adj,map<int,bool> visited,vector<int> component)
{

}
vector<vector<int>> DFS(int n,int m,map<int,set<int>> adj)
{
    vector<vector<int>> ans;
    map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adj=prepare(n,m);
    print(adj);
    vector<int> ans=BFS(n,adj);
}