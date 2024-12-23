PROGRAM 1:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;

//Stack
node *top = NULL;

void push();
void pop();
void displayStack();

void push() {
    node *new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("\nStack Overflow.\n");
        return;
    }

    printf("\nEnter Value to Push: ");
    scanf("%d", &new1->data);
    new1->link = top;
    top = new1;
}

void pop() {
    if (top == NULL) {
        printf("\nStack Underflow.\n");
        return;
    }

    node *temp = top;
    printf("\nPopped Element: %d\n", temp->data);
    top = top->link;
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("\nThe Stack is Empty.\n");
        return;
    }

    printf("\nElements in the Stack: ");
    node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


//Queue
node *front = NULL, *rear = NULL;

void insert();
void del();
void displayQueue();

void insert() {
    node *new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("\nQueue Full.\n");
        return;
    }

    printf("\nEnter Value to Insert: ");
    scanf("%d", &new1->data);
    new1->link = NULL;

    if (rear == NULL) {
        front = rear = new1;
        return;
    }
    rear->link = new1;
    rear = new1;
}

void del() {
    if (front == NULL) {
        printf("\nQueue Empty.\n");
        return;
    }

    node *temp = front;
    printf("\nDeleted Element: %d\n", temp->data);
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("\nThe Queue is Empty.\n");
        return;
    }

    printf("\nElements in the Queue: ");
    node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


// Main
void main(){
    int ch;

    while (1) {
        printf("\n1. Push (Stack) \n2. Pop (Stack) \n3. Display (Stack)");
        printf("\n4. Insert (Queue) \n5. Delete (Queue) \n6. Display (Queue) \n7. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                insert();
                break;
            case 5:
                del();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("\nEnter Your Choice: \n");
        }
    }
}


PROGRAM 2:
#include <stdio.h>
#include <stdlib.h>  


struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *start1 = NULL, *start2 = NULL, *a, *b = NULL, *temp, *new1, *curr, *start;


void create1();
void create2();
void concatenate();
void reverse();
void display();
void sort();
int ch;
char c;

void main() {
    while (1) {
        printf("\n1. Create 1st linked list\n2. Create 2nd linked list\n3. Sort\n4. Concatenate\n5. Reverse\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create1();
                break;
            case 2:
                create2();
                break;
            case 3:
                sort();
                break;
            case 4:
                concatenate();
                break;
            case 5:
                reverse();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}


void create1() {
    do {
        new1 = (node*)malloc(sizeof(node));  
        printf("Enter value: ");
        scanf("%d", &new1->data);
        new1->link = NULL;  

        if (start1 == NULL) {
            start1 = new1;  
            curr = new1;
        } else {
            curr->link = new1;  
            curr = new1;
        }
        printf("Do you want to add another element (Y/N): ");
        scanf(" %c", &c);  
    } while (c == 'y' || c == 'Y');
}


void create2() {
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter value: ");
        scanf("%d", &new1->data);
        new1->link = NULL;

        if (start2 == NULL) {
            start2 = new1;
            curr = new1;
        } else {
            curr->link = new1;
            curr = new1;
        }
        printf("Do you want to add another element (Y/N): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
}

void sort() {
    if (start == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    node *i, *j;
    int tempData;
    for (i = start; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("Linked list sorted successfully.\n");
}

void display() {
    if (start == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    temp = start;
    printf("Elements in the linked list are:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


void concatenate() {
    if (start1 == NULL && start2 == NULL) {
        printf("Both linked lists are empty\n");
        return;
    }
    if (start1 == NULL) {
        start = start2;
        return;
    }
    if (start2 == NULL) {
        start = start1;
        return;
    }

    temp = start1;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = start2;  
    start = start1;  
    start1 = NULL;  
    start2 = NULL;
}

void reverse() {
    a = start;
    b = NULL;
    while (a != NULL) {
        temp = a->link;
        a->link = b;
        b = a;
        a = temp;
    }
    start = b;  
}
