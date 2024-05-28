#include <bits/stdc++.h>
using namespace std;
// int main()
// {
    //pair

    // pair <int,int> p;
    //  p=make_pair(2,4);
     //p={2,4};
    // pair<int,int> p1=p;
    // p1.first=77;
    // pair<int,int> &p2=p;
    // p2.first=77;
    // cout<<p.first<<" "<<p.second<<"\n";
    // int a[]={1,2,3};
    // int b[]={4,5,6};

    // pair <int ,int> arr[3];
    // arr[0]={1,4};
    // arr[1]={2,5};
    // arr[2]={3,6};
    // for(int i=0;i<3;i++)
    // cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    // swap(arr[0],arr[2]);
    // for(int i=0;i<3;i++)
    // cout<<arr[i].first<<" "<<arr[i].second<<"\n";

    // pair<int, int> arr[3];
    // for (int i = 0; i < 3; i++)
    //     cin >> arr[i].first >> arr[i].second;
    // for (int i = 0; i < 3; i++)
    //     cout << arr[i].first << " " << arr[i].second << "\n";
// }


//vector


// void printVec(vector <int> v)
// {
//     cout<<v.size()<<"\n";//o(1)
//     for(int i=0;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<"\n";
//     v.push_back(55);//not reflected since copy of v is made
// }

// void printVec(vector <int> &v)
// {
//     cout<<v.size()<<"\n";//o(1)
//     for(int i=0;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<"\n";
//     v.push_back(55);// reflected since original v is passed
// }


void printVec(vector <string> &v)
{
    cout<<v.size()<<"\n";//o(1)
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<"\n";
}

int main()
{
    // vector<pair<int,int>> v;
    // vector <int> v;
    // int x;
    // cin>>x;
    // for(int i=0;i<x;i++)
    // {
    //     printVec(v);//o(n)
    //     int n;
    //     cin>>n;
    //     v.push_back(n);
    // }
    // printVec(v);

    // vector <int> v(10);
    // v.push_back(11);//o(1)
    // printVec(v);

    // vector <int> v(10,3);
    // v.pop_back();//o(1)
    //  printVec(v);


    // vector<int> v;
    // v.push_back(4);
    // v.push_back(6);
    // // vector<int> v1=v;//o(n)
    // vector<int> &v1=v;
    // v1.push_back(11);
    //  printVec(v);
    //   printVec(v);
    //    printVec(v1);


    vector<string> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
     printVec(v);
}