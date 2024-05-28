//maps mein se value wala part hata do then we get keys that is set
#include <bits/stdc++.h>
using namespace std;
// void print(auto &um)
// {
//     //better
//     for(auto &val:um)
//     cout<<val<<endl;
//     auto it=um.begin();
//     // for(it;it!=um.end();it++)
//     // cout<<*it<<endl;
// }
// int main()
// {
//     set<string> s;
//     //T.C. of insertion and accessing is log(n) same as maps
//     s.insert("garima");
//     s.insert("jaiswal");
//     s.insert("garima");
//     s.insert("jaiswal");
//     s.insert("anjali");//log(n)
//     //in maps we could use [ ] or find() but here only find()
//     auto it=s.find("garima");//o(log(n))
    
//     s.erase("jaiswal");
//     //or
//     // auto it=s.find("jaiswal");
//     // s.erase(it);
//     print(s);
// }


// int main()
// {
//     set<string> ss;
//     int N;
//     cin>>N;
//     while(N--)
//     {
//         string s;
//         cin>>s;
//         ss.insert(s);
//     }
//     for(auto &val:ss)
//     cout<<val<<endl;
// }



//unordered set
// void print(auto &um)
// {
//     //better
//     for(auto &val:um)
//     cout<<val<<endl;
//     auto it=um.begin();
//     // for(it;it!=um.end();it++)
//     // cout<<*it<<endl;
// }
// int main()
// {
//     unordered_set<string> s;
//     //T.C. of insertion and accessing is log(n) same as maps
//     s.insert("garima");
//     s.insert("jaiswal");
//     s.insert("garima");
//     s.insert("jaiswal");
//     s.insert("anjali");//log(n)
//     //in maps we could use [ ] or find() but here only find()
//     auto it=s.find("garima");//o(log(n))
    
//     s.erase("jaiswal");
//     //or
//     // auto it=s.find("jaiswal");
//     // s.erase(it);
//     print(s);
// }


//again unordered mein kisi bhi order mein print kar sakta hai 
//unordered set is implemented using hash table so we can’t have complex data structure

// int main()
// {
//     unordered_set<string> ss;
//     int N;
//     cin>>N;
//     while(N--)
//     {
//         string s;
//         cin>>s;
//         ss.insert(s);
//     }
//     int Q;
//     cin>>Q;
//     while(Q--)
//     {
//         string s;
//         cin>>s;
//         auto it=ss.find(s);
//         if(it==ss.end())
//         cout<<"NO"<<endl;
//         else
//         cout<<"YES"<<endl;
//     }
    // for(auto &val:ss)
    // cout<<val<<endl;
// }



//multiset
void print(auto &um)
{
    //better
    for(auto &val:um)
    cout<<val<<endl;
    auto it=um.begin();
    // for(it;it!=um.end();it++)
    // cout<<*it<<endl;
}
int main()
{
    multiset<string> s;
    //T.C. of insertion and accessing is log(n) same as multimaps
    s.insert("garima");
    s.insert("jaiswal");
    s.insert("garima");
    s.insert("jaiswal");
    s.insert("anjali");//log(n)
    //in maps we could use [ ] or find() but here only find()
    // auto it=s.find("garima");//o(log(n))
    
    // s.erase("jaiswal");
    //or
    // auto it=s.find("jaiswal");
    // s.erase(it);
    print(s);
}

//find() func. returns the iterator of first occurrence of key so when we pass this iterator to s.erase only one ele. is deleted 
//but if directly pass the key to erase then it will delte all occur.
//erase bhi iterator hi find karta hai but voh saare iterator find kar leta hai







