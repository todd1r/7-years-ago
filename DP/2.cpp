// #include<bits/stdc++.h>
// using namespace std;
// #define MOD 1e9+7
// int count(long long nstairs,int i)
// {
//     //base case
//     if(nstairs<i)
//     return 0;
//     if(nstairs==i)
//     return 1;
//     //recu case
//     return (count(nstairs,i+1)+count(nstairs,i+2))%MOD;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     long long nstairs[n];
//     int ans=count(nstairs,0);
//     cout<<ans<<" ";
// }


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(long long n, int i) {
    // base case
    if (n < i)
        return 0;
    if (n == i)
        return 1;
    // recursive case
    return (countWays(n, i + 1) % MOD + countWays(n, i + 2) % MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    int ans = countWays(n, 0);
    cout << ans << " ";
    return 0;
}
