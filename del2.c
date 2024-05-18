#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *newnode(int key) {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = key;
    head->left = NULL;
    head->right = NULL;
    return head;
}

struct node* create(struct node* head, int key) {
    if (head == NULL) {
        head = newnode(key);
        return head;
    } else if (key < head->data)
        head->left = create(head->left, key);
    else if (key > head->data)
        head->right = create(head->right, key);
    return head;
}

void inorder(struct node* head) {
    if (head == NULL)
        return;
    inorder(head->left);
    printf("%d ", head->data);
    inorder(head->right);
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node* head = NULL;
    while (1) {
        int x;
        printf("Enter data to be inserted or press -1 to exit\n");
        scanf("%d", &x);
        if (x == -1)
            break;
        head = create(head, x);
    }
    printf("Inorder traversal: ");
    inorder(head);
    
    while (1) {
        int x;
        printf("\nEnter data to be deleted or press -1 to exit\n");
        scanf("%d", &x);
        if (x == -1)
            break;
        head = deleteNode(head, x);
        printf("Inorder traversal after deletion: ");
        inorder(head);
    }
    inorder(head);
    return 0;
}
