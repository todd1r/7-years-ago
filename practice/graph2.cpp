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
        // adjL[v].insert(u);
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

void noOfCyclesDFS(map<int, set<int>> &adjL, map<int, bool> &visited, map<int, bool> &dfs_visited, int parent, int node, int &count)
{
    visited[node] = 1;
    dfs_visited[node] = 1;
    for (auto &it : adjL[node])
    {
        if (!visited[it])
        {
            // cout<<" "<<it<<" "<<endl;
            noOfCyclesDFS(adjL, visited, dfs_visited, node, it, count);
        }
        else if (dfs_visited[it])
        {
            // cout<<"$"<<it<<"$"<<endl;
            count++;
        }
    }
    dfs_visited[node] = 0;
}
int isCyclic(map<int, set<int>> &adjL)
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
void TOPO(map<int, set<int>> &adjL, map<int, bool> &visited, stack<int> &s, int node)
{
    visited[node] = 1;
    for (auto &it : adjL[node])
    {
        if (!visited[it])
        {
            // cout<<" "<<it<<" "<<endl;
            TOPO(adjL, visited, s, it);
        }
    }
    s.push(node);
}
//topologicl sort
//tc o(n+e)
//sc o(n) linear
void topo(map<int, set<int>> &adjL)
{
    //yaha bass usne vector<bool> visited use kiya kaise?
    map<int, bool> visited;
    stack<int> s;
    for (auto &it : adjL)
    {
        if (!visited[it.first])
        {
            TOPO(adjL, visited, s, it.first);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for (auto &it : ans)
        cout << it << " ";
}
vector<int> TOPOSORT(map<int, set<int>> &adjL)
{
    // indegrees
    map<int, int> indegree;
    for (auto &it : adjL)
    {
        for (auto &it2 : it.second)
            indegree[it2]++;
    }

    // indergree 0
    queue<int> q;
    for (auto &it : adjL)
    {
        if (indegree[it.first] == 0)
            q.push(it.first);
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto &it : adjL[front])
        {

            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
bool DetectCycle(map<int, set<int>> &adjL)
{
    // indegrees
    map<int, int> indegree;
    for (auto &it : adjL)
    {
        for (auto &it2 : it.second)
            indegree[it2]++;
    }

    // indergree 0
    queue<int> q;
    for (auto &it : adjL)
    {
        if (indegree[it.first] == 0)
            q.push(it.first);
    }

    // do bfs
    int cnt=0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;
        for (auto &it : adjL[front])
        {

            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if(cnt==adjL.size())
    return false;
    else
    return true;
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
void DDFFSS(int node,map<int,bool> &vis,stack<int> &st,map<int,set<int>> &adjL)
{
    vis[node]=true;
    for(auto nbr:adjL[node])
    {
        if(!vis[nbr])
        DDFFSS(nbr,vis,st,adjL);
    }
    //topo
    st.push(node);
}
void revdfs(int node,map<int,bool> &vis,map<int,set<int>> &adjL)
{
    vis[node]=1;
    for(auto &nbr:adjL[node])
    {
        if(!vis[nbr])
        revdfs(nbr,vis,adjL);
    }
}
int StronglyConnected(int v, map<int, set<int>> &adjL)
{
    //topo sort
    stack<int> st;
    map<int,bool> vis;
    for(auto &it:adjL)
    {
        if(!vis[it.first])
        DDFFSS(it.first,vis,st,adjL);
    }

    //create a transpose graph
    map<int,set<int>> transpose;
    for(auto &it:adjL)
    {
        //vis[it.first];
        for(auto &it2:adjL[it.first])
        transpose[it2].insert(it.first);
    }

    // Reset the visited map
    for (auto &it : vis) {
        vis[it.first] = false;
    }

    //dfs call 
    int count=0;
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        if(!vis[top])
        {
            count++;
            revdfs(top,vis,transpose);
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    int edges;
    cin >> edges;
    map<int, set<int>> adjL = prepAdjl(edges);
    // printAdjl(adjL);
    // int DAG=isCyclic(adjL);
    // if(DAG==0)
    // {
    // topo(adjL);
    // vector<int> ans=TOPOSORT(adjL);
    // cout<<endl;
    // for(auto &it:ans)
    // cout<<it<<"->";
    // }
    //  bool dag=DetectCycle(adjL);
    //  cout<<endl<<"Cycle presence "<<dag<<endl;
    //   vector<vector<int>> bridge=findBridges(adjL,n,edges);
    // for(auto &it:bridge)
    // {
    //     for(auto &it2:it)
    //     cout<<it2<<" ";
    //     cout<<endl;
    // }
    int strong=StronglyConnected(n,adjL);
    cout<<endl<<strong<<endl;
}