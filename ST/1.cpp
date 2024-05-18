#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;
Node *newNode(Node *newnode, int d)
{
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
Node *create(Node* root,int d)
{
    if(root==NULL)
    {
        root=newNode(root,d);
        return root;
    }
    if(root->data>d)
    root->left = create(root->left,d);
    else if(root->data<d)
    root->right = create(root->right,d);
    return root;
}
void takeinput(Node* &root)
{
    cout<<"Enter data or press -1 to exit"<<endl;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root=create(root,d);
        cin>>d;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
bool searchBST(Node* root,int d)
{
    Node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==d)
        return true;
        else if(temp->data>d)
        temp=temp->left;
        else if(temp->data<d)
        temp=temp->right;
    }
    return false;
}
Node* minval(Node* root)
{
    Node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* maxval(Node* root)
{
    Node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
Node* del(Node* root,int d)
{
    if(root==NULL)
    return root;
    else if(root->data==d)
    {
        if(root->left==NULL&root->right==NULL)
        return NULL;
        else if(root->left==NULL&&root->right!=NULL)
        return root->right;
        else if(root->left!=NULL&&root->right==NULL)
        return root->left;
        else
        {
            int min=(minval(root->right))->data;
            root->data=min;
            root->right=del(root->right,min);
            return root;
        }
    }
    else if(root->data>d)
    root->left=del(root->left,d);
    else if(root->data<d)
    root->right=del(root->right,d);
    return root;
}
int main()
{
    // Node* head=create(head);
    // count=0;
    // inorder(head,count);
    // cout<<endl;
    Node *head=NULL;
    takeinput(head);
    levelOrderTraversal(head);
    bool b=searchBST(head,9);
    cout<<b;
    head=del(head,3);
    cout<<endl;
    levelOrderTraversal(head);
}
