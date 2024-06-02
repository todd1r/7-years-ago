#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ct=0;
    int sum=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" "<<n/i<<endl;
            ct+=1;
            sum+=i;
            if(n/i!=i)
            {
                sum+=n/i;
                ct+=1;
            }
        }
    }
    cout<<ct<<" "<<sum<<endl;
    //O(srqt(N))
}
//x=p1^n1*p2^n2*p3^n3...  where p1,p2,p3 are prime factors
//then no of divisors = (n1+1)(n2+1)(n3+1)...
//sum of divisors=(1+p1+p1^2+....)(1+p2+p2^2+....)(1+p3+p3^2+....)=gp ka formula
//((p1^(n1+1)-1)/(p1-1))*((p2^(n2+1)-1)/(p2-1))... 