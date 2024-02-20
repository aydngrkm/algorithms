#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "priorityqueues.h"

void print_heap(int *arr, int size)
{
    for (int i = 0; i < size && arr[i] != INT_MIN; ++i) printf("%d ", arr[i]);
}

void max_heapify_recursive(int *arr, int index, int size) 
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && arr[index] < arr[left]) largest = left;
    if (right < size && arr[largest] < arr[right]) largest = right;

    if (largest != index) {
        SWAP(arr[index], arr[largest]);
        max_heapify_recursive(arr, largest, size);
    }
}

void build_max_heap(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i) max_heapify_recursive(arr, i, size);
}

int extractMax(int *arr, int size) 
{
    if (size < 0 || arr[0] == INT_MIN) {
        printf("Heap is empty.\n");
        return INT_MIN;
    }

    int ret_val = arr[0];
    int last = size - 1;
    while (last > 0 && arr[last] == INT_MIN) --last;

    arr[0] = arr[last];
    arr[last] = INT_MIN;

    max_heapify_recursive(arr, 0, size);
    return ret_val;
}

void bubbleUp(int *arr, int index)
{
    if (index <= 0) {
        printf("Invalid index to bubble up.\n");
        return;
    }

    int parent = (index-1) / 2;
    while (index > 0 && arr[parent] < arr[index]) {
        SWAP(arr[parent], arr[index]);
        index = parent;
        parent = (parent - 1) / 2;
    }
}

void insertData(int *arr, int data) 
{
    int last = SIZE - 1;
    while (last >= 0 && arr[last] == INT_MIN) --last;

    arr[last+1] = data;
    bubbleUp(arr, last+1);
}

void removeIndex(int *arr, int index) 
{
    if (index < 0) {
        printf("Invalid index to remove element.\n");
        return;
    }

    arr[index] = INT_MAX;

    bubbleUp(arr, index);
    extractMax(arr, SIZE);
}

void changePriority(int *arr, int index, int priority) 
{
    if (index < 0) {
        printf("Invalid index to change priority.\n");
        return;
    }

    if (arr[index] < priority) {
        arr[index] = priority;
        bubbleUp(arr, index);
    }
    else if (arr[index] > priority) {
        arr[index] = priority;
        max_heapify_recursive(arr, index, SIZE);
    }
}
