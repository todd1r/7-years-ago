#include<bits/stdc++.h>
#include<list>
using namespace std;
bool isCyclicBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front]){
        if(visited[neighbour]&& neighbour!=parent[front])
        return true;
        else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=true;
            parent[neighbour]=front;
        }
    }
}
return false;
}
bool isCyclicDFS(int node,int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected=isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetected)
            return true;
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}
void print(unordered_map<int,list<int>>&adj){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
string cycleDetection(vector<vector<int>>&edges,int n,int m)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    print(adj);
        unordered_map<int,bool> visited;

        //to handle disconnected components
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                //bool ans=isCyclicBFS(i,visited,adj);
                bool ans2=isCyclicDFS(i,-1,visited,adj);
                // if(ans==1)
                // return "Yes";
                if(ans2==1)
                return "Yes";
            }
        }
        return "No";
    
}
int main()
{
    int n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter th no of edges"<<endl;
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    string ANS=cycleDetection(edges,n,m);
    cout<<ANS<<endl;
    return 0;
}
//tc is linear