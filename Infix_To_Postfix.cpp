#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char);
char pop();
int preced(char);

int main()
{

	char sc,pc, infix[100], postfix[100];
	int l,j=0,i;
	push('(');
	printf("\nEnter a valid infix expression: ");
	gets(infix);
	
	strcat(infix,")");
	l=strlen(infix);
	for(i=0;i<l;i++)
	{
		sc=infix[i];
		
		if(sc=='(')
		{
			push(sc);
		}	
		else if(sc>=65 && sc<=90 || sc>=97 && sc<=127)
		{
			postfix[j++]=sc;
		}
		else if(sc==')')
		{
			pc=pop();
			while(pc!='(')
			{
				postfix[j++]=pc;
				pc=pop();
			}
		}
		else if(sc=='+' || sc=='-' || sc=='*' || sc=='/')
		{
			while(preced(stack[top]) >= preced(sc))
			{
				pc=pop();
				postfix[j++]=pc;
			}
			push(sc);
		}
	}	
	postfix[j]='\0';
	printf("\nPostfix expression is ");
	puts(postfix);
}

void push(char sc)
{
	if(top>=49)
	{
		return;
	}
	top++;
	stack[top]=sc;
}

char pop()
{
//	if(top==-1)
//	{
//		return;
//	}
	char rc=stack[top];
	top--;
	return rc;
}

int preced(char sc)
{
	switch(sc)
	{
		case '^':
			return 6;
		case '*':
			return 5;
		case '/':
			return 5;
		case '+':
			return 4;
		case '-':
			return 4;
	}
	return 3;
}
