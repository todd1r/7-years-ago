#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *newnode(struct node*head,int key)
{
    head=(struct node*)malloc(sizeof(struct node));
    head->data=key;
    head->left=NULL;
    head->right=NULL;
    return head;
}
struct node* create(struct node* head,int key)
{
    if(head==NULL)
    {
        head=newnode(head,key);
        return head;
    }
    else if(key<head->data)
    head->left=create(head->left,key);
    else if(key>head->data)
    head->right=create(head->right,key);
    return head;
}
void inorder(struct node* head)
{
    if(head==NULL)
    return;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}
int main()
{
    struct node* head=NULL;
    while(1)
    {
    int x;
    printf("Enter data or press -1 to exit");
    scanf("%d",&x);
    if(x==-1)
    break;
    head=create(head,x);
    }
    inorder(head);
}
