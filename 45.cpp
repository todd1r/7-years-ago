#include<bits/stdc++.h>
using namespace std;
bool is_positive(int x)
{
return (x>0);
}
int main()
{
   // [](int x){return x+2;};//lambda func.
//    cout<< [](int x){return x+2;}(2);
auto y= [](int x){return x+2;}(2);
cout<<y<<endl;
auto z= [](int x,int y){return x+y;}(2,4);
cout<<z<<endl;


vector<int> v={2,3,4};
cout<<all_of(v.begin(),v.end(),
[](int x){return x>0;})<<endl;

//is_positive ki jagah use this 

// cout<<all_of(v.begin(),v.end(),
// is_positive);



cout<<any_of(v.begin(),v.end(),
[](int x){return x>0;})<<endl;
cout<<any_of(v.begin(),v.end(),
[](int x){return x>0;})<<endl;
}


//if u have to update a vector or array then it's called online query otherwise offline query