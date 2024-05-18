#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> prepareAdjL(int n,int m)
{
    map<int,set<int>> adjL;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjL[u].insert(v);
        adjL[v].insert(u);
    }
    return adjL;
}
void print(map<int,set<int>> &adjL)
{
    for(auto it:adjL)
    {
        cout<<it.first<<"->";
        for(auto it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
void bfs(int n,map<int,set<int>> &adjL,map<int,bool> &visited,vector<int> &ans)
{
    queue<int> q;
    q.push(n);
    visited[n]=1;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjL[frontNode])
        {
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<vector<int>> BFS(int n,map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto it:adjL)
    {
        if(!visited[it.first])
        {
        vector<int> component;
            bfs(it.first,adjL,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepareAdjL(n,m);
    print(adjL);
    vector<vector<int>> ans=BFS(n,adjL);
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        for(auto it2:it)
        cout<<it2<<" ";
    cout<<endl;
    }
    return 0;
}