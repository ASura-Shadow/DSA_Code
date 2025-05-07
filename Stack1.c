#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int pop();
void push();
void peek();
void display();
int stack[MAX];
int top = -1;
int main()
{
    
    //char ch;
    int choice;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
            push();
            break;
        case 2:
            pop();

            break;
        case 3:
            peek();

            break;
        case 4:
            display();
            break;
		case 5:
			exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void push()
{

    if (top == MAX - 1)
    {
        printf("Stack is full ");
        return ;
    }
    else
    {
        int temp;
        printf("Enter the Element : ");
        scanf("%d", &temp);
        top++;
        stack[top] = temp;
    }
}
int pop()
{
    int temp;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    else
    {
        temp = stack[top];
        top--;
    }
    return temp;
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    else
    {
        printf("Stack Element : ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty! Cannot peek\n");
        return;
    }
    else
    {
        printf("%d", stack[top]);
    }
}
