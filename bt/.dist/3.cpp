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
vector <int> zigZagTraversal(struct node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	
    	queue<struct node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()) {
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++) {
    	        
    	        struct node* frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;
    	   
    	  for(auto i: ans) {
    	      result.push_back(i);
    	  }  
    	}
    	    return result;
    }
    void traverseLeft(node* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL)
        return;
        ans.push_back(root->data);
        if(root->left)
        traverseLeft(root->left,ans);
        else
        traverseLeft(root->right,ans);
    }
    void traverseLeaf(node* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL)
        //return;
      {  ans.push_back(root->data);
        return;
      }
        //if(root->left)
        traverseLeaf(root->left,ans);
        //else
        traverseLeaf(root->right,ans);
    }
    void traverseRight(node* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL)
        return;
        if(root->right)
        traverseRight(root->right,ans);
        else
        traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundary(node* root)
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        traverseRight(root->right,ans);
    }



    //horizontal
    vector<int> verticalOrder(node* root)
    {
        map<int,map<int,vector<int>>> nodes;
        queue<pair<node*,pair<int,int>> q;
        vector<int> ans;
        if(root==NULL)
        return ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<node*,pair<int>> temp=q.front();
            q.pop();
            node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontNode->data);
            if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)))
        }
        for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
    int main()
{
    node* root=buildtree(root);
    vector<int> zigZag=zigZagTraversal(root);
    for(int i=0;i<zigZag.size();i++)
    cout<<zigZag[i]<<" ";
}