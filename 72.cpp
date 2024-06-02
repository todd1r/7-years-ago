//take nos from 2 to 30 then consider all prime 2 is prime now cancel all mutiples of 2 then 3 ...
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool> isPrime(N,1);
int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=2*i;j<N;j+=i)//no increment of j
            isPrime[j]=false;
        }
    }

    //dono jagah i*i daal sakte hai 2*i ki jagah but usme kuch condi. hoti hai
    //inner loop n/2+n/3+n/5+n/7....
    //tc o(nloglog(n))
for(int i=1;i<100;i++)
cout<<isPrime[i]<<endl;
int q;
cin>>q;
while(q--)
{
    int num;
    cin>>num;
    if(isPrime[num])
    cout<<"prime\n";
    else
    cout<<"not prime";
}
// tc O(Q)
}