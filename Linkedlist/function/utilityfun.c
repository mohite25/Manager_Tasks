#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
void Push(struct node** headRef, int newData){
	/*step 1: create a new node*/
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	/*step 2: Assign new data to the new node and link it to the current head*/
	newNode->data = newData;
	newData->next = *headRef;
	
	/*Update the head to point to the new node*/
	*headRef = newNode;
	
}/*End Push()*/

