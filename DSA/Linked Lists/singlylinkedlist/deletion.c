/*
*/ 
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;

};

void traversal(struct Node * ptr){
    while(ptr != NULL){
        printf("Elements of linkedlist are: %d \n", ptr->data);
        ptr = ptr ->next;
    }
}
int main(){

struct Node * head;
struct Node*middle;
struct Node * mid;
struct Node * last;

head = (struct Node*)malloc(sizeof(struct Node));
middle= (struct Node*)malloc(sizeof(struct Node));
mid= (struct Node*)malloc(sizeof(struct Node));
last = (struct Node*)malloc(sizeof(struct Node));

head -> data = 1;
middle -> data = 2;
mid ->data = 3;
last -> data = 4;

head ->next = middle;
middle -> next = mid;
mid ->next = last;
last -> next = NULL;

printf("Elements of the linked list are:\n");
traversal(head);


return 0;
}