#include <stdio.h>
#include <stdlib.h> // Include the standard library header for memory allocation.

// Define a structure for a linked list node.
struct Node {
    int data;         // Data stored in the node.
    struct Node* next; // Pointer to the next node.
};

void linkedlistraversal(struct Node * ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr -> next;
    }
}

int main() {
    // Declare pointers for the head, middle, and last nodes.
    struct Node* head;
    struct Node* second;
    struct Node * third;

    // Allocate memory for the head, middle, and last nodes.
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Set data values for each node.
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect the nodes to form a linked list.
    head->next = second;
    second->next = third;
    third->next = NULL; // Mark the end of the list by setting the 'next' pointer to NULL.

    // Initialize a temporary pointer to traverse the list, starting from the head.
    //struct Node* temp = head;

    // Traverse the list and print the data in each node.
    //while (temp != NULL) {
       // printf("%d ", temp->data); // Print the data.
       // temp = temp->next; // Move to the next node.
    //}


    linkedlistraversal(head);

    // Free the allocated memory to prevent memory leaks.
    free(head);
    free(second);
    free(third);
  return 0;
}