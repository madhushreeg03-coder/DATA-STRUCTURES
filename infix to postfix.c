#include <stdio.h>
#include <ctype.h>
#define MAX 4
char stack[MAX];
int top = -1;
void push(char x)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = x;
    }
}
char pop()
{
    char x;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}
int precedence(char x)
{
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}
int isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}
int infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    top = -1;
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (!isalnum(symbol) && symbol != '(' && symbol != ')' && !isOperator(symbol))
        {
            printf("Invalid expression!\n");
            return 0;
        }
        else if (isalnum(symbol))
        {
            postfix[j] = symbol;
            j++;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if (top == -1)
            {
                printf("Invalid expression!\n");
                return 0;
            }
            pop();
        }
        else if (isOperator(symbol))
        {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }
        i++;
    }
    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Invalid expression!\n");
            return 0;
        }
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    return 1;
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter a valid infix expression.\n");
    printf("Allowed operators: +, -, *, /\n");
    printf("Enter expression: ");
    scanf("%99s", infix);
    if (infixToPostfix(infix, postfix))
        printf("Postfix expression: %s\n", postfix);
    return 0;
}
