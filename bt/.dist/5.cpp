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
// int findPosition(int in[],int element,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(in[i]==element)
//         return i;
//     }
//     return -1;
// }
void createMapping(int in[],map<int,int> &nodeToIndex,int n)
{
    for(int i=0;i<n;i++)
    nodeToIndex[in[i]]=i;
}
//node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n)
node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex)
{
    if(index>=n||inorderStart>inorderEnd)
    return NULL;
    int element=pre[index++];
     node* root=new node(element);
    // int position=findPosition(in,element,n);
    // root->left=solve(in,pre,index,inorderStart,position-1,n);
   
    // root->right=solve(in,pre,index,position+1,inorderEnd,n);
  //// cout<<index<<" "<<position<<" "<<inorderStart<<" "<<inorderEnd<<" "<<root->data<<endl;
    
    int position=nodeToIndex[element];
    root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
    root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToIndex);
    

    return root;
}
    node* buildTree(int in[],int pre[],int n)
    {
        int preOrderIndex=0;
        map<int,int> nodeToIndex;
        createMapping(in,nodeToIndex,n);
        node* ans=solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
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
    
    int in[]={4,2,5,1,6,3,7};
    int pre[]={1,2,4,5,3,6,7};
    node* root=buildTree(in,pre,7);
    levelOrderTraversal(root);
}