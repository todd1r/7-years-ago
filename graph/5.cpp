#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> prepAdjL(int m)
{
    map<int,set<int>> adjL;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjL[u].insert(v);
       // adjL[v].insert(u);
    }
    return adjL;
}
void print(map<int,set<int>> &adjL)
{
    for(auto &it:adjL)
    {
        cout<<it.first<<"->";
        for(auto &it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
bool checkCycleDFS(int node,map<int,bool> &visited,map<int,bool> &dfsVisited,map<int,set<int>> &adjL)
{
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto neighbour:adjL[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected=checkCycleDFS(neighbour,visited,dfsVisited,adjL);
            if(cycleDetected)
            return true;
        }
        else if(dfsVisited[neighbour])
        return true;
    }
    dfsVisited[node]=false;
    return false;
}
int detectCycleInDirectedGraph(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    map<int,bool> dfsVisited;
     for(auto &it:adjL)
        {
            if(!visited[it.first])
            {
                bool ans=checkCycleDFS(it.first,visited,dfsVisited,adjL);
                if(ans==1)
                return true;
            }
        }
        return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepAdjL(m);
    print(adjL);
    int ans=detectCycleInDirectedGraph(adjL);
    cout<<ans;
}