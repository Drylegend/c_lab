#include<stdio.h>
#define SIZE 10
#define INFINITY 999

void prims(int cam[SIZE][SIZE],int n)
{
	int visited[SIZE],i,j,u,v,min,mincost,count;
	visited[0]=1;
	for(i=1;i<n;i++)
		visited[i]=0;
	mincost=0;
	count=1;
	printf("\n There are %d edges in this graph:\n",n-1);
	while(count<n)
	{
		min=INFINITY;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(cam[i][j]<min && visited[i]==1)
				{
					min=cam[i][j];
					u=i,v=j;
				}
			}
		if(visited[v]==0)
		{
			printf("\n %d Edge--->(%d,%d), cost=%d",count,u,v,min);
			mincost+=min;
			visited[v]=1;
			count++;
		}
		cam[u][v]=cam[v][u]=INFINITY;
	}
	printf("\n The minimal cost of the above spanning tree is--->%d",mincost);
}
int main()
{
	int cam[SIZE][SIZE],i,j,n;
	printf("\n Prims Algorithm to find MCSP of a weighted graph");
	printf("\n ************************************************");
	printf("\n Get the cost adjacency matrix ready for your undirected weighted graph.\n");
	printf("\n Enter how many vertices--->");
	scanf("%d",&n);
	printf("\n Enter the cost adjacency matrix in matrix form:(For no edge enter 0):\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cam[i][j]);

			if(cam[i][j]==0)
				cam[i][j]=INFINITY;
		}
	}
	printf("\n The minimum spanning tree for the given graph is:\n");
	prims(cam,n);
	printf("\n");
	return(0);

}
