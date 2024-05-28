#include <bits/stdc++.h>
using namespace std;
vector<int> NGE(vector <int> v)
{
    stack <int> s;
    // multiset<pair<int,int>>;
    vector <int> vv(v.size());
    for(int i=0;i<v.size();i++)
    {
    while(!s.empty()&&v[i]>v[s.top()])
    {
        vv[s.top()]=i;
        s.pop();
    }
    s.push(i);
    }
    while(!s.empty())
    {
        vv[s.top()]=-1;
        s.pop();
    }
    return vv;
}
int main()
{
    int N;
    cin>>N;
    vector <int> v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
        // int x;
        // cin>>x;
        // v.push_back(x);
    }
    vector <int> nge=NGE(v);
    for(int i=0;i<N;i++)
    cout<<v[i]<<" "<<((nge[i]>-1)?v[nge[i]]:-1)<<endl;
}