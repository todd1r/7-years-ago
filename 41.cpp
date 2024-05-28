#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin>>n;
    // int v[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>v[i];
    // }
    // sort(v,v+n);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<v[i]<<" ";
    // }
     int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    // sort(v.begin()+2,v.end());
    // sort(v.begin(),v.end()-2);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}
//wrost T.C. is nlog(n)