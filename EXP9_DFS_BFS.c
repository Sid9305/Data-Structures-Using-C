//Siddhi Mehta 213
//DFS BFS
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#define MAX 5


void bfs(int adj[][MAX],int visited[],int start)
{
    int queue[MAX],front=-1,rear=-1,i,k;
    for(k=0;k<MAX;k++)
    {
        visited[k]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front)
    {
        start=queue[front++];
        printf("%c-",start + 65);

        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&&visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}


void dfs(int adj[][MAX],int visited[],int start)
{
    int stack[MAX];
    int top = -1 , i, k;
    for(k=0;k<MAX;k++)
    {
        visited[k]=0;
    }
    stack[++top]=start;
    visited[start]=1;

    while(top!=-1)
    {
        start = stack[top--];
        printf("%c-",start+65);
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i] && visited[i]==0)
            {
                stack[++top]=i;
                visited[i]=1;
                break;
            }
        }
    }
}

int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j;
    int option,size;
    do
    {
       printf("\n\tSiddhi Mehta 213\t\n\n");
       printf("\n Menu \n");
       printf("1) Enter values in graph\n2) BFS traversal\n3) DFS traversal\n4) Exit\nEnter your choice: ");
       scanf("%d",&option);
       switch(option)
       {
        case 1:
        printf("\nEnter the adjacency matrix: \n");
        for(i=0;i<MAX;i++)
        {
            for(j=0;j<MAX;j++)
            {
                scanf("%d",&adj[i][j]);
            }
        }
        break;

        case 2:
        printf("\nBFS Traversal");
        bfs(adj,visited,0);
        break;

        case 3:
        printf("\nDFS Traversal");
        dfs(adj,visited,0);
        break;

        case 4:
        exit(1);
       }
       printf("If you wish to continue, press 1..");
       scanf("%d",&option);
    } while (option!=4);
    
}
