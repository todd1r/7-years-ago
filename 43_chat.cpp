#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> v(m);
    
    for (int i = 0; i < m; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    
    for (int i = 0; i < m; i++)
        cout << v[i] << " ";
    cout << endl;
    
    // Upper bound finds the first element greater than 5
    auto ptr = upper_bound(v.begin(), v.end(), 5);
    
    if (ptr == v.end()) {
        cout << "Not found" << endl;
    } else {
        cout << (*ptr) << endl;
    }

    return 0;
}
