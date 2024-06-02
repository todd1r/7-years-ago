#include<bits/stdc++.h>
using namespace std;
int count(vector<int> &v,int n)
{
    //base case
    if(v.size()==1)
    return v[0]<n;
    
    //recu case
    int ans=count(nstairs-1);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int ans=count(arr,arr[n-1]);
    cout<<ans<<" ";
}