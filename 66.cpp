//3^13=3^(1101)=3^(8+4+0+1) tc  is o(b)  where is expo. since b ke binary mein max log(b) bits hi honge
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int binExpIter(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*1LL*a)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}
//b      a      ans=1
//1101   3      1*3
//110    3^2    3
//11     3^4    3*3^4
//1      3^8    3^5*3^8

int main()
{
    int a=2, b=3;
    cout<<binExpIter(a,b)<<endl;
}