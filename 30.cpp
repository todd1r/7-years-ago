#include <bits/stdc++.h>
using namespace std;
// void printVec(vector<pair<int,int>> &v)
// {
//     for(int i=0;i<v.size();i++)
//     cout<<v[i].first<<" "<<v[i].second<<"\n";
//     cout<<"\n";
// }
// int main()
// {
    // vector<pair<int,int>> v={{1,11},{2,22},{3,33}};
    // printVec(v);

//     vector<pair<int,int>> v;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         // v[i].first.push_back(x);//gives error
//         //v.push_back(make_pair(x,y));
//         v.push_back({x,y});
//     }
//     printVec(v);
// }

//vector of arrays
//this is wrong code 
// void printVec(vector<int[5]> &v)
// {
//    for(int i=0;i<v.size();i++)
//    {
//     cout<<v[i]<<" ";
//    }
// }
// int main()
// {
// vector<int[5]> vectorOfArrays;

//     // Adding arrays to the vector
//     int arr1[5] = {1, 2, 3, 4, 5};
//     int arr2[5] = {6, 7, 8, 9, 10};

//     vectorOfArrays.push_back(arr1);
//     vectorOfArrays.push_back(arr2);
//     printVec(vectorOfArrays);
// }

//right code by chatgpt
// #include <iostream>
// #include <array>
// #include <vector>

// using namespace std;

// void printVec(vector<array<int, 5>> &v) {
//     for (const auto &arr : v) {
//         for (int element : arr) {
//             cout << element << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     vector<array<int, 5>> vectorOfArrays;

//     // Adding arrays to the vector
//     array<int, 5> arr1 = {1, 2, 3, 4, 5};
//     array<int, 5> arr2 = {6, 7, 8, 9, 10};

//     vectorOfArrays.push_back(arr1);
//     vectorOfArrays.push_back(arr2);

//     printVec(vectorOfArrays);

//     return 0;
// }


//array of vectors
// void printVec(vector<int> &v)
// {
//     cout<<v.size()<<"\n";
//     for(int i=0;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<"\n";
// }
// int main()
// {
//     int N;
//     cin>>N;
//     vector<int> v[N];
//     for(int i=0;i<N;i++)
//     {
//         int n;
//         cin>>n;
//         for(int j=0;j<n;j++)
//         {
//             int x;
//             cin>>x;
//             v[i].push_back(x);
            
//         }
//     }
//     for(int i=0;i<N;i++)
//         printVec(v[i]);
// }



//vector of vectors
//  void printVec(vector<int> &v)
// {
//     cout<<v.size()<<"\n";
//     for(int i=0;i<v.size();i++)
//     cout<<v[i]<<" ";
//     cout<<"\n";
// }
// int main()
// {
//     int N;
//     cin>>N;
//     vector<vector<int>> v;
//     for(int i=0;i<N;i++)
//     {
//         int n;
//         cin>>n;
//         vector<int> temp;
//         for(int j=0;j<n;j++)
//         {
//             int x;
//             cin>>x;
//             temp.push_back(x);
            
//         }
//         v.push_back(temp);
//     }
//v[i] can now be considered as a vector and do the operations as we do on a vector
//     v[0].push_back(10);
//     v.push_back(vector<int> ());
//     for(int i=0;i<v.size();i++)
//         printVec(v[i]);
// }

//if u don't want to use temp then
 void printVec(vector<int> &v)
{
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<"\n";
}
int main()
{
    int N;
    cin>>N;
    vector<vector<int>> v;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        v.push_back(vector<int> ());
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
            
        }
    }
    v[0].push_back(10);
    v.push_back(vector<int> ());
    for(int i=0;i<v.size();i++)
        printVec(v[i]);
}