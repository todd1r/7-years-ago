//topologicl sort
//tc o(n+e)
//sc o(n+e) linear

#include<bits/stdc++.h>
using namespace std;
map<int,set<pair<int,int>>> prepAdjL(int m)
{
    map<int,set<pair<int,int>>> adjL;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjL[u].insert({v,w});
       // adjL[v].insert(u);
    }
    return adjL;
}
void topoSort(int node,map<int,bool> &visited,stack<int> &s,map<int,set<pair<int,int>>> &adjL)
{
    visited[node]=1;
    for(auto neighbour:adjL[node])
    {
        if(!visited[neighbour.first])
        topoSort(neighbour.first,visited,s,adjL);
    }
    //imp
    s.push(node);
}
vector<int> topologicalSort(map<int,set<pair<int,int>>> &adjL,int n)
{
    //yaha bass usne vector<bool> visited use kiya kaise?
    map<int,bool> visited;
    stack<int> s;
    for(auto &it:adjL)
        {
            if(!visited[it.first])
            {
               // bool ans=
                topoSort(it.first,visited,s,adjL);
                // if(ans==1)
                // return true;
            }
        }

int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++)
    dist[i]=INT_MAX;
    dist[src]=0;
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(dist[top]!=INT_MAX)
        {
            for(auto &i:adjL[top])
            {
                if(dist[top]+i.second<dist[i.first])
                {
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }
    

        return dist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<pair<int,int>>> adjL=prepAdjL(m);
    vector<int> ans=topologicalSort(adjL,n);
    for(auto &it:ans)
    cout<<it<<" ";

    
}