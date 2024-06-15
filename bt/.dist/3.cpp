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
    	        
    	        struct node* frontnode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontnode -> data;
    	        
    	        if(frontnode->left)
    	            q.push(frontnode -> left);
    	            
    	        if(frontnode->right)
    	            q.push(frontnode -> right);
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
        //hori. dist., level, list of nodes
        map<int,map<int,vector<int>>> nodes;
        //hori. dist., level
        queue<pair<node*,pair<int,int>>> q;
        vector<int> ans;
        if(root==NULL)
        return ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<node*,pair<int,int>> temp=q.front();
            q.pop();
            node* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontnode->data);
            if(frontnode->left)
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            if(frontnode->right)
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
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

vector<int> topView(node *root)
    {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        //hd node
        map<int,int> topnode;
        //hd
        queue<pair<node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<node*, int> temp = q.front();
            q.pop();
            node* frontnode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
            if(topnode.find(hd) == topnode.end())
                topnode[hd] = frontnode -> data;
                
            if(frontnode->left)
                q.push(make_pair(frontnode->left, hd-1));
            if(frontnode->right)
                q.push(make_pair(frontnode->right, hd+1));
        }
        
        for(auto i:topnode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    }

vector<int> bottomView(node *root)
    {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topnode;
        queue<pair<node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<node*, int> temp = q.front();
            q.pop();
            node* frontnode = temp.first;
            int hd = temp.second;
            
            //if one value is present for a HD, then do nothing
                topnode[hd] = frontnode -> data;
                
            if(frontnode->left)
                q.push(make_pair(frontnode->left, hd-1));
            if(frontnode->right)
                q.push(make_pair(frontnode->right, hd+1));
        }
        
        for(auto i:topnode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    }

void solve(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}

void solve2(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);

    solve2(root->right, ans, level+1);    
    solve2(root->left, ans, level+1);
}

vector<int> rightView(node *root)
{
   vector<int> ans;
   solve2(root, ans, 0);
   return ans;
}


    int main()
{
    node* root=buildtree(root);

    cout<<"ZigZag Traversal"<<endl;
    vector<int> zigZag=zigZagTraversal(root);
    for(int i=0;i<zigZag.size();i++)
    cout<<zigZag[i]<<" ";
    cout<<endl;

    cout<<"Boundary Traversal"<<endl;
    vector<int> boun=boundary(root);
    for(int i=0;i<boun.size();i++)
    cout<<boun[i]<<" ";
    cout<<endl;

    cout<<"Vertical Order Traversal"<<endl;
    vector<int> vertOrder=verticalOrder(root);
    for(int i=0;i<vertOrder.size();i++)
    cout<<vertOrder[i]<<" ";
    cout<<endl;

    cout<<"Top View Traversal"<<endl;
    vector<int> top=topView(root);
    for(int i=0;i<top.size();i++)
    cout<<top[i]<<" ";
    cout<<endl;

    cout<<"Bottom View Traversal"<<endl;
    vector<int> bottom=bottomView(root);
    for(int i=0;i<bottom.size();i++)
    cout<<bottom[i]<<" ";
    cout<<endl;

    cout<<"Left View Traversal"<<endl;
    vector<int> left=leftView(root);
    for(int i=0;i<left.size();i++)
    cout<<left[i]<<" ";
    cout<<endl;

    cout<<"Right View Traversal"<<endl;
    vector<int> right=rightView(root);
    for(int i=0;i<right.size();i++)
    cout<<right[i]<<" ";
    cout<<endl;
}