//tc o(n+e)
//sc o(n+e) linear

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
vector<int> shortestPath(map<int,set<int>> adjL,int s,int t)
{
    //do bfs
    map<int,bool> visited;
    map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto &i:adjL[front])
        {
            if(!visited[i])
            {
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    //prepare shortest path
    vector<int> ans;
    int currentNode=t;
    ans.push_back(t);
    while(currentNode!=s)
    {
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepAdjL(m);
    print(adjL);
    vector<int> ans=shortestPath(adjL,1,8);
    for(auto &it:ans)
    cout<<it<<" ";
}