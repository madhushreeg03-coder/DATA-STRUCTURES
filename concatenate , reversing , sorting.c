
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void sortList(struct Node *head) {
    struct Node *temp, *current;
    int swap;

    for (temp = head; temp != NULL; temp = temp->next) {
        for (current = temp->next; current != NULL; current = current->next) {
            if (temp->data > current->data) {
                swap = temp->data;
                temp->data = current->data;
                current->data = swap;
            }
        }
    }
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node *head1, *head2;

    printf("\nCreate First Linked List\n");
    head1 = createList();

    printf("\nCreate Second Linked List\n");
    head2 = createList();

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);

    sortList(head1);
    printf("\nSorted First Linked List:\n");
    display(head1);

    head1 = reverseList(head1);
    printf("\nReversed First Linked List:\n");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("\nConcatenated Linked List:\n");
    display(head1);

    return 0;
}
