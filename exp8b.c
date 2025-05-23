#include <stdio.h>
#define MAX_NODES 10

void DFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int currentNode, int visited[]) 
{
    int i;
    visited[currentNode] = 1;

    for (i = 0; i < numNodes; i++) 
    {
        if (graph[currentNode][i] && !visited[i]) 
        {
            DFS(graph, numNodes, i, visited);
        }
    }
}


int isConnected(int graph[MAX_NODES][MAX_NODES], int numNodes) 
{
    int visited[MAX_NODES] = {0};
    int i;


    DFS(graph, numNodes, 0, visited);


    for (i = 0; i < numNodes; i++) 
    {
        if (!visited[i]) 
        {
            return 0;
        }
    }

    return 1;
}

int main() 
{
    int graph[MAX_NODES][MAX_NODES] = {0};
    int numNodes, i,j;
    
    printf("Depth First Search Graph Traversal:\n");
    printf("*************************************\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
    for (i = 0; i < numNodes; i++) 
    {
        for (j = 0; j < numNodes; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isConnected(graph, numNodes)) 
    {
        printf("The graph is connected.\n");
    } 
    else 
    {
        printf("The graph is not connected.\n");
    }

    return 0;
}
