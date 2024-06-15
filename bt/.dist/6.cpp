#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent)
{
    node* res=NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty())
    {
        node* front=q.front();
        q.pop();
        if(front->data==target)
        res=front;
        if(front->left)
        {
        nodeToParent[front->left]=front;
        q.push(front->left);
        }
         if(front->right)
        {
        nodeToParent[front->right]=front;
        q.push(front->right);
        }
    }
    return res;
}
//O(N) sc and tc
int burnTree(node* root,map<node*,node*> &nodeToParent)
{
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root]=1;
    int ans=0;
    while(!q.empty())
    {
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            //process neighbouring nodes
            node* front=q.front();
            q.pop();
            if(front->left&&!visited[front->left])
            {
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }
            if(front->right&&!visited[front->right])
            {
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            if(nodeToParent[front]&&!visited[nodeToParent[front]])
            {
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=1;
            }
        }
        if(flag==1)
        ans++;
    }
    return ans;
}
int minTime(node* root,int target)
{
    int ans=0;
    map<node*,node*> nodeToParent;
    node* targetNode=createParentMapping(root,target,nodeToParent);
    ans=burnTree(targetNode,nodeToParent);
    return ans;
}
int main()
{
    node *root =buildtree(root);
    int ans=minTime(root,5);
    cout<<ans<<endl;
    levelOrderTraversal(root);
}