#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     //x^x=0
//     //x^0=x;
//     //x^y^z=y^x^z=x^z^y
//     // xor is associative
//     int a=4,b=6;
//     a=a^b;
//     b=b^a;//b=b^(a^b)==b^b^a=0^a
//     a=a^b;//a=(a^b)^a=b^a^a=b^0=b

// }


//Given an array a of n integers. All integers are present in event count except one.
    //Find that one integer which has odd count in O(N) T.C. and O(1) space;
    //N<10^5
    //a[i]<10^5


    int main()
    {
        int n;
        cin>>n;
        int x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            ans^=x;
        }
        cout<<ans<<endl;
    }