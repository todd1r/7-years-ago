//top down -> recursion + memoization
//bottom up -> tabulation
#include<bits/stdc++.h>
using namespace std;
int fibo(vector<int> &dp,int n)
{
    //base case
    if(n<=1)
    return n;
    
     if(dp[n]!=-1)
     return dp[n];

    //recu case
    dp[n]=fibo(dp,n-1)+fibo(dp,n-2);
    return dp[n];
}
//tc  and sc o(n) in both top to dowm and bottom to up
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> v(n+1,-1);
//     int ans=fibo(v,n);
//     cout<<ans<<" ";
// }


//bottom up
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     dp[i]=dp[i-1]+dp[i-2];
//     cout<<dp[n]<<" ";
// }



//space optimization
int main()
{
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
    if(n==0)
    return prev2;
    for(int i=2;i<=n;i++)
    {
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<" ";
}