#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v,int to_find)
{
    int low=0,hi=v.size()-1;
    int mid;
     while(hi-low>1)
    {
        int mid=(hi-low)/2+low;
        if(v[mid]<to_find)
        low=mid+1;
        else
        hi=mid;
    }
    if(v[low]>=to_find)
    return low;
    else if(v[hi]>=to_find)
    return hi;
    else
    return -1;
}
int upper_bound(vector<int> &v,int to_find)
{
    int low=0,hi=v.size()-1;
    int mid;
     while(hi-low>1)
    {
        int mid=(hi-low)/2+low;
        if(v[mid]<=to_find)
        low=mid+1;
        else
        hi=mid;
    }
    if(v[low]>to_find)
    return low;
    else if(v[hi]>to_find)
    return hi;
    else
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int to_find;
    cin>>to_find;
    int lb=lower_bound(v,to_find);
    if(lb!=-1)
    cout<<lb<<" "<<v[lb]<<endl;
    else
    cout<<"Not found"<<endl;
    lb=upper_bound(v,to_find);
    if(lb!=-1)
    cout<<lb<<" "<<v[lb]<<endl;
    else
    cout<<"Not found"<<endl;
}