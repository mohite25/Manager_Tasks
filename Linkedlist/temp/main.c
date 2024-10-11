#include <stdio.h>
#include "header.h"

int main() {
    LIST myList;
    myList.size = 0;
    myList.max = MAX;

    // Insert some elements into the list
    insert(0, 10, &myList);
    insert(1, 20, &myList);
    insert(2, 30, &myList);

    // Print the list before deletion
    printf("List before deletion: ");
    for (int i = 0; i < myList.size; i++) {
        printf("%d ", myList.arr[i]);
    }
    printf("\n");

    // Delete the element at index 1
    delete(1, &myList);

    // Print the list after deletion
    printf("List after deletion: ");
    for (int i = 0; i < myList.size; i++) {
        printf("%d ", myList.arr[i]);
    }
    printf("\n");

    return 0;
}
