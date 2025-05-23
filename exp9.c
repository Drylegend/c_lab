#include <stdio.h>

int board[8][8];


void printBoard(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col, int n) 
{
    int i,j;
  
    for (i = 0; i < col; i++) 
    {
        if (board[row][i] == 1) 
        {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) 
        {
            return 0;
        }
    }

    
    for (i = row, j = col; i < n && j >= 0; i++, j--) 
    {
        if (board[i][j] == 1) 
        {
            return 0;
        }
    }

    return 1;
}


int solveNQueens(int col, int n) 
{
    int i;
    
    if (col == n) 
    {
        return 1;
    }

    for (i = 0; i < n; i++) 
    {

        if (isSafe(i, col, n)) 
        {
            
            board[i][col] = 1;

            
            if (solveNQueens(col + 1,n)) 
            {
                return 1;
            }


            board[i][col] = 0;
        }
    }

    return 0;
}

int main() 
{
    int i,j,n;
    printf("\n N-Queens");
    printf("\n *************************");
    
    do
    {
        printf("\n How many queens?-->");
        scanf("%d", &n);
        if(n<4 || n>8)
            printf("\n Enter the number of queens(>=4 and <=8");
    }while(n<4 || n>8);
    

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            board[i][j] = 0;
        }
    }


    if (solveNQueens(0,n)) 
    {
        printf("Solution found:\n");
        printBoard(n);
    } else 
    {
        printf("No solution exists.\n");
    }

    return 0;
}
