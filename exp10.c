#include <stdio.h>

#define INF 999
#define V 8

void printSolution(int dist[][V], int n) 
{
    int i,j;
    printf("Shortest path matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (dist[i][j] == INF) 
            {
                printf(" INF ");
            } 
            else 
            {
                printf("%4d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd(int cam[][V], int n) 
{
    int dist[V][V];

   
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            dist[i][j] = cam[i][j];
        }
    }

 
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist,n);
}

int main() 
{
   
    int cam[V][V],i,j,n;
    
    printf("\n Floyds Algorithm to find all pairs shortest paths of a graph");
    printf("\n *************************************************");
    printf("\n How many vertices in your directed weighted graph?-->");
    scanf("%d",&n);
	printf("\n Enter the Cost Adjacency matrix of your graph in the matrix form:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&cam[i][j]);
			if(cam[i][j]==0)
				cam[i][j]=INF;
		}

    floyd(cam,n);

    return 0;
}
