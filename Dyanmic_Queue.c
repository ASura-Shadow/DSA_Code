#include<stdio.h>
#include<stdlib.h>

typedef struct slistqueue{
	int data;
	struct slistqueue *next;
}Q;

Q* enqueue(Q*);
Q* dequeue(Q*);
void display(Q*);
void peek(Q*);

void main()
{
	Q *f=NULL,*r=NULL;
	int ch;
	while(1)
	{
		system("cls");
		printf("\n1.Enqueue in Queue.\n");
		printf("2.Dequeue in Queue.\n");
		printf("3.Display Queue.\n");
		printf("4.Peek in Queue.\n");
		printf("5.Exit\n");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				r=enqueue(r);
				if(f==NULL){
					f=r;
				}
				getch();
				break;
			case 2:
				f=dequeue(f);
				if(f==NULL){
					r=NULL;
				}
				getch();
				break;
			case 3:
				display(f);
				getch();
				break;
			case 4:
				peek(f);
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

Q* enqueue(Q *r){
	
	Q *p=NULL;
	int x;
	p=(Q*)malloc(sizeof(Q));
	if(p==NULL){
		printf("\nMemory not allocated.");
	}
	else
	{
		printf("\nEnter data: ");
		scanf("%d",&x);
		p->data=x;
		
	
		if(r==NULL){
			r=p;
		}
		else{
			r->next=p;
			r=p;
		}
		r->next=NULL;
	}
	printf("%d Is Inserted",x);
	return r;	 
}

Q* dequeue(Q *f){
	Q *p;
	if(f==NULL){
		printf("\nQueue is empty.");
	}
	else{
		printf("%d delete ",f->data);
		p=f;
		f=f->next;
		free(p);
	}
	return f;
}

void display(Q *f){
	if(f==NULL){
		printf("\nQueue is empty.");
	}
	else{
		while(f!=NULL){
			printf("%d ",f->data);
			f=f->next;
		}
	}
}

void peek(Q *f){
	if(f==NULL){
		printf("\nQueue is empty.");
	}
	else{
		printf("%d",f->data);
	}
}

