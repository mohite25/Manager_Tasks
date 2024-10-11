#ifndef HEADER_H
#define HEADER_H

#define MAX 100

typedef struct {
    int arr[MAX];
    int max;
    int size;
} LIST;

void insert(int j, int it, LIST *pl);
void delete(int j, LIST *pl);

#endif

