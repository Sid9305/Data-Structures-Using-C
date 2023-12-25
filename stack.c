#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;		
	}	
}

void push()
{
	int data;
	printf("Enter data to be inserted: ");
	scanf("%d",&data);
	if(isEmpty()==1)
	{
		stack[++top]=data;
	}
	else if(top==(MAXSIZE-1))
	{
		printf("Cannot Insert, Stack Overflow");
	}
	else
	{
		stack[++top]=data;
	}
	
}


void pop()
{
	if(isEmpty()==1)
	{
		printf("Stack Underflow,Cannot delete");
	}
	else
	{
		top--;
	}
}
void display()
{
	int i;
	if(isEmpty()==1)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("Stack elements: ");
		for(i=top;i>=0;i--)
		{
			printf("%d \n",stack[i]);
		}
	}
}

int main()
{
	int choice,cont;
	do
	{
		printf("\n\nMenu-driven stack code\n\n");
		printf("1) Insertion(Push)\n2) Deletion(Pop)\n3) Display\n4) Exit\n\nEnter your choice: ");
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
				printf("Invalid choice");
				break;
		}
		printf("If you would like to continue, press 1");
		scanf("%d",&cont);
	}while(cont==1);
	
	return 0;
}
