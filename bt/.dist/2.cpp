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
 int height(struct node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) +1;
        return ans;
        
    }
    //diameter means longest path
    // int diameter(struct node* root)
    // {
    //     if(root==NULL)
    //     return 0;
    //     int op1=diameter(root->left);
    //     int op2=diameter(root->right);
    //     int op3=height(root->left)+height(root->right)+1;
    //     int ans=max(op1,max(op2,op3));
    //     return ans;
    // }
    pair<int,int> diameterFast(struct node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        //first denotes dia. and second denotes height
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(struct node* root) {
    
        return diameterFast(root).first;
    }   
    // bool isBalanced(struct node* root)
    // {
    //     if(root==NULL)
    //     return true;
    //     bool left=isBalanced(root->left);
    //     bool right=isBalanced(root->right);
    //     bool diff=abs(height(root->left)-height(root->right))<=1;
    //     if(left&&right&&diff)
    //     return 1;
    //     else
    //     return false;
    // }
    pair<bool, int> isBalancedFast(struct node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(struct node *root)
    {
        return isBalancedFast(root).first;
    }
     bool isIdentical(struct node *r1, struct node *r2)
    {
        // base case
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL && r2 != NULL) {
            return false;
        }
        
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data;
        
        
        if(left && right && value) {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    pair<bool,int> isSumTreeFast(struct node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }
    bool isSumTree(struct node* root)
    {
        return isSumTreeFast(root).first;
    }
    void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();

        q.pop();
        if(temp==NULL)
        {
        cout<<endl;
        if(!q.empty())
        q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        }
    }
}
int main()
{
    node* root=buildtree(root);
    levelOrderTraversal(root);
    int heigh=height(root);
    cout<<"\n"<<heigh-1<<endl;
    int dia=diameter(root);
    cout<<"\n"<<dia<<endl;
    // bool bal=isBalanced(root);
    // cout<<"\n"<<bal<<endl;
    // node* r1=buildtree(root1);
    // node* r2=buildtree(root2);
    //  bool Id=isIdentical(r1,r2);
    // cout<<"\n"<<Id<<endl;
    //  bool sum=isSumTreeFast(r1);
    // cout<<"\n"<<sum<<endl;
}