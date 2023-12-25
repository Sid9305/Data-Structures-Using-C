//infix to postfix
#include<stdio.h>
#include<conio.h>
#define MAXSIZE 100
char infix[MAXSIZE];
char stack[MAXSIZE];
int top=-1,res_top=-1;

int isAlphaNumeric(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z' ) || (c>=0 && c<=9))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char c)
{
	if(top==MAXSIZE-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		stack[++top]=c;
	}
}

char pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
		return '\0';
	}
	else
	{
		return stack[top--];
	}
}

int precedence(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='/' || c=='*')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


void conversion()
{
	int i;
	char result[MAXSIZE];
	for(i=0;infix[i]!='\0';i++)
	{
		if(isAlphaNumeric(infix[i]))
		{
			result[++res_top]=infix[i];
		}
		else if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(top!=-1 && stack[top]!='(')
			{
				result[++res_top]=pop();
			}
			if(top!=-1 && stack[top]=='(')
			{
				pop();
			}
			else
			{
				printf("Invalid expression");
				return ;
			}
		}
		else
		{
			while(top!=-1 && precedence(infix[i])<=precedence(stack[top]))
			{
				result[++res_top]=pop();
			}
			push(infix[i]);
		}
	}
	while(top!=-1)
	{
		result[++res_top]=pop();
	}
	result[++res_top]='\0';
	printf("\nPostfix: %s",result);
	
}

int main()
{
	printf("Enter your infix expression: ");
	scanf("%s",infix);
	conversion();
	return 0;
}
