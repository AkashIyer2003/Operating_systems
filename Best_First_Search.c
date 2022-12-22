#include <stdio.h>
#define MAX 10
int n,adj[MAX][MAX];
void breadth_first_search(int adj[][MAX],int visited[],int start)
    {
        int queue[MAX], rear = -1, front = -1, i;
        queue[++rear] = start;
        visited[start] = 1;
        while(rear != front)
		{
start = queue[++front];
if(start == 4)
         printf("5\t");
else
         printf("%c \t",start + 65);
for(i = 0; i < MAX; i++)
{
if(adj[start][i] == 1 && visited[i] == 0)
{
queue[++rear] = i;
visited[i] = 1;
}
}
}
}
int main()
{
int visited[MAX] = {0};
int i,max_edges,org,dest;
printf("\n Enter the number of vertices: ");
scanf("%d",&n);
max_edges = n*(n - 1);
         for(i = 1; i <= max_edges; i++)
{
printf("\n Enter edge %d(0 to quit): ",i);
scanf("%d %d",&org,&dest);
if((org == 0) && (dest == 0))
break;
if( org > n || dest > n || org <= 0 || dest <= 0)
{
         printf("\n Invalid edge");
i--;
}
else
adj[org][dest] = 1;
}
breadth_first_search(adj,visited,0);
}
