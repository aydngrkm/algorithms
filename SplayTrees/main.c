#include <stdio.h>
#include <stdlib.h>
#include "splay.h"

int main(int argc, char *argv[]) 
{
	if (argc == 1) {
		printf("Where is my splay?!?!\n");
		return -1;
	}
	// Values to be added to the Splay tree are: 15 10 17 7 13 16
	struct node *root = NULL;
	for (int i = 1; i < argc; ++i) {
		root = insertNode(root, atoi(argv[i]));
		printTreePreOrder(root);
		printf("\n");
	}

	// Search for a key in the tree and splay it to the root
	int key_to_search = 10;  // Replace this with the key you want to search for
	root = search(root, key_to_search);
	printf("Preorder traversal after searching for %d:\n", key_to_search);
	printTreePreOrder(root);
	printf("\n");

	return 0;		
}
