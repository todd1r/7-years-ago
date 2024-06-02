//topologicl sort
//tc o(n+e)
//sc o(n) linear

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
void topoSort(int node,map<int,bool> &visited,stack<int> &s,map<int,set<int>> &adjL)
{
    visited[node]=1;
    for(auto neighbour:adjL[node])
    {
        if(!visited[neighbour])
        topoSort(neighbour,visited,s,adjL);
    }
    //imp
    s.push(node);
}
vector<int> topologicalSort(map<int,set<int>> &adjL)
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
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepAdjL(m);
    print(adjL);
    vector<int> ans=topologicalSort(adjL);
    for(auto it:ans)
    cout<<it<<" ";
}