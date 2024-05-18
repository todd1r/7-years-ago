// #include<bits/stdc++.h>
// #include<unordered_map>
// #include<list>
// using namespace std;
// class graph{
// public:
// unordered_map<int,list<int>> adj;
// void addEdge(int u,int v,bool direction)
// {
//     //dire. =0-> undirec.
//     //dire. =1->direc.

//     //create an edge from u to v
//     adj[u].push_back(v);
//     if(direction==0)
//     {
//         adj[v].push_back(u);
//     }
// }
// void printAdjList(){
//     for(auto i:adj){
//         cout<<i.first<<"->";
//         for(auto j:i.second){
//         cout<<j<<",";
//         }
//     cout<<endl;
//     }
// }
// };
// int main()
// {
//     int n;
//     cout<<"Enter the no of nodes"<<endl;
//     cin>>n;
//     int m;
//     cout<<"Enter th no of edges"<<endl;
//     cin>>m;
//     graph g;
//     for(int i=0;i<m;i++)
//     {
//         int v,u;
//         cin>>u>>v;
//         g.addEdge(u,v,0);
//     }
//     g.printAdjList();
//     return 0;
// }




#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class graph{
public:
unordered_map<T,list<T>> adj;
void addEdge(T u,T v,bool direction)
{
    //dire. =0-> undirec.
    //dire. =1->direc.

    //create an edge from u to v
    adj[u].push_back(v);
    if(direction==0)
    {
        adj[v].push_back(u);
    }
}
void printAdjList(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
        cout<<j<<",";
        }
    cout<<endl;
    }
}
};
int main()
{
    int n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter th no of edges"<<endl;
    cin>>m;
    graph<int> g;
    //graph<char> g;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();
    return 0;
}


vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++)
    {
        adj[i].push_back(i);
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
