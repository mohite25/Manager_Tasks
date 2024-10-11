/*find the index value of the occurred value
* 4 october 2024
* Author : Pruthviraj 165490
*/
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};
// Utility function to add a new node at the head of the list
void Push(struct node** headRef, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    newNode->data = newData;  // Set the data in the new node
    newNode->next = *headRef; // Link the new node to the existing list
    *headRef = newNode;       // Change the head to point to the new node
}
// Given a linked list and an index, return the data at the nth node of the list
int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 0;
    
    // Traverse the list until we reach the desired index
    while (current != NULL) {
        if (count == index) {  // If the current node is the one at the desired index
            return current->data;
        }
        count++;
        current = current->next;  // Move to the next node
    }
    
    // If we reach here, the index is out of bounds
    printf("Error: Index %d is out of bounds.\n", index);
    exit(1); // Terminate the program
}
// Function to build a simple list {1, 2, 3}
struct node* BuildOneTwoThree() {
    struct node* head = NULL;  // Start with an empty list
    Push(&head, 3);  // Add elements to the list
    Push(&head, 2);
    Push(&head, 1);
    return head;
}

// Test function to demonstrate GetNth usage
void GetNthTest() {
    struct node* myList = BuildOneTwoThree();  // build {1, 2, 3}
    int index = 2;
    int lastNode = GetNth(myList, index);  // Get the element at index 2
    printf("Element at index %d is: %d\n", index, lastNode);  // Should print "Element at index 2 is: 3"
}

int main() {
    GetNthTest();  // Run the test function
    return 0;
}

