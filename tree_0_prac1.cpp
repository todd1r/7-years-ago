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
        this->left-NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root)
{
    printf("Enter data or press -1 to exit\n");
    int d;
    scanf("%d",&d);
    root=new node(d);
        if(d==-1)
    return NULL;
    if(root==NULL)
    return root;
    printf("Enter left child\n");
    root->left=buildTree(root->left);
    printf("Enter right child\n");
    root->right=buildTree(root->right);
}
int main()
{
    node* root=buildTree(root);
}