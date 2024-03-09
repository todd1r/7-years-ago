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
    cout<<"Enter the data"<<endl;
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
 stack<int> s;
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    // stack<int> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();

        q.pop();
        if(temp==NULL)
        {
        cout<<endl;
        s.push(-1);
        if(!q.empty())
        q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            s.push(temp->data);
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        }
    }
}
void reversePrint(node* root)
{
    stack<int> s2;
    while(!s.empty())
    {
    if(s.top()!=-1)
    s2.push(s.top());
    //cout<<s.top()<<" ";
    else
    {
        while(!s2.empty())
        {
     cout<<s2.top()<<" ";
     s2.pop();
        }
    cout<<endl;
    }
    s.pop();
    }
    cout<<s2.top();
}
int main()
{
    node* root=buildtree(root);
    levelOrderTraversal(root);
    reversePrint(root);
}