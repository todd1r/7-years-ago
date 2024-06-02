#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> EDGES;
map<int, set<pair<int,int>>> prepAdjl(int edges)
{
    map<int, set<pair<int,int>>> adjL;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >>w;
        adjL[u].insert({v,w});
        EDGES.push_back({u,v,w});
        // adjL[v].insert(u);
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
void noOfCyclesDFS(map<int, set<pair<int,int>>> &adjL, map<int, bool> &visited, map<int, bool> &dfs_visited, int parent, int node, int &count)
{
    visited[node] = 1;
    dfs_visited[node] = 1;
    for (auto &it : adjL[node])
    {
        if (!visited[it.first])
        {
            // cout<<" "<<it<<" "<<endl;
            noOfCyclesDFS(adjL, visited, dfs_visited, node, it.first, count);
        }
        else if (dfs_visited[it.first])
        {
            // cout<<"$"<<it<<"$"<<endl;
            count++;
        }
    }
    dfs_visited[node] = 0;
}
int isCyclic(map<int, set<pair<int,int>>> &adjL)
{
    map<int, bool> visited;
    map<int, bool> dfs_visited;
    int count = 0;
    for (auto &it : adjL)
    {
        if (!visited[it.first])
        {
            noOfCyclesDFS(adjL, visited, dfs_visited, -1, it.first, count);
        }
    }
    cout << endl<< "No of cycles present in the graph by DFS " << count << endl;
    if(count>0)
    return 1;
    else
    return 0;
}
void TOPO(map<int, set<pair<int,int>>> &adjL, map<int, bool> &visited, stack<int> &s, int node)
{
    visited[node] = 1;
    for (auto &it : adjL[node])
    {
        if (!visited[it.first])
        {
            // cout<<" "<<it<<" "<<endl;
            TOPO(adjL, visited, s, it.first);
        }
    }
    s.push(node);
}
vector<int> ShortestPath(map<int,set<pair<int,int>>> &adjL,int n)
{
    //yaha bass usne vector<bool> visited use kiya kaise?
    map<int,bool> visited;
    stack<int> s;
    for(auto &it:adjL)
        {
            if(!visited[it.first])
            {
               // bool ans=
                 TOPO(adjL, visited, s, it.first);
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
int bellmanFord(int n,int m, int src,int dest,map<int, set<pair<int,int>>> &adjL)
{
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    //n-1 times;
    for(int i=1;i<n;i++)
    {
        //traverse on edge list
        for(int j=0;j<m;j++)
        {
            int u=EDGES[j][0];
            int v=EDGES[j][1];
            int wt=EDGES[j][2];
            if(dist[u]!=1e9&&((dist[u]+wt)<dist[v]))
            dist[v]=dist[u]+wt;
        }
    }
    //check for negative cycle
    bool flag=0;
    for(int j=0;j<m;j++)
    {
            int u=EDGES[j][0];
            int v=EDGES[j][1];
            int wt=EDGES[j][2];
            if(dist[u]!=1e9&&((dist[u]+wt)<dist[v]))
            {
            flag=1;
            break;
            }
        }
        if(flag==0)
        return dist[dest];
        return -1;
}
int main()
{
    int n;
    cin>>n;
    int edges;
    cin >> edges;
    map<int, set<pair<int,int>>> adjL = prepAdjl(edges);
    printAdjl(adjL);
    int DAG=isCyclic(adjL);
    // if(DAG==0)
    // {
    // vector<int> ans=ShortestPath(adjL,n);
    // if(ans.size()==0)
    // cout<<endl<<"No path exists"<<endl;
    // else
    // {
    //     cout<<endl<<"Shortest Path is"<<endl;
    // for(auto &it:ans)
    // cout<<it<<"->";
    // }
    // }
    // vector<int> ans=dijkstra(adjL,n,0);
    // cout<<endl;
    // for(auto &it:ans)
    // cout<<it<<"->";
     int bell=bellmanFord(n,edges,1,3,adjL);
    cout<<bell<<endl;
}