#include<bits/stdc++.h>
#include<list>
using namespace std;
void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>>edges)
{
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void printAdj(unordered_map<int,set<int>>&adjList){
    for(auto i:adjList){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
void bfs(unordered_map<int,set<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto i:adjList[frontNode])
        {
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int,int>> edges)
{
    unordered_map<int,set<int>>adjList;
    vector<int> ans;
    unordered_map<int,bool>visited;
    prepareAdjList(adjList,edges);
    //printAdj(adjList);

    //traverse all components of a graph
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter th no of edges"<<endl;
    cin>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<int> answer=BFS(n,edges);
    for(auto it:answer)
    cout<<it<<" ";
    return 0;
}
//sc and tc is o(n+e)