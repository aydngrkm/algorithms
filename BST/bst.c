#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

// New node create function
struct node* newNode(int data) 
{
    struct node *new_node = malloc(sizeof(struct node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

// Write a function that recursively adds a new node to the tree.
struct node* insertNode(struct node* n, int data) {
    if (n == NULL) return newNode(data);

    if (data >= n->data) n->right = insertNode(n->right, data);
	else n->left = insertNode(n->left, data);

	return n;
}

// Write a function that finds the lowest value in the tree and returns it
int findMin(struct node *tree) 
{
	if (tree == NULL) return -1;

	if (tree->left != NULL) return findMin(tree->left);
	else return tree->data;
}

// Write a function that finds the max value in the tree and returns it
int findMax(struct node *tree) 
{
	if (tree == NULL) return -1;

	if (tree->right != NULL) return findMax(tree->right);
	else return tree->data;
}

// Write a function that returns the address of the highest value node in the tree.
struct node* findMaxNode(struct node *tree) 
{
	if (tree == NULL) return NULL;

	if (tree->right != NULL) return findMaxNode(tree->right);
	else return tree;
}

// Write a function that recursively deletes nodes from the tree. If the node to be deleted has 2 children, update the deleted node as the maximum valued node of the left sub-tree.
// (like the Delete function at https://www.cs.usfca.edu/~galles/visualization/BST.html)
struct node* deleteNode(struct node *tree, int data) 
{
	if (tree == NULL) return NULL;

	if (data < tree->data) tree->left = deleteNode(tree->left, data);
	else if (data > tree->data) tree->right = deleteNode(tree->right, data);

	else {
		if (tree->left == NULL) {
			struct node *temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL) {
			struct node *temp = tree->left;
			free(tree);
			return temp;
		}

		struct node* temp = findMaxNode(tree->left);
        tree->data = temp->data;
        tree->left = deleteNode(tree->left, temp->data);
	}

	return tree;
}

// Write a function that traverses the tree recursively using the "in-order" method and prints the values to the screen.
void printTreeInOrder(struct node* tree) 
{
	if (tree == NULL) return;

	printTreeInOrder(tree->left);
	printf("%d ", tree->data);
	printTreeInOrder(tree->right);
}

// Write a function that traverses the tree recursively using the "pre-order" method and prints the values to the screen.
void printTreePreOrder(struct node* tree) 
{
	if (tree == NULL) return;

	printf("%d ", tree->data);
	printTreePreOrder(tree->left);
	printTreePreOrder(tree->right);
}

// Write a function that traverses the tree recursively using the "post-order" method and prints the values to the screen.	
void printTreePostOrder(struct node* tree) 
{
	if (tree == NULL) return;

	printTreePostOrder(tree->left);
	printTreePostOrder(tree->right);
	printf("%d ", tree->data);
}

// Level-order method
// Function that calculates the height of the tree recursively
int findHeight(struct node *tree) 
{	
	if (tree == NULL) return 0;

	int l = findHeight(tree->left);
	int r = findHeight(tree->right);

	return (l > r ? l : r) + 1;
}

// Function that recursively suppresses nodes in the same alignment (level)
void printLevel(struct node *tree, int level)
{
	if (tree == NULL) return;
	if (level == 1) {
		printf("%d ", tree->data);
		return;
	}

	printLevel(tree->left, level - 1);
	printLevel(tree->right, level - 1);
}

// Using the two functions above, write the function that traverses the tree with the "level-order" method and prints the values to the screen	
void printTreeLevelOrder(struct node* tree)
{
	int height = findHeight(tree);
	for (int i = 1; i <= height; ++i) printLevel(tree, i);
}
