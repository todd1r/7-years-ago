#include <bits/stdc++.h>
using namespace std;
map<int, set<int>> prepAdjl(int edges)
{
    map<int, set<int>> adjL;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjL[u].insert(v);
        adjL[v].insert(u);
    }
    return adjL;
}
void printAdjl(map<int, set<int>> &adjL)
{
    for (auto &it : adjL)
    {
        cout << it.first << "->";
        for (auto &it2 : it.second)
            cout << it2 << " ";
        cout << endl;
    }
}
void BFS(map<int, set<int>> &adjL, map<int, bool> &visited, int node, vector<int> &component)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        component.push_back(front);
        for (auto &it : adjL[front])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}
vector<vector<int>> bfs(map<int, set<int>> &adjL)
{
    map<int, bool> visited;
    vector<vector<int>> ans;
    for (auto &it : adjL)
    {
        if (!visited[it.first])
        {
            vector<int> component;
            BFS(adjL, visited, it.first, component);
            ans.push_back(component);
        }
    }
    return ans;
}
void DFS(map<int, set<int>> &adjL, map<int, bool> &visited, int parent, int node, vector<int> &component)
{
    visited[node] = 1;
    component.push_back(node);
        for (auto &it : adjL[node])
        {
            if (!visited[it])
            {
                DFS(adjL,visited,node,it,component);
            }
        }
}
vector<vector<int>> dfs(map<int, set<int>> &adjL)
{
    map<int, bool> visited;
    vector<vector<int>> ans;
    int parent=-1;
    for (auto &it : adjL)
    {
        if (!visited[it.first])
        {
            vector<int> component;
            DFS(adjL, visited,-1, it.first, component);
            ans.push_back(component);
        }
    }
    return ans;
}
// bool isCycleBFS(map<int, set<int>> &adjL, map<int, bool> &visited, map<int,int> &parent, int node)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;
//     parent[node]=-1;
//     while (!q.empty())
//     {
//         int front = q.front();
//         q.pop();
//         for (auto &it : adjL[front])
//         {
//             if (!visited[it])
//             {
//                 q.push(it);
//                 visited[it] = 1;
//                 parent[it]=front;
//             }
//             else if(parent[front]!=it)
//             return true;
//         }
//     }
//     return false;
// }
// bool isCycleDFS(map<int, set<int>> &adjL, map<int, bool> &visited, int parent, int node)
// {
//     visited[node] = 1;
//         for (auto &it : adjL[node])
//         {
//             if (!visited[it])
//             {
//                 isCycleDFS(adjL,visited,node,it);
//             }
//             else if(parent!=it)
//             return true;
//         }
//         return false;
// }
// void isCyclic(map<int, set<int>> &adjL)
// {
//     map<int, bool> visited;
//     map<int,int> parent;
//     map<int, bool> dfs_visited;
//     for (auto &it : adjL)
//     {
//         if (!visited[it.first])
//         {
//             // bool ans=isCycleBFS(adjL, visited, parent, it.first);
//             bool ans=isCycleDFS(adjL, visited, -1, it.first);
//             if(ans==1)
//             cout<<"Cycle is present"<<endl;
//             else
//             cout<<"Cycle is not present"<<endl;
//         }
//     }
// }
int noOfCyclesBFS(map<int, set<int>> &adjL, map<int, bool> &visited, map<int,int> &parent, int node,int &count)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node]=-1;
    //int count=0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto &it : adjL[front])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
                parent[it]=front;
            }
            else if(parent[front]!=it)
            count++;
        }
    }
    return count;
}
//int i=0;
void noOfCyclesDFS(map<int, set<int>> &adjL, map<int, bool> &visited, int parent, int node,int &count)
{
    //i++;
    visited[node] = 1;
        for (auto &it : adjL[node])
        {
            if (!visited[it])
            {
                 //cout<<" "<<it<<" "<<endl;
                noOfCyclesDFS(adjL,visited,node,it,count);
            }
            else if(parent!=it)
            {
                //cout<<"$"<<it<<"$"<<endl;
            count++;
            }
        }
}
void isCyclic(map<int, set<int>> &adjL)
{
    map<int, bool> visited;
    map<int,int> parent;
    int count=0;
    for (auto &it : adjL)
    {
        if (!visited[it.first])
        {
            // bool ans=isCycleBFS(adjL, visited, parent, it.first);
            //bool ans=isCycleDFS(adjL, visited, -1, it.first);
            // if(ans==1)
            // cout<<"Cycle is present"<<endl;
            // else
            // cout<<"Cycle is not present"<<endl;



          noOfCyclesBFS(adjL, visited, parent, it.first,count);
            //noOfCyclesDFS(adjL, visited, -1, it.first,count);
        }
    }
    cout<<endl<<"No of cycles present in the graph by BFS "<<count/2<<endl;
    //cout<<endl<<"No of cycles present in the graph by DFS "<<count/2<<endl;
}
//9
//it will work only when graph is not weighted
vector<int> ShortestPath(map<int, set<int>> &adjL, int s,int d)
{
    map<int, bool> visited;
    map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s]=-1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto &it : adjL[front])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                parent[it]=front;
                q.push(it);
                // If we reached the destination node, we can stop the BFS
                 if (it == d)
                {
                    break;
                }
            }
        }
    }
    // If the destination node was never reached
    if (!visited[d])
    {
        return {};  // Return an empty vector to indicate no path exists
    }

    // Reconstruct the path from the destination to the source
    vector<int> ans;
    ans.push_back(d);
    int curr=d;
    while(curr!=s)
    {
        curr=parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//14
void dfs_fourteen(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,map<int,set<int>> &adjL, map<int,bool> &vis)
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
            dfs_fourteen(nbr,node,timer,disc,low,result,adjL,vis);
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
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent=-1;
    map<int,bool> vis;
    // for(int i=1;i<=v;i++)
    // {
    //     disc[i]=-1;
    //     low[i]=-1;
    // }

    vector<vector<int>> result;
    //dfs
    for(auto &it:adjL)
    {
        if(!vis[it.first])
        dfs_fourteen(it.first,parent,timer,disc,low,result,adjL,vis);
    }
    return result;
}
//sc o(n)
//tc o(n+e)

void dfs_fifteen(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<int> &ap,map<int,set<int>> &adjL, map<int,bool> &vis)
{
    vis[node]=1;
    disc[node]=low[node]=timer++;
    int child=0;
    for(auto nbr:adjL[node])
    {
        if(nbr==parent)
        {
            continue;
        }
        if(!vis[nbr])
        {
            dfs_fifteen(nbr,node,timer,disc,low,ap,adjL,vis);
            low[node]=min(low[node],low[nbr]);
            //check edge is bridge
            if(low[nbr]>=disc[node]&&parent!=-1)
            {
                ap[node]=1;
            }
            child++;
        }
        else
        {
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
    if(parent==-1&&child>1)
    ap[node]=1;
}
void articulate(map<int,set<int>> &adjL,int v,int e)
{
    int timer=0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    vector<int> ap(v,0);
    int parent=-1;
    map<int,bool> vis;

    //dfs
    for(auto &it:adjL)
    {
        if(!vis[it.first])
        dfs_fifteen(it.first,parent,timer,disc,low,ap,adjL,vis);
    }


    //print ap
    cout<<"Articulation points are as follows"<<endl;
    for(auto &it:adjL)
    {
        if(ap[it.first]!=0)
        cout<<it.first<<" ";
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int edges;
    cin >> edges;
    map<int, set<int>> adjL = prepAdjl(edges);
    printAdjl(adjL);
    vector<vector<int>> ans_bfs = bfs(adjL);
    cout << "No of components in bfs is " << ans_bfs.size();
    for (auto &it : ans_bfs)
    {
        cout << endl;
        for (auto &it2 : it)
            cout << it2 << " ";
    }
    vector<vector<int>> ans_dfs = dfs(adjL);
    cout << endl<<"No of components in dfs is " << ans_dfs.size();
    for (auto &it : ans_dfs)
    {
        cout << endl;
        for (auto &it2 : it)
            cout << it2 << " ";
    }
    isCyclic(adjL);
    vector<int> ans=ShortestPath(adjL, 1, 9);
    if(ans.size()==0)
    cout<<endl<<"No path exists"<<endl;
    else
    {
        cout<<endl<<"Shortest Path is"<<endl;
    for(auto &it:ans)
    cout<<it<<"->";
    }
    vector<vector<int>> bridge=findBridges(adjL,n,edges);
    cout<<endl<<"No of bridges"<<endl;
    for(auto &it:bridge)
    {
        for(auto &it2:it)
        cout<<it2<<" ";
        cout<<endl;
    }
   articulate(adjL,n, edges);
}