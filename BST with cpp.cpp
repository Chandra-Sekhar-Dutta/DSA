#include <iostream>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize the node
    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }

    // Function to create a new node
    node *createTree(int value) {
        return new node(value);
    }

    // Function to insert a node into the tree
    node *InsertNode(node *root, int value) {
        if (root == NULL) {
            return createTree(value);
        } else if (value <= root->data) {
            root->left = InsertNode(root->left, value);
        } else {
            root->right = InsertNode(root->right, value);
        }
        return root;  // Return the updated root
    }

    // In-order traversal
    void InOrderTraversal(node *root) {
        if (root == NULL) {
            return;
        } else {
            InOrderTraversal(root->left);
            cout << root->data << " ";
            InOrderTraversal(root->right);
        }
    }
};

int main() {
    node N1(3);

    node *root = N1.createTree(3);
    root = N1.InsertNode(root, 0);
    root = N1.InsertNode(root, 5);
    root = N1.InsertNode(root, -2);
    root = N1.InsertNode(root, 2);
    root = N1.InsertNode(root, 7);
    root = N1.InsertNode(root, -9);
    root = N1.InsertNode(root, 10);

    N1.InOrderTraversal(root);

    return 0;
}

