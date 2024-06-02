#include<bits/stdc++.h>
using namespace std;
void printBinary(int num)
{
    for(int i=10;i>=0;i--)
    cout<<((num>>i)&1);//cct+= ((num>>i)&1);
    cout<<endl;
}
int main()
{
    printBinary(9);
    int a=9;
    int i=3;
    if((a&(1<<i))!=0)
    cout<<"set bit"<<endl;
    else
    cout<<"unset bit"<<endl;
    // printBinary(a|(1<<1));
    // printBinary(~a);
    // printBinary(a&(~(1<<3)));

    //set a bit
    printBinary(a|(1<<i));
    //how to unset a bit
    printBinary(a&(~(1<<i)));

    //toggle
    printBinary(a^(1<<3));

    int ct=0;
    for(int i=31;i>=0;i--)
    {
        if(a&(1<<i)!=0)
        ct++;
    }
    cout<<ct<<endl;

    cout<<__builtin_popcount(a);//it works only for int so 1ll<<35 won't work so use
    cout<<__builtin_popcountll(a); 
}