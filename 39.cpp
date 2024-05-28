#include <bits/stdc++.h>
using namespace std;
string isBalanced(string &s)
{
    unordered_map<char, int> um = {{'[', -3}, {'{', -2}, {'(', -1}, {')', 1}, {'}', 2}, {']', 3}};
    stack<char> st;
    for(auto val:s)
    {
        if(um[val]<0)
        st.push(val);
        else if((um[val]+um[st.top()])==0)
        st.pop();

    }
if(st.empty())
return "YES";
else
return "NO";
}
int main()
{
    // stack<char> s;
    // int N;
    // cin>>N;
    // if(N%2!=0)
    // {
    //     cout<<"NO"<<endl;
    // }
    // else
    // {
    //     while(N--)
    //     {
    //         char ch;
    //         cin>>ch;
    //         if(ch=='(')
    //         s.push(ch);
    //         else if(ch==')')
    //         s.pop();
    //     }
    //     if(s.empty())
    //     cout<<"YES"<<endl;
    //     else
    //     {
    //     cout<<"NO"<<endl;
    //     cout<<s.top();
    //     }
    // }

    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout<<isBalanced(s)<<endl;
    }
}