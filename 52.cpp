#include<bits/stdc++.h>
using namespace std;
//if we want accuracy upto 5 decimal places
double eps=1e-6;

double multiply(double mid,int n)
{
    double ans=1;
    for(int i=0;i<n;i++)
    ans*=mid;
    return ans;
}

int main()
{
    double x;
    cin>>x;
    int n;
    cin>>n;
    double lo=1,hi=x,mid;
    while(hi-lo>eps)
    {
        mid=(hi+lo)/2;
        //to find nth root mid * mid n times
        if(multiply(mid,n)<x)
        lo=mid;
        //mid and not mid +1 since we are dealing in decimal
        else
        hi=mid;
    }
    //we can o/p anything lo or hi since same upto 5 decimal places
    cout<<setprecision(8)<<lo<<" "<<hi<<endl;
    cout<<pow(x,1.0/n)<<endl;
}