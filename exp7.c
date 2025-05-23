#include <stdio.h>

#define MAX_CITIES 4
#define INF 999

int cam[MAX_CITIES][MAX_CITIES];
int numCities;


int optimalTSP(int mask, int pos) 
{
    int minCost, city, newCost;
    if (mask == (1 << numCities) - 1) 
        return cam[pos][0];

    minCost = INF;

    for (city = 0; city < numCities; city++) 
    {
        if ((mask & (1 << city)) == 0) 
	    {
            newCost = cam[pos][city] + optimalTSP(mask | (1 << city), city);
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    return minCost;
}


int approximateTSP() 
{
	int i, nearestCity, minCost, nextCity;

	int visited[MAX_CITIES] = {0};
    	int currentCity = 0; 
    	int totalCost = 0; 
	

    	visited[currentCity] = 1; 

    	for (i = 0; i < numCities - 1; i++) 
    	{
        	nearestCity = -1;
        	minCost = INF;

        	
		for (nextCity = 0; nextCity < numCities; nextCity++) 
		{
            		if (!visited[nextCity] && cam[currentCity][nextCity] < minCost) 
	    		{
                		nearestCity = nextCity;
                		minCost = cam[currentCity][nextCity];
            		}
        	}

        	visited[nearestCity] = 1; 
        	totalCost += minCost; 
        	currentCity = nearestCity; 
    	}

    	totalCost += cam[currentCity][0];

    	return totalCost;
}

int main() 
{	
	int i, j, optimalCost, approximateCost, error;

    	printf("\n TSP with Dynamic Programming and Nearest Neighbor Algorithm");
	printf("\n ***********************************************************");
	printf("\n Get the cost adjacency matrix ready for a weighted graph.\n");

	printf("\n Enter how many cities?(No more than 4 Cities)--->");
	scanf("%d",&numCities);

	printf("\n Enter the cost adjacency matrix in matrix form:(For no edge enter 0):\n");
	for(i=0;i<numCities;i++)
	{
		for(j=0;j<numCities;j++)
		{
			scanf("%d",&cam[i][j]);
			if(i!=j && cam[i][j]==0)
				cam[i][j]=INF;
		}
	}

    	optimalCost = optimalTSP(1, 0);
    	approximateCost = approximateTSP();
    	error = approximateCost - optimalCost;

	printf("Optimal TSP Cost: %d\n", optimalCost);
    	printf("Approximate TSP Cost: %d\n", approximateCost);
    	printf("Error in Approximation: %d\n", error);

    	return 0;
}
