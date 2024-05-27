#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> prepAdjL(int edges)
{
    map<int,set<int>> adjL;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adjL[u].insert(v);
        adjL[v].insert(u);
    }
    return adjL;
}
void printAdjL(map<int,set<int>> &adjL)
{
    for(auto &it:adjL)
    {
        cout<<it.first<<" ->";
        for(auto &it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
void BFS(int node,map<int,set<int>> &adjL,map<int,bool> &visited,vector<int> &component)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        component.push_back(front);
        for(auto &it:adjL[front])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
            }
        }
    }
}
void DFS(int node,map<int,set<int>> &adjL,map<int,bool> &visited,vector<int> &component)
{
    visited[node]=1;
    component.push_back(node);
    for(auto &it:adjL[node])
    {
        if(!visited[it])
        DFS(it,adjL,visited,component);
    }
}
vector<vector<int>> bfs(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            BFS(it.first,adjL,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
vector<vector<int>> dfs(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            DFS(it.first,adjL,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
void isCyclicBFS(map<int,set<int>> &adjL,map<int,bool> &visited,int node,int &count)
{
    map<int,int> parent;
    queue<int> q;
    visited[node]=true;
    parent[node]=-1;
    q.push(node);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto &it:adjL[front])
        {
            if(!visited[it])
            {
                visited[it]=true;
                parent[it]=front;
                q.push(it);
            }
            else if(parent[front]!=it)
            count++;
        }
    }
}
void isCyclicDFS(map<int,set<int>> &adjL,map<int,bool> &visited,int node,int &count,int parent)
{
    visited[node]=true;
    
        for(auto &it:adjL[node])
        {
            if(!visited[it])
            {
                isCyclicDFS(adjL,visited,it,count,node);
            }
            else if(parent!=it)
            count++;
        }
    }
void isCyclic(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    int count=0;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
          //isCyclicBFS(adjL,visited,it.first,count); 
          isCyclicDFS(adjL,visited,it.first,count,-1); 
    }
    }
    cout<<count/2<<endl;
}
int main()
{
    int edges;
    cin>>edges;
    map<int,set<int>> adjL;
    adjL=prepAdjL(edges);
    printAdjL(adjL);
    vector<vector<int>> ans=bfs(adjL);
    cout<<"No of connected components by BFS Ttaversal is "<<ans.size()<<endl;
    for(auto &it: ans)
    {
        for(auto &it2:it)
        cout<<it2<<" ";
        cout<<endl;
    }
    ans=dfs(adjL);
    cout<<"No of connected components by DFS Ttaversal is "<<ans.size()<<endl;
    for(auto &it: ans)
    {
        for(auto &it2:it)
        cout<<it2<<" ";
        cout<<endl;
    }
    isCyclic(adjL);
}