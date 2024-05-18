#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
//tc o(logn)
Node* insertIntoBST(Node* &root,int d)
{
    if(root==NULL)
    {
    root=new Node(d);
    return root;
    }
    if(d>root->data)
    root->right=insertIntoBST(root->right,d);
    else
    root->left=insertIntoBST(root->left,d);
    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
bool isBST(Node* root,int min,int max)
{
    if(root==NULL)
    return true;
    if(root->data>=min&&root->=data<max)
    {
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left&&right;
    }
    else
    return false;
}
bool validateBST(Node* root)
{
    return isBST(root,INT_MIN,INT_MAX);
}
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();

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
int solve(Node* root,int &i,int k)
{
    if(root==NULL)
    return -1;
    int left=solve(roo->left,i,k);
    if(left!=-1)
    return left;
    i++;
    if(i==k)
    return root->data;
    return solve(root->right,i,k);
}
//tc o(n)  sc O(h)
int kthSmallest(Node* root,int k)
{
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}
int main()
{
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    bool valid=validateBST(root);
    cout<<valid<<endl;
}