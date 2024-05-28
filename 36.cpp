#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    multiset<long long> m;
    int N;
    cin>>N;
    int k;
    cin>>k;
    while(N--)
    {
        long long n;
        cin>>n;
        m.insert(n);
    }
    long long sum=0;
    while(k--)
    {
        auto it=m.end();
        it--;
        sum+=(*it);
        m.insert((*it)/2);
        m.erase(it);//rem iterator se hi erase karna hai
        //erase is o(1) when iterator is provided and o(log(n)) when value is provied
    }
cout<<sum<<endl;
    }
}
