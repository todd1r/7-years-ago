#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *newnode(int x)
{
    node *root = new node;
    root->data = x;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}
node *buildTree()
{
    cout << "Enter data or press -1 to exit" << endl;
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;
    node *root = newnode(x);
    cout << "Enter left node of " << x << endl;
    root->left = buildTree();
    cout << "Enter right node of " << x << endl;
    root->right = buildTree();
    return root;
}
void levelOrderTraversal(node *&root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (front == nullptr)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
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
void inorder(node *root, int &count)
{
    if (root == nullptr)
        return;
    inorder(root->left, count);
    count++;
    cout << root->data << " ";
    inorder(root->right, count);
}
int height(node *root)
{
    if (root == nullptr)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    int ans = max(l, r) + 1;
    return ans;
}
pair<int,int> diaFast(node* root)
{
    if(root==nullptr)
    return {0,0};
    pair<int,int> left=diaFast(root->left);
    pair<int,int> right=diaFast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int dia(node* root)
return diaFast(root).first;
pair<bool,int> isBal(node* root)
{
    if(root==nullptr)
    return {0,0};
    pair<bool,int> left=isBal(root->left);
    pair<bool,int> right=isBal(root->right);
    bool op1=left.first;
    bool op2=right.first;
    bool op3=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    if(op1&&op2&&op3)
    ans.first=true;
    else
    ans.first=false;
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int bal(node* root)
return isBal(root).first;
bool isId(node* root1,node*root2)
{
    if(root1==nullptr&&root2==nullptr)
    return true;
    else if(root1==nullptr&&root2!=nullptr)
    return false;
    else if(root1!=nullptr&&root2==nullptr)
    return false;
    bool left=isId(root1->left,root2->left);
    bool right=isId(root1->right,root2->right);
    bool value=root->data==
}
int main()
{
    node *root = buildTree();
    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);
    int count = 0;
    cout << "Inorder Traversal" << endl;
    inorder(root, count);
    cout << endl
         << "No of nodes " << count << endl;
    cout << "Hieght of tree is " << height(root) << endl;
    cout << "Diameter of tree is " << dia(root) << endl;
    if(bal(root))
    cout << "Tree is balanced"<< endl;
    else
    cout << "Tree is not balanced"<< endl;
    node *root1 = buildTree();
    node *root2 = buildTree();
    if(isId(root1,root2))
    cout << "Tree is Identical"<< endl;
    else
    cout << "Tree is not Identical"<< endl;
}