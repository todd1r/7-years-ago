//arrays and vectors need to be in sorted order to work in log n otherwise it will work in o(n)
//lower bound either finds the requested element or the element upper than it but upper bound only finds the element 
//bigger then it
//in lower bound the no is included but in upper bound even if 2 five is present it will give bigger value 
//and both give pointer to next element

// if a

//no bigger then the largest no is given

//both the func return location in arrays pointers and in vectors iterator


#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    //     sort(a,a+n);
    // for (int i = 0; i < n; i++)
    //     cout << a[i]<<" ";
    // cout << endl;
    // //works in log(N)
    // //int *ptr=upper_bound(a,a+n,5);
    // int *ptr=upper_bound(a+4,a+n,5);
    // if(ptr==(a+n))
    // {
    //     cout<<"Not found";
    //     return 0;
    // }
    // cout<<(*ptr)<<endl;


    //incase of vectors
    // int m;
    // cin >> m;
    // vector<int> v(m);
    // for (int i = 0; i < m; i++)
    //     cin >> v[i];
    //     sort(v.begin(),v.end());
    // for (int i = 0; i < m; i++)
    //     cout << v[i]<<" ";
    // cout << endl;
    // //works in log(N)
    // //int *ptr=upper_bound(v.begin(),v.end());
    // auto ptr=upper_bound(v.begin(),v.end(),5);
    // if(ptr==v.end())
    // {
    //     cout<<"Not found";
    // }
    // else
    // cout<<(*ptr)<<endl;



    //incase of map and set o(n) is tc is you use the traditional syntax auto ptr=upper_bound(v.begin(),v.end(),5);

   int m;
    cin >> m;
    set<int> v;
    for (int i = 0; i < m; i++)
        {
            int x;
            cin>>x;
            v.insert(x);
        }
        //amp and set is already sorted
    

    //works in log(N)
    auto ptr=v.upper_bound(5);
    if(ptr==v.end())
    {
        cout<<"Not found";
    }
    else
    cout<<(*ptr)<<endl;

    //map mein sirf key ke upr hi lower bound lagta hai
}