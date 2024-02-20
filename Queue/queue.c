#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

struct queue *create(int capacity) 
{
    struct queue *new_queue = malloc(sizeof(struct queue));
    new_queue->people = malloc(sizeof(struct person) * (capacity));
    new_queue->capacity = capacity;
    new_queue->front = 0;
    new_queue->rear = 0;
    new_queue->size = 0;

    return new_queue;
}

bool is_full(struct queue *q) 
{
    return (q->size == q->capacity);
}


bool is_empty(struct queue *q) 
{
    return (q->size == 0);
}

void add(struct queue *q, struct person k) 
{
    if (is_full(q)) {
        printf("Queue is full, failed to add person.\n");
        return;
    }

    if (is_empty(q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % q->capacity;

    (q->people)[q->rear] = k;
    ++(q->size);
}


struct person remove_person(struct queue *q) 
{
    if (is_empty(q)) {
        printf("Queue is empty, cannot be removed.\n");
        struct person nullperson = {0, -1.0};

        return nullperson;
    }

    struct person popped = (q->people)[q->front];
    q->front = (q->front + 1) % q->capacity;

    --(q->size);
    if(is_empty(q)) q->front = q->rear = 0;
    
    return popped;
}


void shift_all(struct queue *q) 
{
    if (is_empty(q)) {
        printf("Queue is empty, cannot be shifted.\n");
        return;
    }
    else if (is_full(q)) {
        printf("Queue is full, cannot be shifted.\n");
        return;
    }

    if (q->front == 0) q->front = q->capacity - 1;
    else --(q->front);
}


void add_customer(struct queue *q, struct person k) 
{
    if (is_full(q)) {
        printf("Queue is full, failed to add person.\n");
        return;
    }
    if (is_empty(q)) q->front = q->rear = 0;
    else shift_all(q);
        
    (q->people)[q->front] = k;
    ++(q->size);
}


void display_all(struct queue *q) 
{
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue Status:\n");
    
    int idx = q->front;
    while (idx != q->rear) {
        printf("Is Client: %s, Money: %.2f\n", q->people[idx].isClient ? "Yes" : "No", q->people[idx].money);

        idx = (idx + 1) % q->capacity;
    }
    printf("Is Client: %s, Money: %.2f\n", q->people[idx].isClient ? "Yes" : "No", q->people[idx].money);
}
