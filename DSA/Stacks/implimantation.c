#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10

int stack[MAXSIZE] , top - 1;

void main(){
    int choice;
    do
    {
        printf("------------------stack------------------");
        printf("n1.push/n2.pop/n3.display/n4.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3: display();
            break;
        case 4:printf("Invalid choice!!!");
        scanf("%d",&choice);
        }}
    } while (choice ! = 4 );


void push(){
    int n;
    if(top == MAXSIZE-1)
    printf("stack is overflow");
    else{
    printf("Enter the elements in stack:");
    scanf("%d",&n);
    top++;
    stack[top]=n;
}

void display(){
    int i;
    if(top == -1)
    printf("stack is empty!!");
    else{
    printf("Elements of the stack is:");
        for (i = top; i >= 0; i--)
        {
         printf("/n%d",stack[i];)
        }}
}


void pop(){
    int n;
    if(top == -1)
    printf("stack is empty!!");
    else{
    n = stack[top];
    top--;
    printf("poped the elements.")
    }

}

    
}