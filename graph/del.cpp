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
        //adjL[v].insert(u);
    }
    return adjL;
}
void printAdjL(map<int,set<int>> &adjL)
{
    for(auto &it:adjL)
    {
        cout<<it.first<<"->";
        for(auto &it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
void BFS(map<int,set<int>> &adjL,map<int,bool> &visited,int node,vector<int> &component)
{
    queue<int> q;
    visited[node]=1;
    q.push(node);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        component.push_back(front);
        for(auto &it:adjL[front])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
}
vector<vector<int>> bfs(map<int,set<int>> adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            BFS(adjL,visited,it.first,component);
            ans.push_back(component);
        }
    }
    return ans;
}
void DFS(map<int,set<int>> &adjL,map<int,bool> &visited,int node,vector<int> &component)
{
    component.push_back(node);
    visited[node]=1;
    for(auto &it:adjL[node])
    {
        if(!visited[it])
        DFS(adjL,visited,it,component);
    }
}
vector<vector<int>> dfs(map<int,set<int>> adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            DFS(adjL,visited,it.first,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int cycleBFS(map<int,set<int>> &adjL,map<int,bool> &visited,map<int,int> &parent,int node)
{
    queue<int> q;
    visited[node]=1;
    parent[node]=-1;
    q.push(node);
    int count=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto &it:adjL[front])
        {
            if(!visited[it])
            {
                visited[it]=1;
                parent[it]=front;
                q.push(it);
            }
            else if(parent[front]!=it)
            count++;
        }
    }
    return count;
}
void cycleDFS(map<int,set<int>> &adjL,map<int,bool> &visited,int parent,int node,int &count)
{
    visited[node]=1;
    for(auto &it:adjL[node])
    {
        if(!visited[it])
        cycleDFS(adjL,visited,node,it,count);
        else if(it!=parent)
        count++;
    }
}
void noOfCycles(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    map<int,int> parent;
    int count=0;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            //count=cycleBFS(adjL,visited,parent,it.first);
            cycleDFS(adjL,visited,-1,it.first,count);
        }
    }
    //cout<<"No of cycles using BFS "<<count/2<<endl;
    cout<<"No of cycles using DFS "<<count/2<<endl;
}
void TOPO(map<int,set<int>> &adjL,map<int,bool> &visited,stack<int> &s,int node)
{
    visited[node]=1;
    for(auto &it:adjL[node])
    {
        if(!visited[it])
        TOPO(adjL,visited,s,it);
    }
    s.push(node);
}
void topo(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    // map<int,int> parent;
    // int count=0;
    stack<int> s;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            TOPO(adjL,visited,s,it.first);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for(auto &it:ans)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int edges;
    cin>>edges;
    map<int,set<int>> adjL=prepAdjL(edges);
    printAdjL(adjL);

    // vector<vector<int>> bfs_trav=bfs(adjL);
    // cout<<"No of connected components by BFS Traversal is "<<bfs_trav.size()<<endl;
    // for(auto &it:bfs_trav)
    // {
    //     for(auto &it2:it)
    //     cout<<it2<<" ";
    //     cout<<endl;
    // }
    // vector<vector<int>> dfs_trav=dfs(adjL);
    // cout<<"No of connected components by DFS Traversal is "<<dfs_trav.size()<<endl;
    // for(auto &it:dfs_trav)
    // {
    //     for(auto &it2:it)
    //     cout<<it2<<" ";
    //     cout<<endl;
    // }
    // noOfCycles(adjL);
    

    topo(adjL);
}