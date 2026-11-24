#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed\n");
}

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void displayStack()
{
    struct node *temp = top;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted\n");
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct node *temp = front;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");
        printf("\n4. Enqueue");
        printf("\n5. Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: displayStack();
                    break;

            case 4: enqueue();
                    break;

            case 5: dequeue();
                    break;

            case 6: displayQueue();
                    break;

            case 7: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}



