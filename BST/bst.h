// Define BST node structure
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


struct node* newNode(int data) ;
struct node* insertNode(struct node* n, int data) ;
int findMin(struct node *tree) ;
int findMax(struct node *tree) ;
struct node* findMaxNode(struct node *tree) ;
struct node* deleteNode(struct node *tree, int data) ;
void printTreeInOrder(struct node* tree) ;
void printTreePreOrder(struct node* tree) ;
void printTreePostOrder(struct node* tree) ;
int findHeight(struct node *tree) ;
void printLevel(struct node *tree, int level);
void printTreeLevelOrder(struct node* tree) ;
