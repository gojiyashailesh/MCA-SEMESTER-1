#include<stdio.h>
#include<stdlib.h>


struct stack{
    int size;
    int top;
    int*arr;
};

//condition checks whether the stack is empty or not
int isempty(struct stack*ptr){
    if(ptr->top==-1){ 
        return 1;
    } else {
        return 0;
    }

}

//condition checks whether the stack is full or is there space in stack
int isfull(struct stack*ptr ){
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0; 
    }
}

int main(){
    struct stack *s;
    s->size = 100;
    s->top =-1;
    s->arr =(int*)malloc(s->size*sizeof(int));

    //check empty condition using printf
    if(isempty(s)){
        printf("The stack is empty");
    
    }else{
        printf("The stack is not empty");
    }

    return 0;
}