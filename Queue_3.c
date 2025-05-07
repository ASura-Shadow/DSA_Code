#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int enqueue(int[],int,int);
int dequeue(int[],int,int);
void display(int[],int,int);
void peek(int[],int);

void main(){
	int ch,cq[MAX],f=-1,r=-1;
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
				r=enqueue(cq,f,r);
				if(f==-1){
					f=0;
				}
				getch();
				break;
			case 2:
				f=dequeue(cq,f,r);
				if(f==-1){
					r=-1;
				}
				getch();
				break;
			case 3:
				display(cq,f,r);
				getch();
				break;
			case 4:
				peek(cq,f);
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
int enqueue(int cq[],int f,int r){
	int x;
	if((r+1)%MAX==f){
		printf("\nQueue is Full.\n");
		return;
	}
	else{
		printf("\nEnter Enqueue Elements :");
		scanf("%d",&x);
		r=(r+1)%MAX;
		cq[r]=x;
		printf("\nEnqueue %d in Queue.\n",x);
		return r;
	}
}

int dequeue(int cq[],int f, int r){
	int x;
	if(f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
		x=cq[f];
		printf("\nDequeue %d in Queue.\n",x);
		if(r==f){
			f=-1;
		}
		else{
			f=(f+1)%MAX;
		}
		return f;
	}
}

void display(int cq[], int f,int r){
	int i;
	if(f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
	for(i=f;i!=r;i=(i+1)%MAX)	{
		printf("%d ",cq[i]);
	}
	printf("%d ",cq[r]);
	}
}

void peek(int cq[],int f){
	if(f==-1){
		printf("\nQueue is Empty.");
		return;
	}
	else{
		printf("%d",cq[f]);
	}
}
