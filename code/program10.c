#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *start = NULL, *temp, *new1, *curr;
int ch;
char c;

void createList();
void sort();
void reverse();
void display();
void concatenate();

void createList() {
    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter Value: ");
        scanf("%d", &new1->data);
        new1->link = NULL;

        if (start == NULL) {
            start = new1;
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
        printf("The Linked List is Empty.\n");
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
    printf("Linked List is Sorted.\n");
}

void reverse() {
    node *a = start, *b = NULL;
    while (a != NULL) {
        temp = a->link;
        a->link = b;
        b = a;
        a = temp;
    }
    start = b;
    printf("Linked List is Reversed.\n");
}

void display() {
    if (start == NULL) {
        printf("Linked list is Empty\n");
        return;
    }

    temp = start;
    printf("Elements in Linked List:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void concatenate() {
    node *start2 = NULL, *curr2 = NULL;

    printf("Enter the second linked list:\n");
    createList();

    do {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter value for second list: ");
        scanf("%d", &new1->data);
        new1->link = NULL;

        if (start2 == NULL) {
            start2 = new1;
            curr2 = new1;
        } else {
            curr2->link = new1;
            curr2 = new1;
        }
        printf("Do you want to add another element (Y/N): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');

    if (start == NULL) {
        start = start2;
    } else {
        temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = start2;
    }
    start2 = NULL;
    printf("Lists concatenated successfully.\n");
}

int main() {
    while (1) {
        printf("\n1. Create 1st Linked List\n2. Sort Linked List\n3. Reverse Linked List\n4. Concatenate Linked Lists\n5. Display Linked List\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                createList();
                break;
            case 2:
                sort();
                break;
            case 3:
                reverse();
                break;
            case 4:
                concatenate();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
