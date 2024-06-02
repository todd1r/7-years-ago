//take nos from 2 to 30 then consider all prime 2 is prime now cancel all mutiples of 2 then 3 ...
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0),hp(N,0);
vector<int> divisors[N];
int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++)
    {
        if(isPrime[i]==true)
        {
            lp[i]=hp[i]=i;//prime no ka low aur high wahi hoga
            for(int j=2*i;j<N;j+=i)
            {
            isPrime[j]=false;
            hp[j]=i;
            if(lp[j]==0)
            lp[j]=i;
            }
        }
    }
    int num;
cin>>num;
vector<int> prime_factors;
//to store count of a prime factor
map<int,int> count_prime_factors;
while(num>1)
{
    int prime_factor==hp[num];
    while(num%prime_factor==0)
    {
        num/=prime_factor;
        prime_factors.push_back(prime_factor);
        count_prime_factors[prime_factor]++;//log(N) hai tc so u can use unordered maps
    }
}
//O(log(n))

for(int &factor:prime_factors)
cout<<factor<<" ";
cout<<endl;
for(auto &factor:count_prime_factors)
cout<<factor.first<<" "<<factor.second<<" ";


for(int i=2;i<N;i++)
    {
            for(int j=i;j<N;j+=i)
            dicisors[j].push_back(i);
    }
//n/2+n/3+n/4+...
//tc o(nlogn)
for(int i=1;i<10;i++)
{
    for(int div:divisors[i])
    cout<<div<<" ";
    cout<<endl;
}
}