#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void enqueue(int[],int*);
void dequeue(int[],int*,int*);
void display(int[],int,int);
void peek(int[],int);

void main(){
	int ch,sq[MAX],f=-1,r=-1;
	while(1){
		system("cls");
		printf("\n\n Simple Queue Operation:\n");
		printf("1.Enqueue in Queue.\n");
		printf("2.Dequeue in Queue.\n");
		printf("3.Display Queue.\n");
		printf("4.Peek in Queue.\n");
		printf("5.Exit\n");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enqueue(sq,&r);
				if(f==-1){
					f=0;
				}
				getch();
				break;
			case 2:
				dequeue(sq,&f,&r);
				if(f==-1){
					r=-1;
				}
				getch();
				break;
			case 3:
				display(sq,f,r);
				getch();
				break;
			case 4:
				peek(sq,f);
				getch();
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid Choice! Please try again.");
				getch();
		}
	}
}
void enqueue(int sq[],int *r){
	int x;
	if(*r>=MAX-1){
		printf("\nQueue is Full.\n");
		return;
	}
	else{
		printf("\nEnter Enqueue Elements :");
		scanf("%d",&x);
		(*r)++;
		sq[*r]=x;
		printf("\nEnqueue %d in Queue.\n",x);
	}
}

void dequeue(int sq[],int *f, int *r){
	int x;
	if(*f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
		x=sq[*f];
		printf("\nDequeue %d in Queue.\n",x);
		if(*r==*f){
			*f=-1;
		}
		else{
			(*f)++;
		}
	}
}

void display(int sq[], int f,int r){
	int i;
	if(f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
	for(i=f;i<=r;i++)	{
		printf("%d ",sq[i]);
	}
	printf("\n");
	}
}

void peek(int sq[],int f){
	if(f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
		printf("%d",sq[f]);
	}
}
