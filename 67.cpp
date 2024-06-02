#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
//if a is very big suppose 10^18 then just at starting of func write a%=M;
//if a is of type 2^1024 then just at starting of func write a=binExpIter(2,1024);
//(a^b)%M=((a%M)^b)%M

//if M is very large 10^18 then a problem arises i.e. a*a it can exceed range of long long so we use binMul
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
int binMul(int a,int b)
{
    int ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=binMul(ans,a);
        }
        a=binMul(a,a);
        b>>=1;
    }
    return ans;
}
//log^2(N)
int main()
{
    int a=2, b=3;
    cout<<binExpIter(a,b)<<endl;
}