#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;  // Change char to int for the data type
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    newNode->data = data;  // Assign the data to the node
    newNode->left = newNode->right = NULL;
    
    return newNode;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    else if (data <= root->data) {
        root->left = insert_node(root->left, data);
    }
    else {
        root->right = insert_node(root->right, data);
    }
    return root;

}

void inOrderTraversal(struct node *root) {
    if (root == NULL) { 
        return;
    }
    else{
        inOrderTraversal(root->left);
        printf("%d  ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d  ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d  ",root->data);
    }
}

int main() {
    struct node *root = create_node(100);
    root = insert_node(root, 200);
    root = insert_node(root, 50);
    root = insert_node(root, 40);
    root = insert_node(root, 45);
    root = insert_node(root, 55);
    root = insert_node(root, 250);
    root = insert_node(root, 44);
    
    
    // Perform inorder traversal to print the elements
    printf("In-order Traversal=");
    inOrderTraversal(root);
    printf("\n");
    printf("Pre-order Traversal=");
    preOrderTraversal(root);
    printf("\n");
    printf("Post-order Traversal=");
    postOrderTraversal(root);

    return 0;
}

