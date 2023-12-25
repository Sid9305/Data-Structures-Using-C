#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX];

void display()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("%d\n",arr[i]);
	}
}

void linear()
{
	int i,j,n,num,hashkey,collision=0;
	printf("Number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element: ");
		scanf("%d",&num);
		for(j=0;j<MAX;j++)
		{
			hashkey=((num+j)%MAX);
			if(arr[hashkey]==-1)
			{
				arr[hashkey]=num;
				break;
			}
			else
			{
				collision++;
				printf("\nCollision occurred at %d",hashkey);
				continue;
			}
		}
	}
	display();
}

void quadratic()
{
	int i,j,n,num,hashkey,collision=0;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element to be inserted: ");
		scanf("%d",&num);
		for(j=0;j<MAX;j++)
		{
			hashkey=(num+(j*j))%MAX;
			if(arr[hashkey]==-1)
			{
				arr[hashkey]=num;
				break;
			}
			else
			{
				collision++;
				printf("\nCollision occured at : %d",hashkey);
				continue;
			}
		}
	}
	display();
}

void double_hashing()
{
	int i,j,n,num,hashkey1,hashkey2,collision=0;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element to be inserted: ");
		scanf("%d",&num);
		
		hashkey1=num % MAX;
		hashkey2=num % (MAX-1);
		
		for(j=0;j<MAX;j++)
		{
			if(arr[hashkey1]==-1)
			{
				arr[hashkey1]=num;
				break;
			}
			else
			{
				hashkey1=(hashkey1 + (j*hashkey2))%MAX;
				collision++;
				printf("\nCollision occured at : %d\n",hashkey1);
				continue;
			}
		}
	}
	display();
}

int main()
{
	int i,choice,cont;
	for(i=0;i<MAX;i++)
	{
		arr[i]=-1;
	}
	printf("Menu driven program for hashing : \n");
	printf("1) Linear Probing\n2) Quadratic Probing\n3) Double Hashing\n4) Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			linear();
			break;
		case 2:
			quadratic();
			break;
		case 3:
			double_hashing();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("Invalid choice \n");
			break;
	}
}
