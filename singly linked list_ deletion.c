
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void createNode(struct Node **head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Linked List: ");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}
void deleteFromFirst(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = *head;
        *head = temp->next;
        free(temp);

        printf("Node deleted from front\n");
    }
}
void deleteFromEnd(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        printf("Node deleted from end\n");
    }
    else
    {
        temp = *head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;

        printf("Node deleted from end\n");
    }
}
void deleteAtPosition(struct Node **head, int position)
{
    struct Node *temp, *next;

    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else if (position < 1)
    {
        printf("Invalid position\n");
    }
    else if (position == 1)
    {
        deleteFromFirst(head);
    }
    else
    {
        temp = *head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Position out of range\n");
        }
        else
        {
            next = temp->next->next;
            free(temp->next);
            temp->next = next;

            printf("Node deleted at position %d\n", position);
        }
    }
}
int main()
{
    struct Node *head = NULL;

    int n, value, position, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);

        createNode(&head, value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    while (1)
    {
        printf("\n\n DELETION MENU ");
        printf("\n1. Delete at front");
        printf("\n2. Delete at end");
        printf("\n3. Delete at specified position");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deleteFromFirst(&head);
                break;

            case 2:
                deleteFromEnd(&head);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                deleteAtPosition(&head, position);
                break;

            case 4:
                printf("Exiting program...\n");
                while (head != NULL)
                {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }

                return 0;

            default:
                printf("Invalid choice\n");
        }

        printf("\nLinked List after deletion:\n");
        display(head);
    }

    return 0;
}
