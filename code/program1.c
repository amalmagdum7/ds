#include<stdio.h>
#include<stdlib.h>
int stack[10],top=-1,i,item;
#define max 3

void push(){
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        printf("Enter Element to Push: ");
        scanf("%d",&item);
        stack[top]=item;
    }
}

int pop(){
    if (top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    item=stack[top];
    top=top-1;
    return (item);
}

void display(){
    if (top==-1){
        printf("Stack Empty\n");
    }
    else{
        printf("The Stack is: \n");
        for(i=top;i>-1;i--){
            printf("%d\n",stack[i]);
        }
    }
}

void main(){
    while(1){
        int userInput;
        printf("Enter option: \n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&userInput);
        switch(userInput){
            case 1: push();
                break;
            case 2: item=pop();
                if(item!=-1){
                    printf("The Popped Element is: %d \n",item);
                }
                break;
            case 3: display();
                break;
            case 4: exit(0);
                break;
        }
    }
}
