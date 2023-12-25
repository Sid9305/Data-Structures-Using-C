#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack
{
	int data;
	struct Stack *ptr;
} *Stack;

struct Stack *top = NULL;

struct Stack *createNode()
{
	int data;
	struct Stack *node = malloc(sizeof(struct Stack));
	if(node==NULL)
	{
		return NULL;
	}
	else
	{
		printf("Enter data to be inserted: ");
		scanf("%d",&data);
		node->data=data;
		node->ptr=NULL;
		return node;
	}
}

void push()
{
	struct Stack *node;
	node = createNode();
	if(node==NULL)
	{
		printf("Stack OverFlow");
	}
	else
	{
		if(top==NULL)
		{
			top=node;
		}
		else
		{
			node->ptr=top;
			top=node;
		}
	}
}

void pop()
{
	struct Stack *temp;
	if(top==NULL)
	{
		printf("Stack Underflow");
	}
	else
	{
		temp=top;
		if(temp->ptr==NULL)
		{
			free(top);
		}
		else
		{
			temp=top;
			top=top->ptr;
			free(temp);
		}
	}
}

void display()
{
	struct Stack *temp;
	if(top==NULL)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Elements are: \n");
		temp=top;
		while(temp!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->ptr;
		}
	}
}

int main()
{
	int choice,cont;
	do
	{
		printf("Menu driven program for stack using linked list\n");
		printf("1) Push operation\n2) Pop Operation\n3) Display\n4) Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		printf("Press 1, to continue : ");
		scanf("%d",&cont);	
	}while(cont==1);

}
