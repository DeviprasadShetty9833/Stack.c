#include <stdio.h>

#include <stdlib.h>

// Node structure

typedef struct Node {

int data;

struct Node *next;

} Node;

// Function to create a new node

Node* createNode(int data) {

Node *newNode = (Node*)malloc(sizeof(Node));

newNode->data = data;

newNode->next = NULL;

return newNode;

}

// Function to push an element onto the stack

void push(Node **top, int data) {

Node *newNode = createNode(data);

newNode->next = *top;

*top = newNode;

printf("%d pushed onto stack\n", data);

}

// Function to pop an element from the stack

int pop(Node **top) {

if (*top == NULL) {

printf("Stack Underflow! Cannot pop.\n");

return -1;

}

Node *temp = *top;

int poppedData = temp->data;

*top = (*top)->next;

free(temp);

printf("%d popped from stack\n", poppedData);

return poppedData;

}

// Function to peek at the top element of the stack

int peek(Node *top) {
