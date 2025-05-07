#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


struct Linkedlist{
	int data;
	struct Linkedlist *next;
}typedef L;

void  insertInBeg(L**);
void  insertInEnd(L**);
void countPrime(L*);
void display(L*);

void main ()
{
	L *node;
	int ch;
	do{
		system("cls");
		printf("\n\t1.Insert at beginning.\n\t2.Insert at End\n\t3.Display\n\t4.Count Prime No.\n\t5.Exit");
		printf("\n\tEnter your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insertInBeg(&node);
				getch();
				break;
			case 2:
				insertInEnd(&node);
				getch();
				break;
			case 3:
				display(node);
				getch();
				break;
			case 4:
				countPrime(node);
				getch();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice try again.");   
		}
	}while(1);
}

void insertInBeg(L **node){
	L *p=NULL;
	int x;
	p=(L*)malloc(sizeof(L));
	p->next=NULL;
	if(p!=NULL){
		printf("\nEnter Data to insert:  ");
		scanf("%d",&x);
		p->data=x;
		if((*node)==NULL){
			(*node)=p;
		}
		else{
			p->next=*node;
			*node=p;	
		}
	}
	printf("INSERTED");
}

void insertInEnd(L **node){
	L *p,*t;
	int x;
	p=(L*)malloc(sizeof(L));
	p->next=NULL;
	if(p!=NULL){
		printf("\nEnter Data to insert:  ");
		scanf("%d",&x);
		p->data=x;
		if((*node)==NULL){
			(*node)=p;
		}
		else{
			t=*node;
			while(t->next!=NULL){
				t=t->next;
			}		
			t->next=p;
		}
	}
	printf("INSERTED");
}

void display(L *t){
	if(t==NULL){
		printf("List is empty.");
	}
	else{
		while(t!=NULL){
			printf("%d ",t->data);
			t=t->next;
		}
	}
}

void countPrime(L *t){
	int f=0,x,i,count=0;
	if(t==NULL){
		printf("List is empty.");
	}
	else{
		while(t!=NULL){
			x=t->data;
			f=0;
			for(i=2;i<x/2;i++){
				if(x%i==0){
					f=1;
				}
			}
			if(f==0){
				printf("%d ",t->data);
				count++;
			}
		}
		printf("Total prime no. in list is %d",count);
	}
}


