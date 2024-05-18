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
Node *create(Node *root)
{
    cout << "Enter data or press -1 to exit" << endl;
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    root = newNode(root, d);
    cout << "Enter left node of " << d << " or press -1 to exit" << endl;
    root->left = create(root->left);
    cout << "Enter right node of " << d << " or press -1 to exit" << endl;
    root->right = create(root->right);
    return root;
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
void inorder(Node *root, int &count)
{
    if (root == NULL)
        return;
    inorder(root->left, count);
    count++;
    cout << root->data << " ";
    inorder(root->right, count);
}
void buildFromLevelOrder(Node* &root)
{
    queue<Node *> q;
    cout << "Enter data or press -1 to exit" << endl;
    int d;
    cin >> d;
    if (d == -1)
        return;
    root = newNode(root, d);
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << "Enter left node of " << front->data << " or press -1 to exit" << endl;
        int l;
        cin >> l;
        if (l != -1)
        {
            front->left = newNode(front->left, l);
            q.push(front->left);
        }
        cout << "Enter right node of " << front->data << " or press -1 to exit" << endl;
        int r;
        cin >> r;
        if (r != -1)
        {
            front->right = newNode(front->right, r);
            q.push(front->right);
        }
    }
}
int height(Node* root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    int ans=max(l,r)+1;
    return ans;
}
int main()
{
    // Node* head=create(head);
    // count=0;
    // inorder(head,count);
    // cout<<endl;
    Node *head;
    buildFromLevelOrder(head);
    levelOrderTraversal(head);
    int h = height(head);
    cout << h << endl;
}