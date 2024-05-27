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
        adjL[v].insert(u);
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
void bfs(int i,map<int,set<int>> &adjL,map<int,bool> &visited,vector<int> &component)
{
    queue<int> q;
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        component.push_back(front);
        for(auto &it:adjL[front])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
            }
        }
    }
}
vector<vector<int>> BFS(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            bfs(it.first,adjL,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
void dfs(int i,map<int,set<int>> &adjL,map<int,bool> &visited,vector<int> &component)
{
    component.push_back(i);
    visited[i]=1;
    for(auto &it:adjL[i])
    {
        if(!visited[it])
        dfs(it,adjL,visited,component);
    }
}
vector<vector<int>> DFS(map<int,set<int>> &adjL)
{
    map<int,bool> visited;
    vector<vector<int>> ans;
    for(auto &it:adjL)
    {
        if(!visited[it.first])
        {
            vector<int> component;
            dfs(it.first,adjL,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}
// bool isCyclicBFS(int src,map<int,bool>&visited,map<int,set<int>>&adj)
// {
//     map<int,int> parent;
//     parent[src]=-1;
//     visited[src]=true;
//     queue<int> q;
//     q.push(src);
//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         for(auto neighbour:adj[front]){
//         if(visited[neighbour]&& neighbour!=parent[front])
//         return true;
//         else if(!visited[neighbour]){
//             q.push(neighbour);
//             visited[neighbour]=true;
//             parent[neighbour]=front;
//         }
//     }
// }
// return false;
// }
int isCyclicBFS(int src,map<int,bool>&visited,map<int,set<int>>&adj)
{
    int count=0;
    map<int,int> parent;
    parent[src]=-1;
    visited[src]=true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front]){
        if(visited[neighbour]&& neighbour!=parent[front])
        {
        count++;
        }
        else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=true;
            parent[neighbour]=front;
        }
    }
}
return count;
}
// bool isCyclicDFS(int node,int parent,map<int,bool> &visited,map<int,set<int>> &adj)
// {
//     visited[node]=true;
//     for(auto neighbour:adj[node]){
//         if(!visited[neighbour]){
//             bool cycleDetected=isCyclicDFS(neighbour,node,visited,adj);
//             if(cycleDetected)
//             return true;
//         }
//         else if(neighbour!=parent){
//             return true;
//         }
//     }
//     return false;
// }


bool isCyclicDFS(int node,int parent,map<int,bool> &visited,map<int,set<int>> &adj,int &count)
{
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            if(isCyclicDFS(neighbour,node,visited,adj,count))
        {}
        }
        else if(neighbour!=parent){
            count++;
        }
    }
    return false;
}


// string cycleDetection(map<int,set<int>> adjL)
// {
//         map<int,bool> visited;
//         //to handle disconnected components
//          for(auto &it:adjL)
//         {
//             if(!visited[it.first])
//             {
//                 bool ans=isCyclicBFS(it.first,visited,adjL);
//                 //bool ans2=isCyclicDFS(it.first,-1,visited,adjL);
//                 if(ans==1)
//                 return "Yes";
//                 // if(ans2==1)
//                 // return "Yes";
//             }
//         }
//         return "No";
    
// }
void cycleDetection(map<int,set<int>> adjL)
{
        map<int,bool> visited;
        int count=0;
        //to handle disconnected components
         for(auto &it:adjL)
        {
            if(!visited[it.first])
            {
                //int ans=isCyclicBFS(it.first,visited,adjL);
                isCyclicDFS(it.first,-1,visited,adjL,count);
                //cout<<"Answer by bfs "<<ans/2<<endl;
                // if(ans2==1)
                // return "Yes";
            }
        }
      cout<<"Answer by dfs "<<count/2<<endl;  
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepAdjL(m);
    print(adjL);
    vector<vector<int>> ans=BFS(adjL);
    cout<<"No of connected components in case of undirected graph by BFS traversal="<<ans.size()<<endl;
    for(auto &it:ans)
    {
        for(auto &it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> ans2=DFS(adjL);
    cout<<"No of connected components in case of undirected graph by DFS traversal="<<ans2.size()<<endl;
    for(auto &it:ans2)
    {
        for(auto &it2:it)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    cycleDetection(adjL);
    //  string cycle=cycleDetection(adjL);
    //  cout<<"Presence of cycle detected:"<<cycle<<endl;
}