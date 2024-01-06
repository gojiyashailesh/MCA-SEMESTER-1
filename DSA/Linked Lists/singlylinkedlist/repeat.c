#include<stdlib.h>
#include<stdio.h>


struct Node {
    int data;
    struct Node * next;
};

void traversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Elements : %d\n", ptr->data);
        ptr = ptr-> next;
    }
}

struct Node*insertstart(struct Node * head, int data){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr ->data = data;
    head =ptr;
    return head;

}

struct Node*insertbetween(struct Node*head,int data , int index){
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i=0;
    while ( i !=index-1){
        p= p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr ->data = data;
    return head;

}

struct Node*insertend(struct Node*head,int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data=data;
    while(p->next!=NULL){
        p= p->next;
    }
    p->next= ptr;
    ptr->next=NULL;
    return head;
}

struct Node*insertafter(struct Node*head,struct Node* prevNode,int data){
    struct Node*ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data =data;

    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    return head;
}

int main()
{
struct Node * head;
struct Node* middle;
struct Node* last;

head =(struct Node*)malloc(sizeof(struct Node)); 
middle =(struct Node*)malloc(sizeof(struct Node)); 
last =(struct Node*)malloc(sizeof(struct Node)); 

head ->data = 10;
middle->data = 20;
last->data = 30;

head ->next = middle;
middle->next = last;
last ->next = NULL;

traversal(head);
head = insertstart(head,22);
head=insertbetween(head,33,2);
head = insertend(head,23);
head = insertafter(head, middle, 49);
traversal(head);


return 0;
}