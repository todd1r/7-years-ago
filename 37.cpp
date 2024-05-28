#include <bits/stdc++.h>
using namespace std;
// int main()
// {
    //     map<set<int>,int> m;
    //     set<int> s1={1,2,3};
    //     set<int> s2={2,3};
    //     cout<<(s1<s2);
//     map<pair<string, string>, vector<int>> m;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         string fn, ln;
//         int ct;
//         cin >> fn >> ln >> ct;
//         while (ct--)
//         {
//             int x;
//             cin >> x;
//             m[{fn, ln}].push_back(x);
//         }
//     }
//     for (auto &val : m)
//     {
//         cout << val.first.first << " " << val.first.second << " " << endl;
//         cout << val.second.size() << endl;
//         for( auto ele:val.second)
//         cout<<ele<<" ";
//     }
// }



// int main()
// {
//     map<int,multiset<string>> m;
//     int N;
//     cin>>N;
//     while(N--)
//     {
//         string s;
//         cin>>s;
//         int marks;
//         cin>>marks;
//         m[marks].insert(s);
//     }
//     auto it=--m.end();
//     while(true)
//     {
//         for(auto val:(*it).second)
//         cout<<val<<" "<<(*it).first<<endl;
//         if (it==m.begin())
//         break;
//         else
//         it--;
//     }
// }



int main()
{
    map<int,multiset<string>> m;
    int N;
    cin>>N;
    while(N--)
    {
        string s;
        cin>>s;
        int marks;
        cin>>marks;
        m[-1*marks].insert(s);
    }
    
        for(auto val:m)
        {

        for(auto v:val.second)
        cout<<v<<" "<<val.first<<endl;
        }
}