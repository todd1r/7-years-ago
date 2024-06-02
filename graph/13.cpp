#include<bits/stdc++.h>
using namespace std;
void makeSet(vector<int> &parent,vector<int> &rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(vector<int> &parent,int node)
{
    if(parent[node]==node)
    return node;
    return parent[node]=findParent(parent,parent[node]);
}
void unionSet(int u,int  v,vector<int> &parent, vector<int> &rank)
{
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v])
    parent[u]=v;
    else if(rank[v]<rank[u])
    parent[v]=u;
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}
bool cmp(vector<int> &a,vector<int> &b)
{
return (a[2]<b[2]);
}

int minimumSpanningTree(vector<vector<int>> &edges,int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int minWeight=0;
    for(int i=0;i<edges.size();i++)
    {
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v)
        {
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}
int main()
{
    int n;
    cin>>n;
    int m;
    //cout<<"Enter th no of edges"<<endl;
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        // for(int j=0;j<3;j++)
        // {
        edges.push_back(vector<int> ());
        int v,u,w;
        cin>>u>>v>>w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
        //}
    }
    int ans= minimumSpanningTree(edges,n);
    cout<<ans<<endl;
}