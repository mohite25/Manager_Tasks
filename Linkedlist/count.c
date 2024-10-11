/*Count the ocuurance of number in linkedlist
* 3 October 2024
* Author : Pruthviraj 165490
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Push() adds a node at the head of the list
void Push(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    newNode->data = newData;   // Set the data for the new node
    newNode->next = *headRef;  // Link the new node to the current head
    *headRef = newNode;        // Update the head pointer to point to the new node
}

// Count() returns the number of occurrences of searchFor in the list
int Count(struct node* head, int searchFor) {
    int count = 0;
    struct node* current = head;
    
    // Traverse the list
    while (current != NULL) {
        if (current->data == searchFor) {  // Check if the current node's data matches searchFor
            count++;
        }
        current = current->next;  // Move to the next node
    }
    return count;
}

// BuildOneTwoThree() creates and returns the list {1, 2, 3}
struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    Push(&head, 3);  // Insert 3
    Push(&head, 2);  // Insert 2
    Push(&head, 2);  // Insert 1
    return head;
}

// CountTest() tests the Count() function and takes user input for the value to search for
void CountTest() {
    struct node* myList = BuildOneTwoThree();  // Create the list {1, 2, 3}
    
    int searchFor;
    
    // Ask user for the value to search for
    printf("Enter the number you want to count occurrences of: ");
    scanf("%d", &searchFor);
    
    // Count occurrences of the user-provided number
    int count = Count(myList, searchFor);
    
    // Display the result
    printf("Count of %d: %d\n", searchFor, count);
}

int main() {
    CountTest();  // Run the test for Count()
    return 0;
}

