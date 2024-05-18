#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> prepareAdjL(int n,int m)
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
    for(auto it:adjL)
    {
        cout<<it.first<<"->";
        for(auto it2:it.second)
        cout<<it2<<" ";
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,set<int>> adjL=prepareAdjL(n,m);
    print(adjL);
}