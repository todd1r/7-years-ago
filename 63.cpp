//let an array have 2,4,5 eles (sorted hona chahiye)
//no of subsets is 2^n=8
//000->[]
//001->[2]
//010->[4]
//011->[2,4]
//100->[5]
//101->[2,5]
//110->[4,5]
//111->[2,4,5]
//print all possible subsets with dup.
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int> &nums)
{
    int n=nums.size();
    int subset_ct=(1<<n);
    vector<vector<int>> subsets;
    for(int mask=0;mask<subset_ct;mask++)
    {
        vector<int> subset;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))!=0)
            subset.push_back(nums[i]);
        }
        subsets.push_back(subset);
    }
    //O((2^n)*n)
    return subsets;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    auto all_subsets=subsets(v);
    for(auto subset:all_subsets)
    {
        for(int ele:subset)
        cout<<ele<<" ";
        cout<<endl;
    }
}