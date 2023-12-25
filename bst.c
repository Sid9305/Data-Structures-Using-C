#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

struct Tree *createNode(int data)
{
	struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
	if(node==NULL)
	{
		return NULL;
	}
	else
	{
		node->data=data;
		node->left=NULL;
		node->right=NULL;
		return node;
	}
}

struct Tree *insert(struct Tree *root,int data)
{
	if(root==NULL)
	{
		root=createNode(data);
	}
	else
	{
		if(data<root->data)
		{
			root->left=insert(root->left,data);
		}
		else if(data>root->data)
		{
			root->right=insert(root->right,data);
		}
		return root;
	}
}

void inorder(struct Tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d \n",root->data);
		inorder(root->right);
	}
}

void preorder(struct Tree *root)
{
	if(root!=NULL)
	{
		printf("%d \n",root);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d \n",root);
	}
}

struct Tree *min(struct Tree *node)
{
	struct Tree *temp = node;
	while(temp!=NULL && temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

struct Tree *delete_node(struct Tree *root,int data)
{
	if(root==NULL)
	{
		root = root;
	}
	else if(data>root->data)
	{
		root->right = delete_node(root->right,data);
	}
	else if(data<root->data)
	{
		root->left = delete_node(root->left,data);
	}
	else
	{
		if(root->left==NULL)
		{
			struct Tree *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct Tree *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct Tree *temp = min(root->right);
			root->data=temp->data;
			root->right=delete_node(root->right,temp->data);
		}
		return root;
	}
}

int leaf(struct Tree *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	return leaf(root->left) + leaf(root->right);
}

int internal(struct Tree *root)
{
	if(root==NULL || (root->left==NULL && root->right ==NULL))
	{
		return 0;
	}
	return 1 + internal(root->left) + internal(root->right);
}

int height(struct Tree *root)
{
	if(root==NULL)
	{
		return -1;
	}
	int left=height(root->left);
	int right=height(root->right);
	if(left>right)
	{
		return left+1;
	}
	else
	{
		return right+1;
	}
	
}

int main()
{
	int choice,cont,data,val;
	struct Tree *root = NULL;
	do
	{
		printf("Menu driven program for bst \n");
		printf("1) Insertion\n2) Deletion\n3) In-order Traversal\n4) Pre-Order Traversal\n5) Post-Order Traversal\n");
		printf("6) Internal Nodes\n7) Height\n8) Leaf Nodes\n9) Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data to be inserted: ");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				printf("Enter data to be deleted: ");
				scanf("%d",&data);
				root=delete_node(root,data);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				val=internal(root);
				printf("The total number of internal nodes: %d\n",val);
				break;
			case 7:
				val=height(root);
				printf("Height of the tree: %d",val);
				break;
			case 8:
				val=leaf(root);
				printf("The total number of leaf nodes: %d\n",val);
				break;
			case 9:
				exit(1);
				break;
			default:
				printf("Invalid choice\n");
				break;	
		}printf("Press 1 to continue: ");
		scanf("%d",&cont);	
	}while(cont==1);
	return 0;
}
