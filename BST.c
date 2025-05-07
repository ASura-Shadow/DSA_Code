#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

typedef struct BST
{
	struct BST *left;
	int info;
	struct BST *right;
}bst;

//All Function declaration
void insert(bst **,int);
void display(bst *);
void inorder(bst *);
void preorder(bst *);
void postorder(bst *);
void count_TotalNode(bst *,int *);
void count_TotalLeafNode(bst *,int *);
void countNodeWithOnlyLeftChild(bst *,int *);
void countNodeWithOnlyRightChild(bst *,int *);
void countNodeWithParent(bst * , int*);
void countNodeWithBothChildren(bst *, int *);
void countNodeOnLeftSideOfTree(bst *, int *);
void countNodeOnRightSideOfTree(bst *, int *);
void highestValue(bst *);
void leastValue(bst *);
int heightOfTree(bst *);
int depthOfTree(bst *);
void findParent(bst * ,int);
void count_NodeWithExcatlyOneChild(bst *, int *);
void count_NodesWithCommonParent(bst *, int *);

int main()
{
	bst *root=NULL;
	int ch,num,count;
	while(1)
	{
		system("cls");
		printf("\n\t Binary Search Tree  Operation:\n");
		printf("\n\t\t1.Insert in Binary Search Tree. \n\t\t2.Display Traversals. \n\t\t3.Count Total Node. \n\t\t4.Count Total Leaf Node. \n\t\t5.Count Node With Left Child. \n\t\t6.Count Node With Right Child. \n\t\t7.Count Node With Parent. \n\t\t8.Count Node With Both Child. \n\t\t9.Highest Value In BST. \n\t\t10.Least Value In BST. \n\t\t11.Count Node On Left Side Of BST. \n\t\t12.Count Node On Right Side of BST. \n\t\t13.Height of BST. \n\t\t14.Depth of BST. \n\t\t15.Find Parent of a Node. \n\t16.Count of nodes having only one child \n\t17.Count of Nodes Having Common Parents Or Count of Sibilings \n\t18.exit ");
		printf("\n\tPlease enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\n\tPlease enter the value: ");
				scanf("%d",&num);
				insert(&root,num); //Calling insert function passing address of root and value of num
				system("Pause");
				break;
			case 2:
				display(root); //calling dislay function passing value of root
				system("Pause");
				break;
			case 3:
				count=0;
				count_TotalNode(root,&count); //calling count_TotalNode function passing value of root and address of count
				printf("\n\tTotal node in BST is %d \n",count);
				system("Pause");
				break;
			case 4:
				count=0;
				count_TotalLeafNode(root,&count); //calling count_TotalLeafNode function passing value of root and address of count
				printf("\n\tTotal leaf node in BST is %d \n",count);
				system("Pause");
				break;
			case 5:
				count=0;
				countNodeWithOnlyLeftChild(root,&count); //calling countNodeWithLeftChild function passing value of root and address of count
				printf("Number of node with only left child is %d \n",count);
				system("Pause");
				break;
			case 6:
				count=0;
				countNodeWithOnlyRightChild(root,&count); //calling countNodeWithRightChild function passing value of root and address of count
				printf("Number of node with only right child is %d \n",count);
				system("Pause");
				break;
			case 7:
				count=0;
				countNodeWithParent(root, &count); //calling countNodeWithParent function passing value of root and address of count
				printf("Number of node with parent is %d \n",(count-1));
				system("Pause");
				break;
			case 8:
				count=0;
				countNodeWithBothChildren(root,&count); //calling countNodeWithBothChild function passing value of root and address of count
				printf("Number of node with both child is %d \n",count);
				system("Pause");
				break;
			case 9:
				highestValue(root); //calling highrestValue function passing value of root
				system("Pause");
				break;
			case 10:
				leastValue(root); //calling leastValue function passing value of root
				system("Pause");
				break;
			case 11:
				count=0;
				countNodeOnLeftSideOfTree(root->left, &count); //Calling countNodeOnLeftSideOfTree function passing value of root->left and address of count
				printf("Total node on left side of BST is %d\n",count);
				system("Pause");
				break;
			case 12:
				count=0;
				countNodeOnRightSideOfTree(root->right, &count); //Calling countNodeOnRightSideOfTree function passing value of root->right and address of count
				printf("Total node on right side of BST is %d\n",count);
				system("Pause");
				break;
			case 13:
				printf("Height of BST is %d\n",(heightOfTree(root)+1));
				system("Pause");
				break;
			case 14:
				printf("Depth of BST is %d\n",depthOfTree(root));
				system("Pause");
				break;
			case 15:
				printf("\n\tEnter the node to find its parent: ");
    			scanf("%d", &num);
    			findParent(root, num);
    			system("Pause");
    			break;
			
            case 16:
                count=0;
                count_NodeWithExcatlyOneChild(root,&count);
                printf("Number of nodes having only 1 child are = %d",count);
                system("Pause");
                break;
			
			case 17:
				//This function for common parent or sibiling = count*2
				count=0;
				count_NodesWithCommonParent(root,&count);
				printf("Number of Nodes Having Common Parent OR Count of Nodes that are Sibilings are = &d",(count*2));
				system("Pause");
				break;

			case 18:
				exit(0); //for exit for program
            
			default:
				printf("\nInvaliad choice! Please try again.");
				getch();
		}
		
	}
	
	
}

//Definition of insert function
void insert(bst **rt,int x)
{
	if((*rt) == NULL)
	{
		bst p = (bst)malloc(sizeof(bst));
		if(p != NULL)
		{
			p->info=x;
			p->left=NULL;
			p->right=NULL;
			
			*rt=p;
		}
		printf("\n\tInserted\n");
	}
	else if(x < (*rt)->info)
	{
		insert(&((*rt)->left),x);
	}
	else if(x > (*rt)->info)
	{
		insert(&((*rt)->right),x);
	}
	else
	{
		printf("\n\t\tDuplicate data is not allowed!");
	}
}

//Definition of display function
void display(bst *rt)
{
	int ch;
	if(rt == NULL){
		printf("\n\tTree is empty.");
		return;
	}
	system("cls");
	printf("\n\tTraversal Options:");
	printf("\n\t1.Inorder\n\t2.Preorder\n\t3.Postorder");
	printf("\n\tEnter your choice: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			inorder(rt);
			break;
		case 2:
			preorder(rt);
			break;
		case 3:
			postorder(rt);
			break;
		default:
    		printf("Invalid choice!\n");
	}
	printf("\n");
}

//Definition of inorder function
void inorder(bst *rt)
{
	if(rt == NULL)
	{
		return;
	}
	else
	{
		inorder(rt->left);
		printf("%d ",rt->info);
		inorder(rt->right);	
	}
}

//Definition of preorder function
void preorder(bst *rt)
{
	if(rt == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",rt->info);
		preorder(rt->left);
		preorder(rt->right);	
	}
}

//Definition of postorder function
void postorder(bst *rt)
{
	if(rt == NULL)
	{
		return;
	}
	else
	{
		postorder(rt->left);
		postorder(rt->right);
		printf("%d ",rt->info);	
	}
}

//Definition of count_TotalNode function
void count_TotalNode(bst *rt,int *count)
{
	if(rt != NULL)
	{
		(*count)++;
		count_TotalNode(rt->left,count);
		count_TotalNode(rt->right,count);		
	}
}

//Definition of count_TotalLeafNode function
void count_TotalLeafNode(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if((rt->left == NULL) && (rt->right == NULL))
		{
			(*count)++;
		}
		count_TotalLeafNode(rt->left,count);
		count_TotalLeafNode(rt->right,count);		
	}
}

//Definition of countNodeWithOnlyLeftChild function
void countNodeWithOnlyLeftChild(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if((rt->left) != NULL && (rt->right) == NULL)
		{
			(*count)++;
		}
		countNodeWithOnlyLeftChild(rt->left,count);
		countNodeWithOnlyLeftChild(rt->right,count);
	}
}

//Definition of countNodeWithOnlyRightChild function
void countNodeWithOnlyRightChild(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if((rt->left) == NULL && (rt->right) != NULL)
		{
			(*count)++;
		}
		countNodeWithOnlyRightChild(rt->left,count);
		countNodeWithOnlyRightChild(rt->right,count);
	}
}

//Definition of countNodeWithCommonParent function
void countNodeWithParent(bst *rt , int*count)
{
	if(rt != NULL)
	{
		(*count)++;
		countNodeWithParent(rt->left,count);
		countNodeWithParent(rt->right,count);		
	}	
}

//Definition of countNodeWithBothChild function
void countNodeWithBothChildren(bst *rt,int *count)
{
	if(rt != NULL)
	{
		if(rt->left != NULL && rt->right != NULL)
		{
			(*count)++;
		}
		countNodeWithBothChildren(rt->left, count);
		countNodeWithBothChildren(rt->right, count);
	}
}

//Definition of highestValue function
void highestValue(bst *rt)
{
	if(rt!=NULL)
	{
		while(rt->right != NULL)
		{
			rt = rt->right;
		}
		printf("Highest value in BST is %d\n",rt->info);
	}
}

//Definition of leastValue function
void leastValue(bst *rt)
{
	if(rt!=NULL)
	{
		while(rt->left != NULL)
		{
			rt = rt->left;
		}
		printf("Least value in BST is %d\n",rt->info);
	}
}

//Definition of countNodeOnLeftSideOfTree function
void countNodeOnLeftSideOfTree(bst *rt,int *count)
{
	if(rt != NULL)
	{
		(*count)++;
		countNodeOnLeftSideOfTree(rt->left,count);
		countNodeOnLeftSideOfTree(rt->right,count);
	}
}

//Definition of countNodeOnRightSideOfTree function
void countNodeOnRightSideOfTree(bst *rt,int *count)
{
	if(rt != NULL)
	{
		(*count)++;
		countNodeOnRightSideOfTree(rt->left,count);
		countNodeOnRightSideOfTree(rt->right,count);
	}
}

//Definition of heightOfTree function
int heightOfTree(bst *rt)
{
	int leftheight=0,rightheight=0;
	if(rt == NULL)
	{
		return -1; // Height of an empty tree is 0
	}
	else
	{
		leftheight = heightOfTree(rt->left);
		rightheight = heightOfTree(rt->right); 
	}
	return((leftheight > rightheight ? leftheight : rightheight)+1);
}

//Definition of depthOfTree function
int depthOfTree(bst *rt)
{
	int leftheight=0,rightheight=0;
	if(rt == NULL)
	{
		return -1; //Depth of an empty tree is -1
	}
	else
	{
		leftheight = depthOfTree(rt->left);
		rightheight = depthOfTree(rt->right); 	
	} 
	return((leftheight > rightheight ? leftheight : rightheight)+1);
}

//Definition of findParent function
void findParent(bst *rt,int x)
{
	if(rt == NULL)
	{
		printf("Tree is empty.");
		return;
	}
	else if(rt->info == x)
	{
		printf("The node is root. It has no parent.\n");
		return;
	}
	bst *current =rt;
	bst *parent = NULL;
	while(current != NULL)
	{
		if(x < current->info)
		{
			parent = current;
			current = rt->left;
		}
		else if(x > current->info)
		{
			parent = current;
			current = rt->right;
		}
		else
		{
			printf("Parent node is %d\n",parent->info);
			return;
		}
	}
	printf("Node %d not found in the tree.\n",x);
}

//Definition of count_NodesWithExactlyOneChild function
void count_NodeWithExcatlyOneChild(bst *rt, int *count)
{
    if(rt!=NULL)
    {
        if(((rt->left!=NULL) && (rt->right==NULL)) || ((rt->left==NULL) && (rt->right!=NULL))) 
        {
            (*count)++;
        }
        count_NodeWithExcatlyOneChild(rt->left,count);
        count_NodeWithExcatlyOneChild(rt->right,count);
    }
}

//Definition of count_NodesWithCommonParent function
void count_NodesWithCommonParent(bst *rt, int *count)
{
	if(rt!=NULL)
	{
		if((rt->left!=NULL) && (rt->right!=NULL))
		{
			(*count)++;
		}
		count_NodesWithCommonParent(rt->left,count);
		count_NodesWithCommonParent(rt->right,count);
	}
}