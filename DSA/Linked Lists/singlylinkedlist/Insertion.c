/*There are the several type of the inserition in the linkedlist 
1)Insert at the beggining) O(1)
2)Insert at the between O(n)
3)Insert at the end O(n)
4)Insert at the after the given nodeO(1)
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedlistt(struct Node * ptr){
    while (ptr!=NULL){
        printf("Elements : %d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node * insertAtfirst(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    head = ptr; 
}

struct Node * insertAtbetween(struct Node* head, int data, int index){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while(i != index -1)
    {
        p = p-> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p-> next = ptr;
    return head;
    
}


struct Node * insertAtend(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node * p = head;

    while(p->next != NULL)
    {
        p = p->next; 
    }
    p->next = ptr;
    ptr -> next = NULL;
    return head;
    
}


struct Node* insertAfter(struct Node * head, struct Node *prevNode,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;

    ptr -> next = prevNode -> next;
    prevNode->next = ptr;
    return head;

}

 

int main(){

struct Node * head;
struct Node * middle;
struct Node * last;

head = (struct Node *) malloc (sizeof ( struct Node));
middle= (struct Node * ) malloc (sizeof (struct Node));
last = (struct Node * ) malloc (sizeof ( struct Node));

head -> data = 1;
middle-> data = 2;
last ->data = 3;

head -> next = middle;
middle -> next = last;
last -> next = NULL;

printf("Linked list before insertion :\n");
linkedlistt(head);
//head = insertAtfirst(head, 11);
//head = insertAtbetween(head, 43, 2);
printf("Linked list after insertion : \n");
//head = insertAtend(head, 34);
head = insertAfter(head, last, 44);
linkedlistt(head);
return 0;

}