#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct BST
{
	struct BST *left;
	int info;
	struct BST *right;		
}bst
void delete(bst**,int);

int main()
{
	
}

//Definition of delete_node function
void delete_node(bst **rt)
{
	int v;
	if(*rt == NULL)
	{
		printf("\n\t Tree is empty.");
		return;
	}
	printf("\n\n\tPlease enter the value: ");
	scanf("%d",&v);
	bst *p=NULL,*t=NULL,*x=NULL,*c=NULL;
	p=*rt;x=*rt;
	if(((*rt)->info == v))
	{
		if(((*rt)->left == NULL) && ((*rt)->right == NULL))
		{
			(*rt) = NULL;
		}
		else if((*rt)->left != NULL && ((*rt)->right == NULL))
		{
			(*rt)=(*rt)->left;
			free(p);
		}
		else
		{
			p=p->right;
			t=p;
			while(p->left != NULL)
			{
				p = p->left;
			}
			p->left = (*rt)->left;
			(*rt) = (*rt)->right;
			free(x);
		}
	}
	else
	{
		while(x->info !=v)
		{
			p=x;
			x=(x->info > v) ? x->left : x->right;
			if(x == NULL)
			{
				printf("Key not found.");
				return;
			}
		}
		//t=x;
		if((x->left == NULL) && (x->right == NULL))
		{
			if(p->info > x->info)
			{
				p->left == NULL;
			}
			else
			{
				p->right == NULL;
			}
			free(x);
		}
		else if((x->left != NULL) && (x->right == NULL))
		{
			if(p->info > x->info)
			{
				p->left == x->left;
			}
			else
			{
				p->right == x->left;
			}
			free(x);
		}
		else
		{
			t=x->right;
			c=t;
			
			while(c->left != NULL)
			{
				c=c->left;
			}
			c->left = x->left;
			
			if(p->info > x->info)
			{
				p->left == t;
			}
			else
			{
				p->right == t;
			}
			free(x);
		}
	}
}
