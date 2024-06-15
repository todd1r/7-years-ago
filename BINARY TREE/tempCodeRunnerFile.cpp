            if(!q.empty())
            q.push(nullptr);
        }
        else
        {
            cout<<front->data<<" ";
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
    }
}
void inorder(node* root,int &count)
{
    if(root==nullptr)
    return;
    inorder(root->left,count);
    count++;
    cout<<root->data<<" ";
    inorder(root->right,count);
}
int height(node* root)