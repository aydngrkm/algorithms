#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#define MAX_SIZE 10
#define INPUT_SIZE 1

int main() {
    struct person removed_member_customer;
    struct person removed_member_noncustomer;
    
    char input[INPUT_SIZE];
    scanf("%s", input);
    int case_no = atoi(input);

    switch(case_no)
    {
        case 1:
            printf("Using customer and non-customer queues:\n");
            printf("---------------------------------------\n");
            // TODO:
            // Create two queues of type queue, named customer and non-customer, 
            // and do as requested in the assignment document:

            // Create empty customer and non-customer queues of size 5 each
            struct queue *bankQueueCustomer = create(5);
            struct queue *bankQueueNonCustomer = create(5);

            // First, 4 non-customers come to the bank.
            printf("4 non-customers are added to non-customer queue:\n");

            struct person nonCustomers[4];
            for (int i = 0; i < 4; ++i) {
                nonCustomers[i].isClient = 0;
                nonCustomers[i].money = ((i+1) * 100);
                add(bankQueueNonCustomer, nonCustomers[i]);
            }

            printf("Customer queue:\n");
            display_all(bankQueueCustomer);

            printf("Non-customer queue:\n");
            display_all(bankQueueNonCustomer);
            printf("\n");

            // Then 2 people who are customers come in.
            struct person customers[2];
            for (int i = 0; i < 2; ++i) {
                customers[i].isClient = 1;
                customers[i].money = ((i+1) * 100) + 400;
                add(bankQueueCustomer, customers[i]);
            }

            printf("2 customers are added to customer queue:\n");
            printf("Customer queue:\n");
            display_all(bankQueueCustomer);

            printf("Non-customer queue:\n");
            display_all(bankQueueNonCustomer);
            printf("\n");

            // Then 3 people take turns at the bank and exit their queues. 
            // But here, first the queue of customers will be empty, 
            // then the queue of non-customers will start to be processed.  
            // Therefore, until there are no more people in the customer queue, 
            //the customers will take turns to do their bank transactions
            int counter = 3;
            while (counter > 0 && is_empty(bankQueueCustomer) == 0) {
                remove_person(bankQueueCustomer);
                --counter;
            }
            while (counter > 0 && is_empty(bankQueueNonCustomer) == 0) {
                remove_person(bankQueueNonCustomer);
                --counter;
            }

            printf("3 people exit the queue (2 customer, 1 non-customer):\n");
            printf("Customer queue:\n");
            display_all(bankQueueCustomer);

            printf("Non-customer queue:\n");
            display_all(bankQueueNonCustomer);
            printf("\n");

            break;
      
        case 2:
            printf("Using solely one queue:\n");
            printf("------------------------\n");

            // TODO
            // Create a queue of type queue, 
            // do the things requested in the assignment document

            // Create an empty queue of size 10
            struct queue *bankQueue = create(10);
            // Add 5 non-customers to queue
            struct person non_customer1 = {0, 700};
            struct person non_customer2 = {0, 800};
            struct person non_customer3 = {0, 800};
            struct person non_customer4 = {0, 1050};
            struct person non_customer5 = {0, 1100};

            add(bankQueue, non_customer1);
            add(bankQueue, non_customer2);
            add(bankQueue, non_customer3);
            add(bankQueue, non_customer4);
            add(bankQueue, non_customer5);

            printf("5 non-customers are added to queue:\n");
            display_all(bankQueue);
            printf("\n");

            // Add 2 bank customers to the queue.
            struct person customer1 = {1, 550};
            struct person customer2 = {1, 1000};

            add_customer(bankQueue, customer1);
            add_customer(bankQueue, customer2);

            printf("2 customers are added to queue:\n");
            display_all(bankQueue);
            printf("\n");


            // Add 4 new non-customers to the queue 
            // (Note that it will give an error if the queue is full)
            struct person non_customer6 = {false, 12000};
            struct person non_customer7 = {false, 1300};
            struct person non_customer8 = {false, 1400};
            struct person non_customer9 = {false, 1600};
            
            add(bankQueue, non_customer6);
            add(bankQueue, non_customer7);
            add(bankQueue, non_customer8);
            add(bankQueue, non_customer9);

            printf("4 non-customers are added to queue:\n");
            display_all(bankQueue);
            printf("\n");

            // First remove 2 people from the queue. 
            for (int i = 0; i < 2; ++i) remove_person(bankQueue);

            printf("2 people are removed from the queue:\n");
            display_all(bankQueue);
            printf("\n");

            // Then add 1 non-bank customer
            add(bankQueue, non_customer9);
            
            printf("1 non-customers are added to queue:\n");
            display_all(bankQueue);
            printf("\n");

            break;
    }
    return 0;
}
