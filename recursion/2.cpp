#include<bits/stdc++.h>
using namespace std;
long long count(long long nstairs)
{
    //base case
    if(nstairs<0)
    return 0;
    if(nstairs==0)
    return 1;
    //recu case
    long long ans=count(nstairs-1)+count(nstairs-2);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    long long ans=count(n);
    cout<<ans<<" ";
}