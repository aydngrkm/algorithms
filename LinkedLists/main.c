#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlists.h"

#define INPUT_SIZE 50
#define INT_TOKEN 50

int main() 
{
    char input[INPUT_SIZE];
    char * token;
    int values[INT_TOKEN];
    int i=0;

    scanf("%s", input);
    token = strtok(input, "-");

    while (token != NULL) {

        values[i] = atoi(token);
        token = strtok(NULL, "-");
        i++;
        
    }
    
    int case_no = values[0];
    int searched_id = values[2];


    struct linearNode* head_LN = NULL;
    struct doublyNode* head_DN= NULL;

    switch (case_no)
    {
        case 1:
            ;

            if(values[1] == 1) // Insertion
            {
                printf("Insertion at Beginning\n");
                SL_insertBeginning(&head_LN, 1, "John Smith", "Susan Smith", 2020, 5555555);
                printSinglyLinearList(head_LN);
                
                printf("Insertion at end\n");
                SL_insertAtEnd(&head_LN, 2, "Emily Johnson", "Michael Johnson", 2021, 6666666);
                printSinglyLinearList(head_LN);
                
                printf("Insertion after specified node\n");
                struct linearNode *SL_searchedNode = searchSinglyNode(head_LN, searched_id);
                if (SL_searchedNode != NULL)
                {
                        SL_insertAfterNode(SL_searchedNode, createLinearNode(3, "Olivia Taylor", "Jennifer Taylor", 2019, 7777777));
                }

                printSinglyLinearList(head_LN);

            }

            if(values[1] == 2) // Insert + Deletion
            {
                SL_insertBeginning(&head_LN, 1, "Benjamin Martinez", "David Martinez", 2020, 5555555);
                SL_insertAtEnd(&head_LN, 2, "Daniel Brown", "Laura Brown", 2021, 6666666);
                SL_insertAtEnd(&head_LN, 3, "Lian Hall", "Robert Hall", 2019, 8888888);
                SL_insertAtEnd(&head_LN, 4, "Noah Brown", "Ava Brown", 2018, 7777777);

                printf("Deletion at Beginning\n");
                SL_deleteAtBeginning(&head_LN);
                printSinglyLinearList(head_LN);

                printf("Deletion at end\n");
                SL_deleteAtEnd(&head_LN);
                printSinglyLinearList(head_LN);

                printf("Deletion after specified node\n");
                int searched_id = values[2];
                struct linearNode *SL_searchedNode = searchSinglyNode(head_LN, searched_id);
                if (SL_searchedNode != NULL)
                {
                    SL_deleteAfterNode(SL_searchedNode, searched_id);
                }
                printSinglyLinearList(head_LN);
            }
            
            break;
        
        
        case 2:
        ;
            if(values[1] == 1) // Insertion
            {
                printf("Insertion at Beginning\n");
                CSL_insertBeginning(&head_LN, 1, "Alex Davis", "Susan Davis", 2020, 5555555);
                printSinglyCircularList(head_LN);
                
                printf("Insertion at end\n");
                CSL_insertAtEnd(&head_LN, 2, "Isabella Wilson", "Mallory Wilson", 2021, 6666666);
                printSinglyCircularList(head_LN);
                
                printf("Insertion after specified node\n");
                struct linearNode *CSL_searchedNode = searchCircularSinglyNode(head_LN, searched_id);
                if (CSL_searchedNode != NULL)
                {
                    CSL_insertAfterNode(CSL_searchedNode, createLinearNode(3, "Ethan Anderson", "David Anderson", 2019, 9999999));
                }

                printSinglyCircularList(head_LN);
            }

            if(values[1] == 2) // Insert + Deletion
            {
                CSL_insertBeginning(&head_LN, 1, "Mia Anderson", "Bob Anderson", 2020, 5555555);
                CSL_insertAtEnd(&head_LN, 2, "Eve Moore", "Christopher Moore", 2021, 6666666);
                CSL_insertAtEnd(&head_LN, 3, "Laura King", "Jessica King", 2019, 55555);
                CSL_insertAtEnd(&head_LN, 4, "Adam Parker", "Kevin Parker", 2018, 1111111);

                printf("Deletion at Beginning\n");
                CSL_deleteAtBeginning(&head_LN);
                printSinglyCircularList(head_LN);

                printf("Deletion at end\n");
                CSL_deleteAtEnd(&head_LN);
                printSinglyCircularList(head_LN);

                printf("Deletion after specified node\n");

                struct linearNode *CSL_searchedNode = searchCircularSinglyNode(head_LN, searched_id);
                if (CSL_searchedNode != NULL)
                {
                    CSL_deleteAfterNode(CSL_searchedNode, searched_id);
                }
                printSinglyCircularList(head_LN);
            }

            break;

        case 3:
        ;
            if(values[1] == 1) // Insertion
            {
                printf("Insertion at Beginning\n");
                DL_insertBeginning(&head_DN, 1, "Melissa Hall", "Sarah Hall", 2020, 5555555);
                printDoublyLinearList(head_DN);

                printf("Insertion at end\n");
                DL_insertAtEnd(&head_DN, 2, "Eve White", "Benjamin White", 2021, 6666666);
                printDoublyLinearList(head_DN);

                printf("Insertion after specified node\n");
                struct doublyNode *DL_searchedNode = searchDoublyNode(head_DN, searched_id);
                if (DL_searchedNode != NULL) {
                    DL_insertAfterNode(DL_searchedNode, createDoublyNode(3, "Dave Haris", "Jennifer Harris", 2010, 2222222));
                } else {
                    printf("Node with ID %d not found.\n", searched_id);
                }

                printDoublyLinearList(head_DN);
            }

            if(values[1] == 2) // Insert + Deletion
            {
                DL_insertBeginning(&head_DN, 1, "Alice Lewis", "David Lewis", 2020, 5555555);
                DL_insertAtEnd(&head_DN, 2, "Charlie Jones", "Mason Jones", 2021, 6666666);
                DL_insertAtEnd(&head_DN, 3, "Emily Williams", "Jacob Williams", 2019, 55555);
                DL_insertAtEnd(&head_DN, 4, "Ethan Smith", "Lily Smith", 2018, 3333333);

                printf("Deletion at Beginning\n");
                DL_deleteAtBeginning(&head_DN);
                printDoublyLinearList(head_DN);


                printf("Deletion at end\n");
                DL_deleteAtEnd(&head_DN);
                printDoublyLinearList(head_DN);


                printf("Deletion after specified node\n");
                
                struct doublyNode *DL_searchedNode = searchDoublyNode(head_DN, searched_id);
                if (DL_searchedNode != NULL)
                {
                    DL_deleteAfterNode(DL_searchedNode, searched_id);
                }
                printDoublyLinearList(head_DN);

            }

            break;
        case 4:
            if(values[1] == 1) // Insertion
            {
                printf("Insertion at Beginning\n");
                CDL_insertBeginning(&head_DN, 1, "Olivia Johnson", "Matthew Johnson", 2020, 5555555);
                printDoublyCircularList(head_DN);

                printf("Insertion at end\n");
                CDL_insertAtEnd(&head_DN, 2, "William Brown", "Sophia Brown", 2021, 6666666);
                printDoublyCircularList(head_DN);
                
                printf("Insertion after specified node\n");
                struct doublyNode* CDL_searchedNode = searchCircularDoublyNode(head_DN, searched_id);
                if (CDL_searchedNode != NULL)
                {
                    CDL_insertAfterNode(CDL_searchedNode, createDoublyNode(3, "Dave Thomas", "Karen Thomas", 2010, 4545454));
                }

                printDoublyCircularList(head_DN);
            }

            if(values[1] == 2) // Insert + Deletion
            {
                CDL_insertBeginning(&head_DN, 1, "Alice Scott", "Joseph Scott", 2020, 5555555);
                CDL_insertAtEnd(&head_DN, 2, "David Lewis", "Rachel Lewis", 2021, 6666666);
                CDL_insertAtEnd(&head_DN, 3, "Matthew Wilson", "Timothy Wilson", 2019, 9868974);
                CDL_insertAtEnd(&head_DN, 4, "Susan Harris", "Laura Harris", 2018, 4125637);

                printf("Deletion at Beginning\n");
                CDL_deleteAtBeginning(&head_DN);
                printDoublyCircularList(head_DN);

                printf("Deletion at end\n");
                CDL_deleteAtEnd(&head_DN);
                printDoublyCircularList(head_DN);

                printf("Deletion after specified node\n");
                
                struct doublyNode *CDL_searchedNode = searchCircularDoublyNode(head_DN, searched_id);
                if (CDL_searchedNode != NULL)
                {
                    CDL_deleteAfterNode(CDL_searchedNode, searched_id);
                }
                printDoublyCircularList(head_DN);
            }


            break;

    }


return 0;
}

