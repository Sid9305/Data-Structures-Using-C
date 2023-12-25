#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0

struct Node
{
	int data;
	struct Node *ptr;
};

struct Node *head = NULL;

struct Node* createNode()
{
	int data;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node==NULL)
	{
		return NULL;
	}
	else
	{
		printf("Enter data to be inserted: ");
		scanf("%d",&data);
		new_node->data=data;
		new_node->ptr=NULL;
		return new_node;
	}
} 

void insertAtBeg()
{
	struct Node *new_node;
	new_node=createNode();
	if(new_node==NULL)
	{
		printf("Memory Overflow");
	}
	else
	{
		new_node->ptr=head;
		head=new_node;
	}
}

void insertAtEnd()
{
	struct Node* new_node, *temp;
	new_node = createNode();
	if(new_node==NULL)
	{
		printf("Memory Overflow");
	}
	else
	{
		if(head==NULL)
		{
			head=new_node;
		}
		else
		{
			temp=head;
			while(temp->ptr!=NULL)
			{
				temp=temp->ptr;
			}
			if(temp->ptr==NULL)
			{
				temp->ptr=new_node;
			}
		}
		
	}
}

void insertAtMid()
{
	struct Node* new_node, *temp,*temp1;
	new_node = createNode();
	int data;
	if(new_node==NULL)
	{
		printf("Memory Overflow");
	}
	else
	{
		printf("Enter data before which you want to insert: ");
		scanf("%d",&data);
		temp=NULL;
		temp1=head;
		while(temp1!=NULL && temp1->data!=data)
		{
			temp=temp1;
			temp1=temp1->ptr;
		}
		if(temp1==head)
		{
			new_node->ptr=head;
			head=new_node;
		}
		else if(temp1!=NULL && temp1->data==data)
		{
			temp->ptr=new_node;
			new_node->ptr=temp1;
		}
		else
		{
			printf("%d not found",data);
		}
	}
}

void delAtBeg()
{
	struct Node *temp;
	if(head==NULL)
	{
		printf("Memory Underflow");
	}
	else
	{
		temp=head;	
		head=head->ptr;
		free(temp);
	}
}

void delAtEnd()
{
	struct Node *temp,*new_last;
	if(head==NULL)
	{
		printf("Memory Underflow");
		return;
	}
	else
	{
		new_last=NULL;
		temp=head;
		while(temp->ptr!=NULL)
		{
			new_last=temp;
			temp=temp->ptr;
		}
		if(temp->ptr==NULL)
		{
			new_last->ptr=NULL;
			free(temp);
		}
	}
}

void delAtMid()
{
	struct Node *temp,*temp1;
	int data;
	if(head==NULL)
	{
		printf("Memory Underflow");
		return;
	}
	else
	{
		printf("Enter the node u want to delete: ");
		scanf("%d",&data);
		temp=NULL;
		temp1=head;
		while(temp1!=NULL && temp1->data!=data)
		{
			temp=temp1;
			temp1=temp1->ptr;
		}
		if(temp1==head)
		{
			head=head->ptr;
			printf("deleted!");
		}
		else if(temp1!=NULL && temp1->data==data)
		{
			temp->ptr=temp1->ptr;
			free(temp1);
			printf("deleted!");
		}
		else
		{
			printf("%d not found",data);
		}
	}
}

void display()
{
	struct Node *temp;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		printf("Elements: \n");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->ptr;
		}
	}
}

void search()
{
	struct Node *temp;
	int data;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		temp=head;
		printf("Enter the data to be find: ");
		scanf("%d",&data);
		while(temp!=NULL && temp->data!=data)
		{
			temp=temp->ptr;
		}
		if(temp!=NULL && temp->data==data)
		{
			printf("Element found!");
		}
		else
		{
			printf("Element not found!");
		}
	}
}

void count()
{
	struct Node *temp;
	int count=0;
	if(head==NULL)
	{
		printf("Count is : %d",count);
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			temp=temp->ptr;
			count++;
		}
		printf("Count is : %d",count);
	}
}

void sort()
{
	struct Node *i,*j;
	int data;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		for(i=head ; i->ptr!=NULL ; i=i->ptr)
		{
			for(j=i->ptr ; j!=NULL; j=j->ptr)
			{
				if(i->data > j->data)
				{
					data=i->data;
					i->data=j->data;
					j->data=data;
				}
			}
		}
		display();
	}
	
	
}

int main()
{
	int choice,cont;
	do
	{
		printf("Menu driven program for Singly Linked list\n");
		printf("1) Insert at Beginning\n2) Insert at Middle\n3) Insert at End\n");
		printf("4) Delete at Beginning\n5) Delete at Middle\n6) Delete at End\n");
		printf("7) Display\n8) Search\n9) Sorting\n10) Total Elements\n11) Exit\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insertAtBeg();
				break;
			case 2:
				insertAtMid();
				break;
			case 3:
				insertAtEnd();
				break;
			case 4:
				delAtBeg();
				break;
			case 5:
				delAtMid();
				break;
			case 6:
				delAtEnd();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				sort();
				break;
			case 10:
				count();
				break;
			case 11:
				exit(1);
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Press 1, if u want to continue ");
		scanf("%d",&cont);	
	} while(cont==1);
	
	return 0;
}
