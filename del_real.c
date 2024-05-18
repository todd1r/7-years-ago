#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(struct node *head, int key)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = key;
    head->left = NULL;
    head->right = NULL;
    return head;
}
struct node *create(struct node *head, int key)
{
    if (head == NULL)
    {
        head = newnode(head, key);
        return head;
    }
    else if (key < head->data)
        head->left = create(head->left, key);
    else if (key > head->data)
        head->right = create(head->right, key);
    return head;
}
void inorder(struct node *head)
{
    if (head == NULL)
        return;
    inorder(head->left);
    printf("%d ", head->data);
    inorder(head->right);
}
struct node *delete(struct node *head, int key)
{
    if (head == NULL)
        return head;
    else if (head->data == key)
    {
        if (head->left == NULL)
        {
            struct node *temp = head->right;
            free(head);
            return temp;
        }
        else if (head->right == NULL)
        {
            struct node *temp = head->left;
            free(head);
            return temp;
        }
        else
        {
            struct node *n = head->right;
            while (n->left != NULL)
            {
                n = n->left;
            }
            head->data = n->data;
            head->right = delete (head->right, head->data);
        }
    }
    else if (key < head->data)
    {
        head->left = delete (head->left, key);
    }
    else if (key > head->data)
    {
        head->right = delete (head->right, key);
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    while (1)
    {
        int x;
        printf("Enter data to be inserted or press -1 to exit\n");
        scanf("%d", &x);
        if (x == -1)
            break;
        head = create(head, x);
    }
    inorder(head);
    while (1)
    {
        int x;
        printf("\nEnter data to be deleted or press -1 to exit\n");
        scanf("%d", &x);
        if (x == -1)
            break;
        head = delete (head, x);
        inorder(head);
    }
    inorder(head);
}
