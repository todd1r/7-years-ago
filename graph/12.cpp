//we can use set or priority queue for this
//tc o(elogv)
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
        adjL[v].insert({u,w});
    }
    return adjL;
}
vector<int> primsMST(map<int,set<pair<int,int>>> &adjL,int n,int src)
{
    map<int,int> key;
    map<int,bool> mst;
    map<int,int>parent;
    for(auto &it:adjL)
    {
        key[it.first]=INT_MAX;
        mst[it.first]=false;
        parent[it.first]=-1;
    }

    //let's start the algo
    key[src]=0;
    for(int i=0;i<n;i++)
    {
        int mini=INT_MAX;
        int u=-1;
        //find the min val
        for(auto &it:adjL)
        {
            if(mst[it.first]==false&&key[it.first]<mini)
            {
                u=it.first;
                mini=key[it.first];
            }
        }
        //mark min node as true
        mst[u]=true;
        //check its adjacent nodes
        for(auto it:adjL[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false&&w<key[v])
            {
                parent[v]=u;
                key[v]=w;
            }
        }
    }
vector<int> result;
for(auto &it:key)
result.push_back(it.second);
return result;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<pair<int,int>>> adjL=prepAdjL(m);
    vector<int> ans=primsMST(adjL,n,0);
    int count=0;
    for(auto &it:ans)
    {
        cout<<it<<" ";
     count+=it;
    }

    cout<<count;
}