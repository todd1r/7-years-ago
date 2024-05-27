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
void isCyclicDFS(map<int,set<int>> &adjL,map<int,bool> &visited,map<int,bool> &dfs_visited,int node,int &count)
{
    visited[node]=true;
    dfs_visited[node]=true;
        for(auto &it:adjL[node])
        {
            if(!visited[it])
            {
                isCyclicDFS(adjL,visited,dfs_visited,it,count);
            }
            else if(dfs_visited[it])
            count++;
            else 
            dfs_visited[it]=0;
        }
        dfs_visited[node]=0;
    }
void isCyclic(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    map<int,bool> dfs_visited;
    int count=0;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
          //isCyclicBFS(adjL,visited,it.first,count); 
          isCyclicDFS(adjL,visited,dfs_visited,it.first,count);
          
    }
    }
    cout<<count<<endl;
}
void TOPO(map<int,set<int>> &adjL,map<int,bool> &visited,int node,stack<int> &s)
{
    visited[node]=1;
    for(auto &it:adjL[node])
    {
        if(!visited[it])
        TOPO(adjL,visited,it,s);
    }
    s.push(node);
}
void topo(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    stack<int> s;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
          //isCyclicBFS(adjL,visited,it.first,count); 
          TOPO(adjL,visited,it.first,s);
          
    }
    }
    vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        for(auto &it:ans)
    cout<<it<<" ";
}
int main()
{
    int edges;
    cin>>edges;
    map<int,set<int>> adjL;
    adjL=prepAdjL(edges);
    isCyclic(adjL);
    topo(adjL);
}













