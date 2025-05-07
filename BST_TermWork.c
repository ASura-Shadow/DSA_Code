#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct BST
{
	struct BST *left;
	int info;
	struct BST *right;
}typedef bst;

void insert(bst **,int); //insert function declaration
void inorder(bst *); //inorder function declaration
void preorder(bst *); //preorder function declaration
void postorder(bst *); //podt function declaration
void countTotalNode(bst *,int *); //countTotalNode function declaration
void countTotalLeafNode(bst *,int *); //countTotalLeafNode function declaration
void countNodeWithLeftChild(bst *,int *); //countNodeWithLeftChild function declartion
void countNodeWithExactlyOneChild(bst *,int *); //countNodeWithExactlyOneChild function declaration

void main()
{
	bst *root=NULL;
	int ch,count,num;
	
	while(1)
	{
		system("cls");
		printf("\n\n=== Binary Search Tree Operations === \n");
		// For menu bar
		printf("\n\t1. Insert in Binary Search Tree \n\t2. Display (Inorder Traversal) \n\t3. Display (Preorder Traversal) \n\t4. Display (Postorder Traversal) \n\t5. Count Total Nodes \n\t6. Count Total Leaf Nodes \n\t7. Count Nodes With Exactly One Child \n\t8. Cont Nodes With Only Left Child \n\t9.Exit ");
		printf("\n\n\tPlease enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\n\tPlease enter the value to insert: ");
				scanf("%d",&num);
				insert(&root,num); //calling insert function by passing the address of root pointer and value of num 
				getch();
				break;
			case 2:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				printf("\n\tInorder Traversal:\n\t=>");
				inorder(root); //calling inorder function by passing value of root pointer
				getch();
				break;
			case 3:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				printf("\n\tPreorder Traversal:\n\t=>");
				preorder(root); //calling preorder function by passing value of root pointer
				getch();
				break;
			case 4:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				printf("\n\tPostorder Traversal:\n\t=>");
				postorder(root); //calling postorder function by passing value of root pointer
				getch();
				break;
			case 5:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				count=0;
				countTotalNode(root,&count); //calling countTotalNode function by passing value of root pointer and address of count
				printf("\n\tTotal Nodes are %d \n",count);
				getch();
				break;
			case 6:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				count=0;
				countTotalLeafNode(root,&count); //calling countTotalLeafNode function by passing value of root pointer and address of count
				printf("\n\tTotal Leaf Nodes are %d \n",count);
				getch();
				break;
			case 7:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				count=0;
				countNodeWithExactlyOneChild(root,&count); //calling countNodeWithExactlyOneChild function by passing value of root pointer and address of count
				printf("\n\tNodes with exactly one child are %d \n",count);
				getch();
				break;
			case 8:
				if(root == NULL)
				{
					printf("\n\tTree is empty.\n");
					getch();
					break;
				}
				count=0;
				countNodeWithLeftChild(root,&count); //calling countNodeWithLeftChild function by passing value of root pointer and address of count 
				printf("\n\tNodes with left child are %d \n",count);
				getch();
				break;
			case 9:
				exit(0);
			default:
				printf("\n\tInvalid choice! Please try again.");
				getch();
		}
	}
}

//Definition of insert function
void insert(bst **rt,int x)
{
	if((*rt) == NULL)
	{
		bst *p=(bst*)malloc(sizeof(bst));
		if(p!=NULL)
		{
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			(*rt) = p;	
		}
		printf("\n\tInserted\n");
	}
	else if(x < (*rt)->info)
	{
		insert((&(*rt)->left),x);
	}
	else if(x > (*rt)->info)
	{
		insert((&(*rt)->right),x);
	}
	else
	{
		printf("\n\tDuplicate value not allow.\n");
		return;
	}
	
}

//Definition of inorder function
void inorder(bst *rt)
{
	if(rt != NULL)
	{
		inorder(rt->left);
		printf("%d ",rt->info);
		inorder(rt->right);
	}
}

//Definition of preorder function
void preorder(bst *rt)
{
	if(rt != NULL)
	{
		printf("%d ",rt->info);
		preorder(rt->left);
		preorder(rt->right);
	}
}

//Definition of postorder function
void postorder(bst *rt)
{
	if(rt != NULL)
	{
		postorder(rt->left);
		postorder(rt->right);
		printf("%d ",rt->info);
	}
}

//Definition of countTotalNode function
void countTotalNode(bst *rt,int *count)
{
	if(rt != NULL)
	{
		(*count)++;
		countTotalNode(rt->left,count);
		countTotalNode(rt->right,count);
	}
}

//Definition of countTotalLeafNode function
void countTotalLeafNode(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if(rt->left == NULL && rt->right == NULL)
		{
			(*count)++;
		}
		countTotalLeafNode(rt->left,count);
		countTotalLeafNode(rt->right,count);
	}
}

//Definition of countNodeWithLeftChild function
void countNodeWithLeftChild(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if(rt->left != NULL && rt->right == NULL)
		{
			(*count)++;
		}
		countNodeWithLeftChild(rt->left,count);
		countNodeWithLeftChild(rt->right,count);
	}
}

//Definition of countNodeWithExactlyOneChild function
void countNodeWithExactlyOneChild(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if((rt->left != NULL && rt->right == NULL) || (rt->left ==NULL && rt->right != NULL))
		{
			(*count)++;
		}
		countNodeWithExactlyOneChild(rt->left,count);
		countNodeWithExactlyOneChild(rt->right,count);
	}
}

