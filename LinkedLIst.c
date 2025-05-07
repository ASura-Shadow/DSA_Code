#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct linkedlist
{
	int data;
	struct linkedlist *next;
}typedef node;

void insertAtBeginning(node **,int);
void insertAtEnd(node **,int);
void insertAfterFirst(node **,int);
void insertBeforeLast(node **,int);
void insertInAscendingOrder(node **,int);
void display(node*);
void countTotalNode(node *);
void delete_first(node **);
void delete_last(node **);
void delete_after_first(node *);
void delete_before_last(node **);
void delete_alternate(node *);
void armstrong(node *);
void palindrome(node *);
void prime(node *);
void alternate_display(node *);


void main()
{
	node *head=NULL;
	int ch,count,num;
	while(1)
	{
		system("cls");
		printf("\n->Linked List Operation.\n");
		printf("\n\t1.Insert at beginning. \n\t2.Insert at End. \n\t3.Insert node after first node. \n\t4.Insert node before last node. \n\t5.Insert node in ascending order. \n\t6.Display. \n\t7.Delete first node. \n\t8.Delete last node. \n\t9.Delete node after first node. \n\t10.Delete node before last node. \n\t11.Delete alternate node. \n\t12.Delete specific node. \n\t13.Display alternate node. \n\t14.Count and Display node with prime. \n\t15.Count and Display node with Armstrong. \n\t16.Count and Display node with palindrome. \n\t17.Total number of node present in linked list. \n\t18.Exit. ");
		printf("\n\n\tEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter data to insert: ");
				scanf("%d",&num);
				insertAtBeginning(&head,num);
				getch();
				break;
			case 2:
				printf("Enter data to insert: ");
				scanf("%d",&num);
				insertAtEnd(&head,num);
				getch();
				break;
			case 3:
				printf("Enter data to insert: ");
				scanf("%d",&num);
				insertAfterFirst(&head,num);
				getch();
				break;
			case 4:
				printf("Enter data to insert: ");
				scanf("%d",&num);
				insertBeforeLast(&head,num);
				getch();
				break;
			case 5:
				printf("Enter data to insert: ");
				scanf("%d",&num);
				insertInAscendingOrder(&head,num);
				getch();
				break;
			case 6:
				display(head);
				getch();
				break;
			
			case 7:
                delete_first(&head);
                system("Pause");
                break;

            case 8:
                delete_last(&head);
                system("Pause");
                break;

            case 9:
                delete_after_first(head);
                system("Pause");
                break;
            
            case 10:
                delete_before_last(&head);
                system("Pause");
                break;
            
            case 11:
                delete_alternate(head);
                system("Pause");
                break;
            case 12:
            	break;
            
			case 13:
                alternate_display(head);
                system("Pause");
                break;
				
            case 14:
                prime(head);
                system("Pause");
                break;
                
            case 15:
                armstrong(head);
                system("Pause");
                break;

            case 16:
                palindrome(head);
                system("Pause");
                break;

			case 17:
				countTotalNode(head);
				getch();
				break;
				
			case 18:
				exit(0);
				
			default:
                printf("\n\tInvalid Choice Entered!! Please Try Again");
                getch();
		}
	}
}

void insertAtBeginning(node **head,int num)
{
	node *p=(node*)malloc(sizeof(node));
	p->data = num;
	p->next = (*head);
	(*head) = p;
	printf("\nInserted");
}

void insertAtEnd(node **head,int num)
{
	node *p=(node*)malloc(sizeof(node));
	p->data = num;
	p->next = NULL;
	node *t=(*head);
	if((*head) == NULL)
	{
		(*head) = p;
		return;
	}
	else
	{
		while(t->next != NULL)
		{
			t=t->next;
		}
		t->next=p;
	}
	printf("\nInserted");
}

void insertAfterFirst(node **head,int num)
{
	node *p=(node*)malloc(sizeof(node));
	p->data = num;
	if((*head) == NULL)
	{
		(*head) = p;
		return;
	}
	else
	{
		p->next = (*head)->next;
		(*head)->next = p;	
	}
	printf("\nInserted");
}

void insertBeforeLast(node **head,int num)
{
	node *p=(node*)malloc(sizeof(node));
	p->data = num;
	p->next = NULL;
	if((*head) == NULL || (*head)->next == NULL)
	{
		p->next = (*head);
		(*head) = p;
		return;
	}
	else
	{
		node *t=(*head);
		while(t->next->next != NULL)
		{
			t = t->next;
		}
		p->next=t->next;
		t->next=p;	
	}
	printf("\nInserted");
}
 
void insertInAscendingOrder(node **head,int num)
{
	node *p = (node*)malloc(sizeof(node));
	p->data = num;
	p->next = NULL;
	if((*head) == NULL || (*head)->data > num)
	{
		p->next =(*head);
		(*head) = p;
		return;
	}
	
	else
	{
		node *t = (*head);
		while(t->next != NULL && t->next->data < num)
		{
			t= t->next;
		}
		p->next = t->next;
		t->next = p;	
	}
	printf("\nInserted");
} 

void display(node *head)
{
	if(head == NULL)
	{
		printf("List is empty.");
		return;
	}
	while(head != NULL)
	{
		printf("%d -> ",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void countTotalNode(node *head)
{
	int c=0;
	if(head == NULL)
	{
		printf("List is Empty.");
		return;
	}
	else
	{
		while(head != NULL)
		{
			c++;
			head=head->next;
		}
		printf("Total number of node present in linked list are %d",c);
	}
}

void alternate_display(node *head)
{
    if(head==NULL)
    {
        printf("\nList is Empty");
        return;
    }

    node *t=head;
    
    while(t!=NULL)
    {
        printf("%d ",t->data);
        if(t->next==NULL)
        {
            return;
        }
        t=t->next->next;
    }
    return;
}

void delete_first(node **head)
{
    if(*head==NULL)
    {
        printf("\n\tList is Empty!!");
        return;
    }

    node *t=*head;
    (*head)=(*head)->next;
    printf("Node deleted = %d",t->data);
    free(t);
}

void delete_last(node **head)
{
    if(*head==NULL)
    {
        printf("\n\tList is Empty!!");
        return;
    }

    node *t=*head,*p;

    if((*head)->next==NULL)
    {
        printf("Node Delete = %d",(*head)->data);
        free(t);
        *head=NULL;
        return;
    }

    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    
    p=t->next;
    t->next=NULL;
    printf("Node Delete = %d",p->data);
    free(p);
    printf("\n");

}

void delete_after_first(node *head)
{
    if(head==NULL || head->next==NULL)
    {
        printf("Node not Exist");
        return;
    }

    node *t=head->next;
    head->next = t->next;
    printf("Node Delete = %d",t->data);
    free(t);

}

void delete_before_last(node **head)
{
    if(*head==NULL || (*head)->next==NULL) 
    {
        printf("Node not Exist");
        return;
    }
    
    node *t=(*head)->next, *p=*head; // p is at node 1 and t is at node 2
    
    if((*head)->next->next==NULL)
    {
        *head=p->next;
        printf("Node Delete = %d",p->data);
        free(p);
        printf("\n");
        
        return;
    }
    
    while(t->next->next!=NULL) //t will stop at 2nd last and p will stop at 3rd last
    {
        p=p->next;
        t=t->next;
    }

    p->next=t->next;
    printf("Node Delete = %d",t->data);
    free(t);
    return;
}

void delete_alternate(node *head)
{
    return;
}

void armstrong(node *head)
{
    if(head==NULL)
    {
        printf("\n\tList is Empty!!");
        return;
    }
    
    int num,rem,digit=0,sum=0,count=0;
    while(head!=NULL)
    {
        //digit count
        num=head->data;
        digit=0;
        while(num>0)
        {
            digit++;
            num=num/10;
        }
        
        //armstrong check
        num=head->data;
        sum=0;
        int i,p;
        while(num>0)
        {
            rem=num%10;
            p=1;
            for(i=1;i<=digit;i++)
            {
                p=p*rem;
            }
            sum = sum+p;
            num=num/10;
        }

        if(sum==head->data)
        {
            printf("%d ",head->data);
            count++;
        }

        head=head->next;
    }
    
    printf("\nTotal Armstrong Numbers Present = %d",count);
    return;
}

void palindrome(node *head)
{
    if(head==NULL)
    {
        printf("\n\tList is Empty!!");
        return;
    }
    
    int num,rem,rev=0,count=0;
    while(head!=NULL)
    {
        num=head->data;
        
        //Palindrome check
        rev=0;
        while(num>0)
        {
            rem=num%10;
            rev=rev*10+rem;
            num=num/10;
        }

        if(rev==head->data)
        {
            printf("%d ",head->data);
            count++;
        }

        head=head->next;
    }
    
    printf("\nTotal Palindrome Numbers Present = %d",count);
    

    return;
}

void prime(node *head)
{
    return;
}
