#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct person {
    bool isClient; 
    float money;     
};

struct queue {
    int front, rear, size;
    int capacity;
    struct person *people;
};

struct queue *create(int capacity);
bool is_full(struct queue *q) ;
bool is_empty(struct queue *q) ;
void add(struct queue *q, struct person k);
struct person remove_person(struct queue *q) ;
void shift_all(struct queue *q);

void add_customer(struct queue *q, struct person k);
void display_all(struct queue *q) ;

#endif // QUEUE_H
