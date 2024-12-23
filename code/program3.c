#include <stdio.h>
#include <stdlib.h>
#define max 3

int front=-1, rear=-1, i, queue[10], ch, item;

void insert();
int del();
void display();

void main()
{
    while (1)
    {
        printf("\n1. INSERT \n2. DELETE \n3. DISPLAY \n4. EXIT \nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert();
                    break;
            case 2: item=del();
                    if (item!=-1)
                    {
                        printf("The Deleted Item is:%d\n", item);
                    } break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    }
}

void insert()
{
    if (rear==max-1)
    {
        printf("Queue is Full \n");
        return;
    }
    printf("Enter Element: \n");
    scanf("%d",&item);
    if (rear ==-1 && front ==-1)
    {
        rear=0;
        front=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=item;
    return;
}

int del()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    item=queue[front];

    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=front+1;
    }
    return item;
}

void display()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is Empty \n");
        return;
    }
    printf("The Elements of the Queue are: \n");
    for (i=front;i<=max-1;i++)
    {
        printf("%d \n", queue[i]);
    }
    return;
}
