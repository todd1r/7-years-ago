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
    int low=0,hi=n-1;
    int mid;
    while(hi-low>1)
    {
        int mid=(hi-low)/2+low;
        if(v[mid]<to_find)
        low=mid+1;
        else
        hi=mid;
    }
    if(v[low]==to_find)
    cout<<low<<endl;
    else if(v[hi]==to_find)
    cout<<hi<<endl;
    else
    cout<<"Not Found";
}