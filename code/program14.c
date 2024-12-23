#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;
node *start = NULL;
node *new1, *curr, *ptr;

void create();
void display();
void InsertLeft();
void DeleteSpecificElement();

void main() {
    int ch;
    while (1) {
        printf("\n1. Create \n2. Display \n3. Insert Left \n4. Delete Specific Element \n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create();
                break;
            case 2: display();
                break;
            case 3: InsertLeft();
                break;
            case 4: DeleteSpecificElement();
                break;
            case 5: exit(0);
        }
    }
}

void create() {
    char ch;

    do {
        new1 = (node*)malloc(sizeof(node));
        printf("\nEnter Value: ");
        scanf("%d", &new1->data);
        new1->left = NULL;
        new1->right = NULL;

        if (start == NULL) {
            start = new1;
            curr = new1;
        } else {
            curr->right = new1;
            new1->left = curr;
            curr = new1;
        }

        printf("Do You Want to Add an Element (Y/N)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display() {
    if (start == NULL) {
        printf("\nLinked List is Empty.");
        return;
    }

    ptr = start;
    printf("\nElements in Linked List: \n");

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}

void InsertLeft() {
    int val;
    printf("\nEnter Value: ");
    scanf("%d", &val);

    new1 = (node*)malloc(sizeof(node));
    new1->data = val;
    new1->left = NULL;
    new1->right = NULL;

    printf("\nEnter the Value to Insert Left of: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->right;
    }

    if (ptr != NULL) {
        new1->right = ptr;
        new1->left = ptr->left;
        if (ptr->left != NULL) {
            ptr->left->right = new1;
        }
        ptr->left = new1;
        if (ptr == start) {
            start = new1;
        }
    } else {
        printf("\nValue not found.\n");
    }
}

void DeleteSpecificElement() {
    int value;
    printf("\nEnter Value to Delete: ");
    scanf("%d", &value);

    ptr = start;
    while (ptr != NULL && ptr->data != value) {
        ptr = ptr->right;
    }

    if (ptr == NULL) {
        printf("\nValue not found.\n");
        return;
    }

    if (ptr->left != NULL) {
        ptr->left->right = ptr->right;
    }
    if (ptr->right != NULL) {
        ptr->right->left = ptr->left;
    }
    if (ptr == start) {
        start = ptr->right;
    }

    free(ptr);
    printf("\nElement with value %d deleted.\n", value);
}
