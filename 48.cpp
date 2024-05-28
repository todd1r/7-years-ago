#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> allSubsets;
void generate(vector<int> &subset,int i,vector<int> &nums)
{
    if(i==nums.size())
    {
    allSubsets.push_back(subset);
    return;
    }
    generate(subset,i+1,nums);
    subset.push_back(nums[i]);
     generate(subset,i+1,nums);
      subset.pop_back();
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    vector<int> empty;
    generate(empty,0,nums);
    for(auto subset:allSubsets)
    {
        for(auto ele:subset)
        cout<<ele<<" ";
        cout<<endl;
    }

}
//no of func. calls is o(n^2)
// tc of 1 func. call is o(1)