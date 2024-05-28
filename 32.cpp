#include <bits/stdc++.h>
using namespace std;
int main()
{
//     vector <int> v={1,2,3,4,5};
//     for(int i=0;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<endl;
//     vector <int> ::iterator it=v.begin();
//     for(it;it!=v.end();it++)
//     cout<<*it<<" ";
//     cout<<endl;

//     //range based loops
//     for(int value : v)
//     cout<<value<<" ";
//     cout<<endl;

//     //here copy is passed 
//     //ex
// for(int value : v)
//    value++;

//     for(int value : v)
//     cout<<value<<" ";
//     cout<<endl;

// for(int &value : v)
//    value++;

//     for(int &value : v)
//     cout<<value<<" ";
//     cout<<endl;


// vector<pair<int,int>> v={{1,2},{2,3},{3,4}};
// for(pair<int,int> val: v)
// cout<<val.first<< " " <<val.second<< endl;

// auto a=1.2;
// cout<<a<<endl;


//  vector <int> v={1,2,3,4,5};
//     for(auto it=v.begin();it!=v.end();it++)
//     cout<<*it<<" ";

    vector<pair<int,int>> v={{1,2},{2,3},{3,4}};
for(auto val: v)
cout<<(val).first<< " " <<(val).second<< endl;
}