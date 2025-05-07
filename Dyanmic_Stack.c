#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct stack{
	int data;
	struct stack *next;
}typedef node;

node *top=NULL;

void main(){
	int ch;
	while(1){
		system("cls");
		printf("\n\nStasck Operation:\n\n1.Push the element.\n2.Pop the element.\n3.Display the stack.\n4.Exit\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				push(); //calling push function
				getch();
				break;
			case 2:
				pop(); //calling pop function
				getch();
				break;
			case 3:
				display(); //calling display function
				getch();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice! Please try again.");
				getch();			
		}
	}
}

//push function
void push(){
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("\nOverflow");
		return;
	}
	printf("\nEnter an element: ");
	scanf("%d",&p->data);
	p->next=top;
	top=p;
}

//pop function
void pop(){
	node *p;
	if(top==NULL){
		printf("\nUnderflow");
		return;
	}
	p=top;
	printf("\n%d element poped.",p->data);
	top=top->next;
	free(p);
}

//display function 
void display(){
	node *p;
	p=top;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

