#ifndef TP03_H
#define TP03_H

#define NUM 50

struct linearNode 
{
    int id ; // used this as address
    char childName [ NUM ];
    char parentName [ NUM ];
    int childBY ; // childBirthYear
    int parentPhone ;
    struct linearNode * linearNext ;	
};
struct linearNode* createLinearNode(int id, char childName[], char parentName[], int childBY, int parentPhone);


/// Singly Linked List
void SL_insertBeginning(struct linearNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void SL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void SL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode);

void SL_deleteAtBeginning(struct linearNode **head);
void SL_deleteAtEnd(struct linearNode **head);
void SL_deleteAfterNode(struct linearNode *head, int targetID);

void printSinglyLinearList(struct linearNode *head);
struct linearNode *searchSinglyNode(struct linearNode *head, int id);

// Circular Singly Linked List
void CSL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void CSL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void CSL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode);

void CSL_deleteAtBeginning(struct linearNode **head);
void CSL_deleteAtEnd(struct linearNode **head);
void CSL_deleteAfterNode(struct linearNode* head, int targetID);

void printSinglyCircularList(struct linearNode* head);
struct linearNode *searchCircularSinglyNode(struct linearNode *head, int id);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct doublyNode {
    int id ; // used this as address of the CDLnode
    char childName [ NUM ];
    char parentName [ NUM ];
    int childBY ; // childBirthYear
    int parentPhone ;
    struct doublyNode * doublyNext ;
    struct doublyNode * doublyPrev ;
};
struct doublyNode* createDoublyNode(int id, char childName[], char parentName[], int childBY, int parentPhone);

// Doubly Linked List
void DL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void DL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void DL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode);


void DL_deleteAtBeginning(struct doublyNode** head);
void DL_deleteAtEnd(struct doublyNode** head);
void DL_deleteAfterNode(struct doublyNode *head, int targetID);

void printDoublyLinearList(struct doublyNode* head);
struct doublyNode* searchDoublyNode(struct doublyNode* head, int id);

// Circular Doubly Linked List
void CDL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void CDL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone);
void CDL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) ;

void CDL_deleteAtBeginning(struct doublyNode** head) ;
void CDL_deleteAtEnd(struct doublyNode** head) ;
void CDL_deleteAfterNode(struct doublyNode* head, int targetID);

void printDoublyCircularList(struct doublyNode* head);
struct doublyNode* searchCircularDoublyNode(struct doublyNode* head, int id);

#endif // TP03_H

