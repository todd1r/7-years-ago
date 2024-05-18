#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(struct node* head)
{
    head=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data or press -1 to exit\n");
    scanf("%d",&x);
    head->data=x;
    if(x==-1)
    return NULL;
    printf("Enter left child of %d\n",x);
    head->left=create(head->left);
    printf("Enter left child of %d\n",x);
    head->right=create(head->right);
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
int bst_check(struct node* head, int min, int max) {
    if (head == NULL)
        return 1;
    if (head->data <= min || head->data >= max)
        return 0;
    return bst_check(head->left, min, head->data ) && bst_check(head->right, head->data , max);
}
int main()
{
    struct node* head=create(head);
    inorder(head);
    if (bst_check(head, INT_MIN, INT_MAX))
        printf("\nBST\n");
    else
        printf("\nNot BST\n");
}
