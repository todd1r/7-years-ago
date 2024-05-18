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
void preorder(struct node* root)
{
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root,int &count)
{
    if(root==NULL)
    return;
    inorder(root->left,count);
    if(root->left==NULL&&root->right==NULL)
    count++;
    //printf("%d ",root->data);
    inorder(root->right,count);
}
void postorder(struct node* root)
{
    if(root==NULL)
    return;
     postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for:"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    // node* root=buildtree(root);
    // levelOrderTraversal(root);
    // printf(\n);
    // preorder(root);
    // printf(\n);
    // inorder(root);
    // printf(\n);
    // postorder(root);

    node* root=NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // int count=0;
    // inorder(root,count);
    // cout<<count<<endl;
}