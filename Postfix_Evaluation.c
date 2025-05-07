//Postfix Evaluation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int stack[20];
int top=-1;

void push(int);
int pop();

void main()
{
	char post[50],sc;
	int i,l,val[50],p1,p2;
	printf("\nEnter valid postfix expression: ");
	gets(post);
	l=strlen(post);
	for(i=0;i<l;i++)
	{
		if(isalpha(post[i]))
		{
			printf("\nEnter valur of %c",post[i]);
			scanf("%d",&val[i]);
		}
	}
	
	for(i=0;i<l;i++)
	{
		if(isalpha(post[i]))
		{
			push(val[i]);
		}
		else
		{
			p1=pop();
			p2=pop();
			switch(post[i])
			{
				case '^':
					push(pow(p2,p1));
					break;
				case '/':
					push(p2/p1);
					break;
				case '*':
					push(p2*p1);
					break;
				case '+':
					push(p2+p1);
					break;
				case '-':
					push(p2-p1);
					break;
			}
		}
	}
	printf("\n\t Answer is %d ",pop());
}

void push(int x)
{
	top++;
	stack[top]=x;
}

int pop()
{
	int x;
	x=stack[top];
	top--;
	return x;
}
