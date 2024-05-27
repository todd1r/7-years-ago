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
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<pair<int,int>>> adjL=prepAdjL(m);
    vector<int> ans=dijkstra(adjL,n,0);
    for(auto &it:ans)
    cout<<it<<" ";

    
}