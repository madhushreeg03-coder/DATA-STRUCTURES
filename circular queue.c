
#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int item;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = item;

    printf("Element inserted\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element = %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert();
                    break;

            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: return 0;

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
