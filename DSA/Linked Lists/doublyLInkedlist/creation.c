#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*prev;
    int data ;
    struct node *next;
};

struct node*addempty(struct node * head, int data){
    struct node * temp = (struct node * )malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp-> next = NULL;
    temp -> data = data;
    head = temp;
    return head;
}

struct node*addbeg(struct node*head,int data){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev= NULL;
    temp->data= data;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;

}

struct node*addend(struct node*head,int data){
    struct node*temp ,*tp;
    temp = malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data= data;
    tp = head;
    while(tp->next !=NULL){
        tp = tp -> next;
    tp ->next = temp;
    temp->prev = tp;
    return head;
    }
}

int main(){
    // create a new linked list
    struct node*head = NULL;
    struct node*ptr;
    head = addempty(head,45);
    head = addbeg(head,34);
    head = addend(head,9);
    ptr=head;

    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
    