//topologicl sort
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
       // adjL[v].insert(u);
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
vector<int> topologicalSort(map<int,set<int>> &adjL)
{
    //find all indegree
    map<int,int> indegree;
    for(auto &it:adjL)
        {
            for(auto &it2:it.second)
            indegree[it2]++;
        }
        //o degree wale node ko push kardo
        queue<int> q;
        for(auto &it:adjL)
        {
            if(indegree[it.first]==0)
            q.push(it.first);
        }

        //do bfs
        vector<int> ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            //ans store
            ans.push_back(front);
            //neighbour indegree update
            for(auto neighbour:adjL[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                q.push(neighbour);
            }
        }
        return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepAdjL(m);
    print(adjL);
    vector<int> ans=topologicalSort(adjL);
    for(auto it:ans)
    cout<<it<<" ";
}