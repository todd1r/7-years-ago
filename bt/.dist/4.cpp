#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node * buildtree(node* root)
{
    cout<<"Enter the data or press -1 to exit"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;
    cout<<"Enter data for inserting in left"<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right"<<endl;
    root->right=buildtree(root->right);
    return root;
}
void solve(node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
    void solve(node* root,int sum,int &maxSum,int len,int &maxlen)
    {
        if(root==NULL)
        {
        if(len>maxlen)
        {
            maxlen=len;
            maxSum=sum;
        }
        else if(len==maxlen)
        maxSum=max(sum,maxSum);
        return ;
        }
        sum+=root->data;
        solve(root->left,sum,maxSum,len+1,maxlen);
        solve(root->right,sum,maxSum,len+1,maxlen);
    }
    int sumOfLongRootToLeafPath(node* root)
    {
        int len=0;
        int maxlen=0;
        int sum=0;
        int maxSum=INT_MIN;
        solve(root,sum,maxSum,len,maxlen);
        return maxSum;
    }
    node* lca(node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2) 
        {
            return root;
        }
        
        node* leftAns = lca(root->left, n1, n2);
        node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) 
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
    node* solve4(node* root, int &k, int n) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == n) 
    {
        return root;
    }
    
    node* leftAns = solve4(root->left, k, n);
    node* rightAns = solve4(root->right, k, n);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(node *root, int k, int n)
{
    node* ans = solve4(root, k, n);
    if(ans == NULL || ans->data == n)
        return -1;
    else
        return ans->data;
}
pair<int,int> solve(node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int getMaxSum(node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
    int main()
{
    node* root=buildtree(root);
   int sum=sumOfLongRootToLeafPath(root);
   cout<<sum<<endl;
   node* LCA=lca(root,2,5);
   cout<<LCA->data<<endl;
   int SUMk=sumK(root,9);
   cout<<SUMk<<endl;
   int kAncestor=kthAncestor(root, 1, 3);
   cout<<kAncestor<<endl;
   int nonAdja=getMaxSum(root);
   cout<<nonAdja<<endl;

}