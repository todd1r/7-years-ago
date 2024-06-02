//a*b/(gcd(a,b))=lcm(a,b)
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
    return b;
    //yaha sirf ek call extra hai both can be used
    // if(b==0) 
    // return a;
    return gcd(b,a%b);

}
//tc is log(n)
int main()
{
    cout<<gcd(18,12)<<endl;
     cout<<gcd(12,18)<<endl;
     cout<<"LCM "<<12*18/gcd(12,18)<<endl;
    cout<<__gcd(12,18)<<endl;//o(logN) same tc
    //how to take gcd of 3 nos.
    //__gcd(__gcd(a,b),c)

    // to find min. frac of 2 nos
    //a/b=(a/__gcd(a,b))/(b/__gcd(a,b))
}