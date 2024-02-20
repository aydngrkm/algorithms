#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 29 

/* A simple hash calculation function for strings.
    * The ASCII value of each letter is one of the previous hash value.
    * is added to the multiplier.
    * For example: for the string "abcde":
    * ascii values: a=97, b=98,c=99,d=100,e=101
    *h0 = 0 * 29 + 97 = 97
    * h1 = h0 * 29 + 98 = 2911
    *h2 = h1 * 29 + 99 = 84518
    *h3 = h2 * 29 + 100 = 2451122
    *h4 = h3 * 29 + 101 = 71082639
    * 71082639% MAXBUCKETS (1000) = 639
*/
unsigned long hash_compute(const char *str){
    // TODO: Write the function according to the explanations above
    unsigned long val = 0;
    while (*str) {
        val = (val * MULTIPLIER) + *str;
        ++str;
    }

    return val % MAXBUCKETS;
}

/* A table array, each element of which is a 
    * linked list pointer, is given as a parameter.
    * This table array actually represents the
    * hash data structure.
    *
    * If the string given with str exists in the hash, 
    * its address is frozen.
    * If not and create == 1, this string is added to 
    * the hash data structure.
*/
Key* hash_lookup(Key **table,const char *str,int create){
    // TODO: call hash function for str

    // lookup the value in the hash table
    // if value is found, return that variable.
    unsigned long idx = hash_compute(str);
    Key *curr = table[idx];
    while (curr) {
        if (strcmp(curr->word, str) == 0) return curr;
        curr = curr->next;
    }
    // if there is no value and an addition is to be made
    if(create) {
        // Make space in memory for the value to be added
        // if memory space is freed
        // make count, word, next assignments for the new element
        //return the newly added element
        Key *new_key = malloc(sizeof(Key));
        new_key->word = strdup(str);
        new_key->count = 0;
        new_key->next = table[idx];

        table[idx] = new_key;
        return new_key;
    }

    return NULL;
}


/* Function that returns the hash data structure given by 
* table to the operating system. 
* While cleaning, you need to free() the nodes of each 
* linked list and the "word" member in these nodes.
*/
void hash_free(Key **table){
    for (int i = 0; i < MAXBUCKETS; ++i) {
        Key *curr = table[i];

        while (curr) {
            Key *temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
        table[i] = NULL;
    }
}


/* Function that prints words with count parameter >= n on the screen. 
* When printing to the screen, use the format "%30s-->%5ld\n".
* %ld: required for unsigned long.
*/
void hash_dump(Key **table,int n){
    for (int i = 0; i < MAXBUCKETS; ++i) {
        Key *curr = table[i];

        while (curr) {
            if (curr->count >= n) {
                printf("%30s-->%5ld\n", curr->word, curr->count);
            }
            curr = curr->next;
        }
    }
}