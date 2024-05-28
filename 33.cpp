#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     map<int,string> m;
//     m[2]="abc";
//     m[5]="efg";
//     m[1]="hij";
//     m.insert(make_pair(7,"tbc"));
//     m.insert({9,"itr"});
    // map<int,string> ::iterator it=m.begin();
    // for(it;it!=m.end();it++)
    // cout<<(*it).first<<" "<<it->second<<endl;

//better
//     for(auto val:m)
//     cout<<val.first<<" "<<val.second<<endl;

 //best
//     for(auto &val:m)
//     cout<<val.first<<" "<<val.second<<endl;
// }


// void print(auto &m)
// {
//     cout<<m.size()<<endl;
//     for(auto &val:m)
//     cout<<(val).first<<" "<<val.second<<endl;
// }

// int main()
// {
//     map<int,string> m;
//     m[2]="abc";//o(log(n)) n is size of map
//     m[5]="efg";
//     m[1]="hij";
//     m.insert(make_pair(7,"tbc"));
//     m.insert({9,"itr"});
//     print(m);
// }


//map stores unique elements so when declaring same key, value is overritten




// void print(auto &m)
// {
//     cout<<m.size()<<endl;
//     for(auto &val:m)//o(nlog(n)) since accessing also take o(log(n)) tc same as insertion takes
//     cout<<(val).first<<" "<<val.second<<endl;
// }

// int main()
// {
//     map<int,string> m;
//     m[2]="abc";//o(log(n)) n is size of map
//     m[5]="efg";
//     m[1]="hij";
//     m.insert(make_pair(7,"tbc"));
//     m.insert({9,"itr"});

    //find() func.
    // auto it=m.find(7);
    // if(it==m.end())
    // cout<<"NO VALUE"<<endl;
    // else
    // cout<<(*it).first<<" "<<it->second<<endl;

    //erase() func.
    //two ways to pass either key or value to erase
//m.erase("abc");
//     m.erase(7);
//     auto it=m.find(5);
//     if(it!=m.end())
//     m.erase(it);
//     print(m);
// }


//here the T.C. is not  o(log(n)) since  internally strings are compared and then stored in lexicogr. order
//map<string,string> m;
//m["abc"]="abc";//s.size()*log(n) s is size of string in key


int main()
{
    map<string,int> m;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        m[s]=m[s]+1;
        //or 
        //m[s]++;
    }
    for(auto val:m)
    cout<<val.first<<" "<<val.second<<endl;
}