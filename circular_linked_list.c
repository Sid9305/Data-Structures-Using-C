#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *ptr;
};

struct Node *head = NULL;

struct Node *createNode()
{
	int data;
	struct Node *node = malloc(sizeof(struct Node));
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

void insertAtBeg()
{
	struct Node *temp,*node;
	node = createNode();
	if(node == NULL)
	{
		printf("Memory Overflow");
	}
	else
	{
		if(head==NULL)
		{
			head=node;
			node->ptr=node;
		}
		else
		{
			temp=head;
			while(temp->ptr!=head)
			{
				temp=temp->ptr;
			}
			temp->ptr=node;
			node->ptr=head;
			head=node;
		}
	}
}

void insertAtEnd()
{
	struct Node *temp, *node;
	node = createNode();
	if(node==NULL)
	{
		printf("Memory Overflow");
	}
	else
	{
		if(head==NULL)
		{
			head=node;
			node->ptr=node;
		}
		else
		{
			temp=head;
			while(temp->ptr!=head)
			{
				temp=temp->ptr;
			}
			temp->ptr=node;
			node->ptr=head;
		}
	}
	
}

void delAtBeg()
{
	struct Node *temp,*temp1;
	if(head==NULL)
	{
		printf("Memory Underflow");
	}
	else if(head->ptr==head)
	{
		temp=head;
		free(temp);
		head=NULL;
	}
	else
	{
		temp=head;
		temp1=head;
		while(temp->ptr!=temp1)
		{
			temp=temp->ptr;
		}
		temp->ptr=temp1->ptr;
		head=temp1->ptr;
		free(temp1);
	}
}


void delAtEnd()
{
	struct Node *temp,*temp1;
	if(head==NULL)
	{
		printf("Memory Underflow");
	}
	else
	{
		temp=NULL;
		temp1=head;
		while(temp1->ptr!=head)
		{
			temp=temp1;
			temp1=temp1->ptr;
		}
		if(head==temp1)
		{
			head=NULL;
			free(temp1);
			return;
		}
		temp->ptr=head;
		free(temp1);
	}
}

void display()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("Memory Underflow\n");
    }
    else
    {
        printf("Elements are: ");
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->ptr;
        } while (temp != head);
        printf("\n");
    }
}

int countNode()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("Memory Underflow\n");
    }
    else
    {
        int count=0;
        temp = head;
        do
        {
            count++;
            temp = temp->ptr;
        } while (temp != head);
        return count;
    }
}

int main()
{
	int choice,cont;
	do
	{
		printf("Menu driven circular linked list\n");
		printf("1) Insert at Beginning\n2) Insert at End\n");
		printf("3) Delete at Beginning\n4) Delete at End\n");
		printf("5) Display\n6) Count Nodes\n7) Exit\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insertAtBeg();
				break;
			case 2:
				insertAtEnd();
				break;
			case 3:
				delAtBeg();
				break;
			case 4:
				delAtEnd();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Number of nodes : %d",countNode());
				break;
			case 7:
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
