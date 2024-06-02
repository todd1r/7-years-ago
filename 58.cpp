#include<bits/stdc++.h>
using namespace std;
int main()
{
    //1<<n=2^n
    int a=1<<32-1;
    cout<<a<<endl;//this will give error since 1<<32 is out of range of int so write
    int aa=1LL<<32-1;
    cout<<a<<endl;//but again it will not be able to store this as int is signed
    int b=1<<31-1;
    cout<<b<<endl;
    unsigned int b=(1LL<<32)-1;
    cout<<b<<endl;
}