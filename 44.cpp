#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int min=*(min_element(v.begin()+2,v.end()));
    cout<<min<<endl;
    int max=*(max_element(v.begin(),v.end()));
    cout<<max<<endl;
    int sum=(accumulate(v.begin(),v.end(),0));
    cout<<sum<<endl;
    int cnt=(count(v.begin(),v.end(),4));
    cout<<cnt<<endl;
    auto it=(find(v.begin(),v.end(),4));
    if(it!=v.end())
    cout<<*it<<endl;
    else
    cout<<"Element not found\n";
    reverse(v.begin()+2,v.end());
    for(auto val:v)
    cout<<val<<" ";
    cout<<endl;
    string s="abcd";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    //o(n) for vector and array and o(log(n)) for maps and sets
    //for array just replace v.begin by v and v.end() by v+n
}