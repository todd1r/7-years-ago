#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(struct node* head)
{
    head=(struct node*)malloc(sizeof(struct node));
     while(1)
    {
    int x;
    printf("Enter data or press -1 to exit\n");
    scanf("%d",&x);
    head->data=x;
    if(x==-1)
    break;
    printf("Enter left child of %d\n",x);
    head->left=create(head->left);
    printf("Enter left child of %d\n",x);
    head->right=create(head->right);
    }
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
// void bst_check(struct node* head)
// {
//     if(head==NULL||head->left==NULL||head->right==NULL)
//     return;
//     if(head->data<head->right->data&&head->data>head->left->data)
//     {
//         bst_check(head->left);
//         bst_check(head->right);
//     }
//     else
//     {
//         printf("Not BST\n");
//         return ;
//     }
// }
int main()
{
    struct node* head=create(head);
    inorder(head);
    bst_check(head);
    // if(x==1)
    // printf("BST\n");
    // else
    // printf("Not BST\n");
}
