#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedlistdemo(struct Node * ptr){
    while(ptr != NULL){
        printf("Elements : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    struct Node * head;
    struct Node * middle;
    struct Node * last;

    head = (struct Node *)malloc(sizeof(struct Node));
    middle = (struct Node *)malloc(sizeof(struct Node));
    last = (struct Node * )malloc(sizeof(struct Node));

    head -> data = 5;
    middle -> data = 6;
    last -> data = 7;

    head -> next = middle;
    middle -> next = last;
    last -> next = NULL;

    linkedlistdemo(head);

    return 0;
}