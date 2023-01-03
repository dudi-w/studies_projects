#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 10
#define N 5
#define USED -1
#define FREE 0

typedef struct
{
    int row;
    int col; 
}tile;

bool path(int maze[M][N] , tile src ,tile dst);
bool inBound(tile t ,int  row ,int col);
bool used(int maze[M][N] , tile t);
bool isEqual(tile t1 ,tile t2);
tile mov(tile t , int movRow ,int movCol);
//void printMatrix(int matrix[M][N], int M ,int N);