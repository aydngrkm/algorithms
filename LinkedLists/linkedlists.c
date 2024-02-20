#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlists.h"

////////// Singly Linked List ////////

struct linearNode* createLinearNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode *new_node = (struct linearNode*) malloc(sizeof(struct linearNode));
    if (new_node == NULL) return NULL;
    new_node->childBY = childBY;
    new_node->id = id;

    strcpy(new_node->childName, childName);
    strcpy(new_node->parentName, parentName);

    new_node->parentPhone = parentPhone;
    new_node->linearNext = NULL;

    return new_node;
}

void SL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode *new_node = createLinearNode(id, childName, parentName, childBY, parentPhone);
    if (*head != NULL) {
        new_node->linearNext = *head;
    }
    *head = new_node;
}

void SL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode *new_node = createLinearNode(id, childName, parentName, childBY, parentPhone);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct linearNode *curr = *head;
    while (curr->linearNext) curr = curr->linearNext;

    curr->linearNext = new_node;
}

void SL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    // TODO
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    newNode->linearNext = prevNode->linearNext;
    prevNode->linearNext = newNode; 
}

void SL_deleteAtBeginning(struct linearNode **head)
{
    //TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *temp = *head;
    *head = (*head)->linearNext;

    free(temp);
}

void SL_deleteAtEnd(struct linearNode **head)
{
    // TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    else if ((*head)->linearNext == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct linearNode *curr = *head;
    while (curr->linearNext->linearNext) curr = curr->linearNext;

    free(curr->linearNext);
    curr->linearNext = NULL;
} 

void SL_deleteAfterNode(struct linearNode *head, int targetID)
{
    // TODO
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *curr = head;
    while (curr != NULL && curr->id != targetID) curr = curr->linearNext;

    if (curr == NULL) {
        printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
        return;
    }
    else if (curr->linearNext == NULL) return;

    struct linearNode *temp = curr->linearNext;
    curr->linearNext = curr->linearNext->linearNext;
    free(temp);
}

void printSinglyLinearList(struct linearNode* head)
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct linearNode *current = head;
    while (current){
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->linearNext;
    }
}

struct linearNode *searchSinglyNode(struct linearNode *head, int id)
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct linearNode *curr = head;
    while (curr != NULL && curr->id != id) {
        curr = curr->linearNext;
    }
    if (curr == NULL) {
        printf("Node with ID %d not found in the list, cannot delete.\n", id);
        return NULL;
    }

    return curr;
}

////////// Circular Singly Linked List ////////

void CSL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) {
    struct linearNode *new_node = createLinearNode(id, childName, parentName, childBY, parentPhone);

    if (*head == NULL) {
        *head = new_node;
        new_node->linearNext = new_node;
        return;
    }
    // When inserting at the beginning, also update the last element of the list.
    struct linearNode *last_node = *head;
    while (last_node->linearNext != *head) last_node = last_node->linearNext;

    last_node->linearNext = new_node;
    new_node->linearNext = *head;
    *head = new_node;
}

void CSL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode *new_node = createLinearNode(id, childName, parentName, childBY, parentPhone);

    if (*head == NULL) {
        new_node->linearNext = new_node;
        *head = new_node;
        return;
    }

    struct linearNode *curr = *head;
    while (curr->linearNext != *head) curr = curr->linearNext;

    new_node->linearNext = *head;
    curr->linearNext = new_node;
}

void CSL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    // TODO
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    newNode->linearNext = prevNode->linearNext;
    prevNode->linearNext = newNode;
}

void CSL_deleteAtBeginning(struct linearNode **head)
{
    // TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *curr = *head;
    if(curr->linearNext == curr) {
        *head = NULL;
        free(curr);
    }
    else {
        while (curr->linearNext != *head) curr = curr->linearNext;
        curr->linearNext = (*head)->linearNext;
        free(*head);
        *head = curr->linearNext;
    }
}

void CSL_deleteAtEnd(struct linearNode **head)
{
    // TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    else if ((*head)->linearNext == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct linearNode *curr = *head;
    while (curr->linearNext->linearNext != *head) curr = curr->linearNext;

    free(curr->linearNext);
    curr->linearNext = *head;
}

void CSL_deleteAfterNode(struct linearNode* head, int targetID) 
{
    // TODO
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    // If the list has only one element and its ID matches the targetID, delete it.
    else if(head->linearNext == head && head->id == targetID) {
        free(head);
        head = NULL;
        return;
    }

    struct linearNode *node = searchCircularSinglyNode(head, targetID);
    // If the targetID is the last node and is mistakenly deleted twice, it may cause an error or infinite loop in the print function (varies depending on the list).
    if (node == NULL) printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
    else {
        struct linearNode *temp = node->linearNext;
        node->linearNext = node->linearNext->linearNext;
        free(temp);
    }
}

struct linearNode *searchCircularSinglyNode(struct linearNode *head, int id)
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct linearNode *curr = head;
    while (curr->linearNext != head && curr->id != id) curr = curr->linearNext;

    if (curr->id == id) return curr;
    else {
        printf("Node with ID %d not found in the list, cannot delete.\n", id);
        return NULL;
    }
}

void printSinglyCircularList(struct linearNode* head)
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct linearNode *current = head;
    printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
    
    while(current->linearNext != head) {
        current = current->linearNext;
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
    }
}


////////// Doubly Linked List ////////

// Function to create a node for the circular doubly linked list
struct doublyNode *createDoublyNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode *new_node = (struct doublyNode*) malloc(sizeof(struct doublyNode));
    if (new_node == NULL) return NULL;

    new_node->id = id;
    strcpy(new_node->childName, childName);
    strcpy(new_node->parentName, parentName);
    new_node->childBY = childBY;
    new_node->parentPhone = parentPhone;
    new_node->doublyNext = NULL;
    new_node->doublyPrev = NULL;

    return new_node;
}

void DL_insertBeginning(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode *new_node = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (*head != NULL) {
        (*head)->doublyPrev = new_node;
        new_node->doublyNext = *head;
    }

    *head = new_node;
}

void DL_insertAtEnd(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode *new_node = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct doublyNode *curr = *head;
    while (curr->doublyNext != NULL) curr = curr->doublyNext;

    curr->doublyNext = new_node;
    new_node->doublyPrev = curr;
}

void DL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    // TODO
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    newNode->doublyPrev = prevNode;
    newNode->doublyNext = prevNode->doublyNext;

    prevNode->doublyNext = newNode;
    
    if (newNode->doublyNext != NULL) {
        newNode->doublyNext->doublyPrev = newNode;
    }
}

void DL_deleteAtBeginning(struct doublyNode **head) 
{
    // TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    else if ((*head)->doublyNext == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    *head = (*head)->doublyNext;
    free((*head)->doublyPrev);

    (*head)->doublyPrev = NULL;
}


void DL_deleteAtEnd(struct doublyNode** head) 
{
    // TODO
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    else if ((*head)->doublyNext == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    struct doublyNode *curr = *head;
    while (curr->doublyNext->doublyNext != NULL) curr = curr->doublyNext;

    free(curr->doublyNext);
    curr->doublyNext = NULL;
}

void DL_deleteAfterNode(struct doublyNode *head, int targetID)
{
    // TODO
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct doublyNode *node = searchDoublyNode(head, targetID);
    if (node == NULL) printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
    else if (node->doublyNext == NULL) return;

    else if (node->doublyNext->doublyNext == NULL) {
        free(node->doublyNext);
        node->doublyNext = NULL;
    }

    else {
        node->doublyNext = node->doublyNext->doublyNext;
        free(node->doublyNext->doublyPrev);
        node->doublyNext->doublyPrev = node;
    }
}

void printDoublyLinearList(struct doublyNode *head) 
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct doublyNode *current = head;
    while (current != NULL) {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->doublyNext;
    }
}

struct doublyNode* searchDoublyNode(struct doublyNode* head, int id) 
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct doublyNode *curr = head;
    while (curr != NULL && curr->id != id) curr = curr->doublyNext;
        
    if (curr == NULL) {
        printf("Node with ID %d not found in the list, cannot delete.\n", id);
        return NULL;
    }
    else return curr;
}

/////// Circular Doubly Linked List /////////////

void CDL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
    struct doublyNode *new_node = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (*head == NULL) {
        // The pointers of new_node are self-referencing, and head is assigned to new_node.
        new_node->doublyNext = new_node;
        new_node->doublyPrev = new_node;
        *head = new_node;
        return;
    }
    
    // The pointers of new_node are assigned.
    new_node->doublyNext = *head;
    new_node->doublyPrev = (*head)->doublyPrev;

    // The previous of head is changed, and head is assigned to new_node.
    (*head)->doublyPrev = new_node;
    *head = new_node;

    // The next of the last element is assigned to the new head.
    new_node->doublyPrev->doublyNext = *head;
}

void CDL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode *new_node = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (*head == NULL) {
        // The pointers of new_node are self-referencing, and head is assigned to new_node.
        new_node->doublyNext = new_node;
        new_node->doublyPrev = new_node;
        *head = new_node;
        return;
    }

    struct doublyNode *last_node = (*head)->doublyPrev;

    // The pointers of new_node are assigned.
    new_node->doublyNext = *head;
    new_node->doublyPrev = last_node;

    // The next of the last element and the previous of the first element become new_node.
    last_node->doublyNext = new_node;
    (*head)->doublyPrev = new_node;
}

void CDL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    // TODO
    // If the previous node is NULL, print an error message and return.
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;   
    }
    // Assign the pointers of newNode.
    newNode->doublyNext = prevNode->doublyNext;
    newNode->doublyPrev = prevNode;

    // Update the next of prevNode and the previous of prevNode's next to newNode.
    prevNode->doublyNext = newNode;
    newNode->doublyNext->doublyPrev = newNode;
}

void CDL_deleteAtBeginning(struct doublyNode** head) 
{
    // TODO
    // If the list is empty, print an error message and return.
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    // If the list has only one element, delete the head.
    else if ((*head)->doublyNext == (*head)) {
        free(*head);
        *head = NULL;
        return;
    }

    struct doublyNode *last_node = (*head)->doublyPrev;

    // Update the head and delete the first element.
    *head = (*head)->doublyNext;
    free(last_node->doublyNext);

    // Update the next of the last element and the previous of the new head.
    last_node->doublyNext = *head;
    (*head)->doublyPrev = last_node;
}

void CDL_deleteAtEnd(struct doublyNode** head) 
{
    // TODO
    // If the list is empty, print an error message and return.
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    } 
    // If the list has only one element, delete the head.
    else if ((*head)->doublyNext == (*head)) {
        free(*head);
        *head = NULL;
        return;
    }
    // Get the second last node as last_node.
    struct doublyNode *last_node = (*head)->doublyPrev->doublyPrev;
    
    // Delete the last element.
    free(last_node->doublyNext);

    // Update the next of the second last node and the previous of the head.
    last_node->doublyNext = *head;
    (*head)->doublyPrev = last_node;
}

void CDL_deleteAfterNode(struct doublyNode* head, int targetID) 
{
    // TODO
    // If the list is empty, print an error message and return.
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    // If the list has only one element and its ID matches the target ID, delete the head.
    else if (head->doublyNext == head && head->id == targetID) {
        free(head);
        head = NULL;
        return;
    }

    // Search for the node with the target ID.
    struct doublyNode *node = searchCircularDoublyNode(head, targetID);
    if (node == NULL) {
        printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
        return;
    }
    // If the node to be deleted is the last node, update the head and delete the node.
    else if (node->doublyNext == head) {
        head = head->doublyNext;
        free(node->doublyNext);

        // Update the previous of the new head.
        node->doublyNext = head;
        head->doublyPrev = node;
    }
    else {
        // Update the node and delete the target node.
        node->doublyNext = node->doublyNext->doublyNext;
        free(node->doublyNext->doublyPrev);

        // Update the previous of the next node.
        node->doublyNext->doublyPrev = node;
    }
}


void printDoublyCircularList(struct doublyNode* head)
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct doublyNode *current = head;
    printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);

    while(current->doublyNext != head) {
        current = current->doublyNext;
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
    } 
}


struct doublyNode* searchCircularDoublyNode(struct doublyNode* head, int id) 
{
    // TODO
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct doublyNode *curr = head;

    while (curr->doublyNext != head && curr->id != id) curr = curr->doublyNext;

    if (curr->id == id) return curr;
    else {
        printf("Node with ID %d not found in the list, cannot delete.\n", id);
        return NULL;
    }
}