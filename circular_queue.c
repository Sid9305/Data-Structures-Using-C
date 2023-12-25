#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 5

int front=-1;
int rear=-1;
int queue[MAXSIZE];

void enqueue()
{
	int data;
	if(rear+1==front || (front==0 && rear==MAXSIZE-1))
	{
		printf("Queue Overflow");
	}
	else
	{
		printf("Enter data to be inserted: ");
		scanf("%d",&data);
		if(front==-1 && rear==-1)
		{
			front++;
			queue[++rear]=data;
		}
		else if(rear==MAXSIZE-1)
		{
			rear=0;
			queue[rear]=data;
		}
		else
		{
			queue[++rear]=data;
		}
	}
	
}

void dequeue()
{
	if(front==-1 && rear ==-1)
	{
		printf("Queue Underflow");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==MAXSIZE-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
}

void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Queue Underflow");
		return;
	}
	else 
	{
		printf("Displaying elements: ");
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("\n %d",queue[i]);
			}
		}
		else
		{
			for(i=front ; i<=MAXSIZE ; i++)
			{
				printf("\n %d",queue[i]);
			}
			for (i = 0 ; i<=rear;i++)
			{
				printf("\n %d",queue[i]);
			}
		}
	}
}

int main()
{
	int choice,cont;
	do
	{
		printf("Menu driven program for circular queue\n");
		printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Invalid choice");
				break;
		}
		printf("If you wish to continue, press 1");
		scanf("%d",&cont);
			
	}while(cont==1);

	return 0;
}
