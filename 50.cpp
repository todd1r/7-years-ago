//binary search can be applied on monotonic or predicate function
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int to_find;
    cin>>to_find;
    int lo=0,hi=n-1;
    int mid;
    while(hi-lo>1)
    {
        int mid=(hi-low)/2+low;
        if(v[mid]<to_find)
        lo=mid+1;
        else
        hi=mid;
    }
    if(v[lo]==to_find)
    cout<<lo<<endl;
    else if(v[hi]==to_find)
    cout<<hi<<endl;
    else
    cout<<"Not Found";
}