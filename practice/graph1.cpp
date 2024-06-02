#include <bits/stdc++.h>
using namespace std;
map<int, set<pair<int,int>>> prepAdjl(int edges)
{
    map<int, set<pair<int,int>>> adjL;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >>w;
        adjL[u].insert({v,w});
        adjL[v].insert({u,w});
    }
    return adjL;
}
void printAdjl(map<int, set<pair<int,int>>> &adjL)
{
    for (auto &it : adjL)
    {
        cout << it.first << "->"<<endl;
        for (auto &it2 : it.second)
            cout << it2.first << " "<<it2.second<<endl;
        cout << endl;
    }
}
//we can use set or priority queue for this
//tc o(elogv)
//sc o(n+e) linear
vector<int> dijkstra(map<int,set<pair<int,int>>> &adjL,int n,int src)
{
    vector<int> dist(n,INT_MAX);
    set<pair<int,int>> st;
    dist[src]=0;
    st.insert(make_pair(0,src));
    while(!st.empty())
    {
        //fetch top record
        auto top=*(st.begin());

        int nodeDistance=top.first;
        int topNode=top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour:adjL[topNode])
        {
            if(nodeDistance+neighbour.second<dist[neighbour.first])
            {
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                //if record found, then erase it
                if(record!=st.end())
                st.erase(record);


                //distance update
                dist[neighbour.first]=nodeDistance+neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
        
    }
    

        return dist;
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
void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,map<int,set<int>> &adjL, map<int,bool> &vis)
{
    vis[node]=1;
    disc[node]=low[node]=timer++;
    for(auto nbr:adjL[node])
    {
        if(nbr==parent)
        {
            continue;
        }
        if(!vis[nbr])
        {
            dfs(nbr,node,timer,disc,low,result,adjL,vis);
            low[node]=min(low[node],low[nbr]);
            //check edge is bridge
            if(low[nbr]>disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(map<int,set<int>> &adjL,int v,int e)
{
    int timer=0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent=-1;
    map<int,bool> vis;
    for(int i=0;i<v;i++)
    {
        disc[i]=-1;
        low[i]=-1;
    }

    vector<vector<int>> result;
    //dfs
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        dfs(i,parent,timer,disc,low,result,adjL,vis);
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    int edges;
    cin >> edges;
    map<int, set<pair<int,int>>> adjL = prepAdjl(edges);
//     printAdjl(adjL);
//     vector<int> ans=dijkstra(adjL,n,0);
//     cout<<endl;
//     for(auto &it:ans)
//     cout<<it<<"->";
//     ans=primsMST(adjL,n,0);
//     int count=0;
//     cout<<endl;
//     for(auto &it:ans)
//     {
//         cout<<it<<" ";
//      count+=it;
//     }
// cout<<endl;
//     cout<<count;
}