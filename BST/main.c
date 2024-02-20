#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

int main(int argc, char *argv[]) 
{
	if (argc == 1) {
		printf("Where is my BST?!?!\n");
		return -1;
	}
	// for copy-paste: 78 85 56 65 13 79 85 86 43
	
	// Define and create a BST using the parameters you get from the command line
	struct node *root = newNode(atoi(argv[1]));

	for (int i = 2; i < argc; ++i) insertNode(root, atoi(argv[i]));
	
	// Add a new node with value 97 to your tree
	insertNode(root, 97);
	
	// Print the min and max values of the nodes in the tree to the screen
	printf("Minimum: %d\n", findMin(root));
	printf("Maximum: %d\n", findMax(root));
	
	// Delete nodes with values 85 and 56 respectively
	root = deleteNode(root, 85);
	root = deleteNode(root, 56);
	
	// Print the values of the nodes properly on the screen by traversing the tree using in-order, pre-order, post-order and level-order methods.
	printf("In-order   : ");
	printTreeInOrder(root);
	printf("\n");

	printf("Pre-order  : ");
	printTreePreOrder(root);
	printf("\n");

	printf("Post-order : ");
	printTreePostOrder(root);
	printf("\n");

	printf("Level-order: ");
	printTreeLevelOrder(root);
	printf("\n");
	
	return 0;
}
