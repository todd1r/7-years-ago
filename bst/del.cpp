#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int lef;
    int rig;
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
            cout<<temp->data<<" "<<temp->lef<<" "<<temp->rig<<"  $ ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        }
    }
}
//tc in normal case is o(logn) or o(height)
//tc in worst case is o(n)
//sc o(height) since recursion stack this was by recursive method by iterative method sc reduces to o(1)
bool searchInBST(Node* root,int x)
{
    // if(root==NULL)
    // return false;
    // if(root->data==x)
    // return true;
    // if(root->data>x)
    // return searchInBST(root->left,x);
    // else 
    // return searchInBST(root->right,x);


    Node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        return true;
        if(temp->data>x)
        temp=temp->left;
        else
        temp=temp->right;
    }
    return false;
}
Node* minVal(Node* root)
{
    Node* temp=root;
    while(temp->left!=NULL)
    temp=temp->left;
    return temp;
}
Node* maxVal(Node* root)
{
    Node* temp=root;
    while(temp->right!=NULL)
    temp=temp->right;
    return temp;
}
Node* deleteFromBST(Node* root,int val)
{
    //base case
    if(root==NULL)
    return root;
    if(root->data==val)
    {
        //0 child
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL&&root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL&&root->right!=NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL&&root->right!=NULL)
        {
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>val)
    {
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else
    {
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}
int label(Node* root)
{
    if(root==NULL)
    {
      return 0;
    }
    if(root->left)
    {
        return label(root->left)+1;
    }
    if(root->right)
    {
        return label(root->right)+1;
    }
}
int main()
{
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    label(root);

    levelOrderTraversal(root);
    // bool search=searchInBST(root,3);
    // cout<<search<<endl;
    //label(root);
}