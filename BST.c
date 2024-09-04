#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* root = NULL; 

struct node* create(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int x) {
    if (root == NULL) {
        return create(x);
    } else if (x > root->data) {
        root->right = insert(root->right, x);
    } else if (x < root->data) {
        root->left = insert(root->left, x);
    }
    return root; 
}

struct node* search(struct node* root, int x) {
    if (root == NULL) {
        printf("Node not found\n");
        return NULL;
    } else if (x == root->data) {
        printf("Node found: %d\n", root->data);
        return root;
    } else if (x > root->data) {
        return search(root->right, x);
    } else {
        return search(root->left, x);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node* minimum(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    else if(root->left!=NULL){
        return minimum(root->left);
    }
    return root;
}

int main() {
    
    int ch, x;
    printf("Binary Search Tree Implementation\n");
    do {
        printf("1. Insert \n2. Search \n3. Inorder Traversal \n4. Preorder Traversal \n5. Postorder Traversal \n6. Delete \n7. Find Minimum \n8. Exit\n");
        printf("Enter your Choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &x);
                search(root, x);
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                preorder(root);
                printf("\n");
                break;

            case 5:
                postorder(root);
                printf("\n");
                break;

            /* case 6:
                printf("Enter the data to Delete: ");
                scanf("%d", &x);
                root = delete(root, x); // You need to implement the delete function
                break; */

            case 7:
                {
                    struct node* minNode = minimum(root);
                    if (minNode != NULL) {
                        printf("Minimum value: %d\n", minNode->data);
                    } else {
                        printf("Tree is empty\n");
                    }
                }
                break;

            case 8:
                exit(0);

            default:
                printf("Please Enter a Valid Choice!\n");
        }
    } while (ch != 8);
    return 0;
}
