#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* newnode(node* root,int d)
{
    root=new node;
    root->data=d;
    root->left=nullptr;
    root->right=nullptr;
    return root;
}
node* create()
{
    int x;
    cout<<"Enter data or press -1 to exit"<<endl;
    cin>>x;
    if(x==-1)
    return nullptr;
    node* root=newnode(root,x);
    cout<<"Enter left part"<<endl;
    root->left=create();
    cout<<"Enter right part"<<endl;
    root->right=create();
    return root;
}
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node* front=q.front();
        q.pop();
        if(front==nullptr)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout<<front->data;
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
    }
}
void inorder(node* root,int &count)
{
    if(root==nullptr)
    return;
    inorder(root->left,count);
    count++;
    cout<<root->data<<" ";
    inorder(root->right,count);
}
// buildFromLevelOrder(node* root)
// {
//     queue<node*> root;
//     cout<<"Enter data or press -1 to exit"<<endl;
//     cin>>x;
//     if(x==-1)
//     return nullptr;
//     root=newnode(root,x);
//     q.push(nullptr)
//     {

//     }
//     return root;
// }
int main()
{
    node* root=create();
    int count=0;
    inorder(root,count);
    cout<<endl;
    cout<<count<<endl;
    levelOrderTraversal(root);
}