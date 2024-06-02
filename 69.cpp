#include<bits/stdc++.h>
using namespace std;
//const int M=1e9+7;
//b<=10^18 or anything then it will work but b=64^32 this will give problem
// int binExpIter(int a,int b,int m)
// {
//     int ans=1;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=(ans*1LL*a)%m;
//         }
//         a=(a*1LL*a)%m;
//         b>>=1;
//     }
//     return ans;
// }
// int main()
// {
//     //int a=2, b=3;
//     cout<<binExpIter(50,binExp(64,32,M-1),M)<<endl;
// }



//leetcode ques.
int binExpIter(int a,int b,int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}
int main()
{
    //int a=2, b=3;
    int M=1440;
    int a;
    cin>>a;
    int b=0;
    for(int i=0;i<n;i++)
    {
    b+=binExp(arr[n-i-1],(int)pow(10,i),M-1)
    }
    cout<<50,binExp(a,b,1337)<<endl;
}