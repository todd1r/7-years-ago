//2 sorted arrays ka intersection can be found in O(N) T.C.

//3 people may have 4 types of fruits indexed 0,1,2,3
//1. 2,3 so it's bit mask is 1100
//2. 0,1,2 so it's bit mask is 0111
//3. 1,3 so it's bit mask is 1010
//now u can take & and find the common fruits

//unsigned long long mein 64 bits hoti hai
//11:31 vedio mein se question dekh lo
//brute force

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> days[n];
//     for(int i=0;i<n;i++)
//     {
//         int num_workers;
//         cin>>num_workers;
//         for(int j=0;j<num_workers;j++)
//         {
//             int day;
//             cin>>day;
//             days[i].push_back(day);
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             //O(N^2*30)
//         }
//     }
// }



//bitmask
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> masks(n,0);
    for(int i=0;i<n;i++)
    {
        int num_workers;
        cin>>num_workers;
        int mask=0;
        for(int j=0;j<num_workers;j++)
        {
            int day;
            cin>>day;
            mask=(mask|(1<<day));
        }
        masks[i]=mask;
    }
    int max_days=0;
    int person1=-1;
    int person2=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //O(N^2*30)
            int intersection=(masks[i],masks[j]);//O(n)
            int common_days=__builtin_popcount(intersection);//O(n)
           if(max_days<common_days)
           {
            max_days=common_days;
            person1=i;
            person2=j;
           }
        }
    }
    cout<<person1<<" "<<person2<<" "<<endl;
}
//O(N^2)