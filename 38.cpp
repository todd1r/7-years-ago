#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     while (!s.empty())
//     {
//         cout << s.top() << endl;
//         s.pop();
//     }
// }
//recursion is done using stack

int main()
{
    queue<string> q;
    q.push("anjali");
    q.push("garima");
    q.push("savita");
     q.push("govind");
      q.push("jaiswal");
      while(!q.empty())
      {
        cout<<q.front()<<endl;
        q.pop();
              }
}