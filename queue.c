//queue
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 100

int front=-1,rear=-1;
int queue[MAXSIZE];

void enqueue()
{
	int data;
	printf("Enter data to be inserted: ");
	scanf("%d",&data);
	if(front==-1 && rear==-1)
	{
		queue[++rear]=data;
		front++;
	}
	else if(rear==MAXSIZE-1)
	{
		printf("Queue Overflow");
	}
	else
	{
		queue[++rear]=data;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue Underflow");
	}
	else if(front == rear)
	{
		front = -1;
		rear = -1;
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
	}
	else
	{
		printf("Elements are: \n");
		for(i=front;i<=rear;i++)
		{
			printf("%d \n",queue[i]);
		}
	}
}

int main()
{
	int choice,cont;
	do
	{
		printf("Menu driven program for queue");
		printf("\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n\nEnter your choice: ");
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
	
}
