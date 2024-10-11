#include "header.h"

void insert(int j, int it, LIST *pl) {
    int i;
    for (i = pl->size; i >= j; i--) {
        pl->arr[i + 1] = pl->arr[i];  // Create the gap
    }
    pl->arr[j] = it;  // Insert the new element into the gap
    pl->size = pl->size + 1;  // Update the size
}

void delete(int j, LIST *pl) {
    int i;
    for (i = j; i < pl->size - 1; i++) {
        pl->arr[i] = pl->arr[i + 1];  // Shift elements to the left to close the gap
    }
    pl->size = pl->size - 1;  // Update the size
}

