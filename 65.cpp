#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int binExpRecu(int a,int b)
{
    if(b==0)
    return 1;
    long res=binExpRecu(a,b/2);
    if(b&1)
    return (a*((res*1LL*res)%M))*M;
    else
    return ((res*1LL*res)%M);
}
int main()
{
    int a=2,b=13;
    cout<<binExpRecu(a,b)<<endl;
    cout<<pow(2,13)<<endl;
}