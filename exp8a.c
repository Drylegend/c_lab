#include <stdio.h>

#define MAX_NODES 10


void BFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode) 
{
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0, currentNode, i;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) 
    {
        currentNode = queue[front++];

        printf("%d ", currentNode); 

        
        for (i = 0; i < numNodes; i++) 
        {
            if (graph[currentNode][i] && !visited[i]) 
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() 
{
    int graph[MAX_NODES][MAX_NODES] = {0};
    int numNodes, startNode, i, j;

    printf("Breadth First Search Graph Traversal:\n");
    printf("*************************************\n");
    printf("Enter the number of nodes(vertices) of a digraph: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
    for (i = 0; i < numNodes; i++) 
    {
        for (j = 0; j < numNodes; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("Nodes reachable from node %d using BFS: ", startNode);
    BFS(graph, numNodes, startNode);
    printf("\n");

    return 0;
}
