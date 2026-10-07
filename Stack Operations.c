


#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push()
{
    int value;
    if(top==MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    printf("Enter value to be pushed: ");
    scanf("%d",&value);
    top++;
    stack[top]=value;
    printf("Element pushed successfully");
    return;
}
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
        return;
    }
    printf("%d is popped from the stack.",stack[top]);
    top=top-1;
    return;
}
void display()
{
    int i;
    if(top==i)
    {
        printf("Stack is empty!");
        return;
    }
    printf("Stack elements (TOP TO BOTTOM) are ");
    for(i=top;i>=0;i--)
    {
        printf("\n%d",stack[i]);
    }
    return;
}
int main()
{
    int choice;
    printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
    while(1)
    {
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting Program...\n");
            return 0;
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

