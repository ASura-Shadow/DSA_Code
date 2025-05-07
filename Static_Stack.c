#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int stack[10];
int top=-1;

void main(){
	int choice;
	do{
		system("cls");
		printf("\nStack Operation:\n1.Push the element.\n2.Pop the element.\n3.Display the element\n4.Exit.\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				getch();
				break;
			case 2:
				pop();
				getch();
				break;
			case 3:
				display();
				getch();
				break;
			case 4:
				printf("\n Thank you!");
				exit(0);
			default:
				printf("\nInvaild Choice! Please try again.\n");
		}
	}while(1);
}

void push(){
	
	if(top>=9){
		printf("\nStack is Overflow.");
		return;
	}
	else{
		top++;
		printf("\nEnter element to push: ");
		scanf("%d",&stack[top]);
		printf("\n Element %d is Push.",stack[top]);
	}
}

void pop(){
	int d;
	if(top==-1){
		printf("\nStack is underflow.");
		return;
	}
	else{
		d=stack[top];
		top--;
		printf("\n Element %d is Pop.",d);
			
	}
}

void display(){
	int i=top;
	if(top==-1){
		printf("\nStack is Empty.");
		return;
	}
	else{
		while(i>=0){
			printf("%d ",stack[i]);
			i--;
		}
	}
}
