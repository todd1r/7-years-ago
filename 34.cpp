#include <bits/stdc++.h>
using namespace std;
// void print(unordered_map<int,string> &m)
// {
//     cout<<m.size()<<endl;
//     for(auto &val:m)
//     {
//         cout<<val.first<<" "<<val.second<<endl;
//     }
// }
// int main()
// {
//     unordered_map<int,string> m;
//     m[5]="anjali";
//     m[7]="garima";
//     m[3]="jaiswal";
//     m[1]="savita";
//     m[5]="jai";
//     print(m);
// }

// int main()
// {
//     unordered_map<pair<int,int>,string> um;
// }
//pair ka inbuilt hash func. defined nahi hota hai isiliye we can’t use it with unordered maps since unor. maps uses hash table
//containers ka inbuilt hash func nahi hota toh sirf basic datat types like string ,long long par hi unor. maps kaam karta hai
//rem. sirf keys par limitation hai value par nahi****


int main()
{
    int N;
    cin>>N;
    unordered_map<string,int> um;
    while(N--)
    {
      string s;
      cin>>s;
      um[s]=um[s]+1;
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        string s;//Q*s is T.C.
        cin>>s;
        // auto it=um.find(s);
        // if(it==um.end())
        // cout<<"-1"<<endl;
        // else
        // cout<<it->second<<endl;

        //or
        cout<<um[s]<<endl;
    }
}