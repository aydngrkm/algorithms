#include <stdio.h>
#include <stdlib.h>
#include "splay.h"

struct node *createNode(int data) 
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;

    return new_node;
}

struct node *rightRotate(struct node *x) 
{
    struct node *left_child = x->left;
    x->left = left_child->right;
    left_child->right = x;

    return left_child;
}

struct node *leftRotate(struct node *x) 
{
    struct node *right_child = x->right;
    x->right = right_child->left;
    right_child->left = x;
    
    return right_child;
}

// This function brings the key at the root if the key is present in the tree.
// If the key is not present, then it brings the last accessed item at the root.
// This function modifies the tree and returns the new root.
struct node *splay(struct node *root, int key) 
{
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->data == key) return root;

    // Key lies in the left subtree
    if (root->data > key) 
    {
        // Key is not in the tree, we are done
        if (root->left == NULL) return root;

        // Zig-Zig (Left Left)
        if (root->left->data > key) {
            // First recursively bring the key as the root of left-left
            root->left->left = splay(root->left->left, key);

            // Do the first rotation for root, the second rotation is done after else
            root = rightRotate(root);
        }

        // Zig-Zag (Left Right)
        else if(root->left->data < key) {
            // First recursively bring the key as the root of left-right
            root->left->right = splay(root->left->right, key);

            // Do the first rotation for root->left
            if (root->left->right != NULL) root->left = leftRotate(root->left);
        }

        // Do the second rotation for root
        if (root->left == NULL) return root;
        else return rightRotate(root);
    }

    // Key lies in the right subtree
    else
    {
        // Key is not in the tree, we are done
        if (root->right == NULL) return root;

        // Zag-Zig (Right Left)
        if (root->right->data > key) {
            // Bring the key as the root of right-left
            root->right->left = splay(root->right->left, key);

            // Do the first rotation for root->right
            if (root->right->left != NULL) root->right = rightRotate(root->right);
        }

        // Zag-Zag (Right Right)
        else if (root->right->data < key)
        {
            // Bring the key as the root of right-right and do the first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do the second rotation for root
        if (root->right == NULL) return root;
        else return leftRotate(root);
    }
}



struct node *insertNode(struct node *root, int data) 
{
    if (root == NULL) return createNode(data);
    root = splay(root, data);

    if (root->data == data) return root;
    struct node *new_node = createNode(data);

    if (root->data > data) {
        new_node->left = root->left;
        new_node->right = root;
        root->left = NULL;
    }

    else {
        new_node->left = root;
        new_node->right = root->right;
        root->right = NULL;
    }

    return new_node;
}

// The search function for the Splay tree. Note that this function
// returns the new root of the Splay Tree. If the key is present in the tree,
// then it is moved to the root.
struct node *search(struct node *root, int key) 
{
    return splay(root, key);
}

void printTreePreOrder(struct node *root) 
{
    if (root == NULL) return;

	printf("%d ", root->data);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}
