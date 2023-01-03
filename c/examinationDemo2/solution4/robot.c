#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "solution4.h"

/*#define M 6
#define N 6
#define USED -1
#define FREE 0

typedef struct
{
    int row;
    int col; 
}tile;*/

bool inBound(tile t ,int  row ,int col){
    if(t.row >= row || t.row <0 || t.col >= col || t.col <0)
        return false;
    return true;
}

bool used(int maze[M][N] , tile t){
    if(maze[t.row][t.col]== USED){
        return true;
    }
        
    return false;
}

bool isEqual(tile t1 ,tile t2){
    if(t1.col == t2.col && t1.row == t2.row)
        return true;
    return false;
}

tile mov(tile t , int movRow ,int movCol){
    t.row+=movRow;
    t.col+=movCol;
    return t;
}
void printMatrix(int matrix[M][N], int m ,int n){
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            printf("%d, ",matrix[i][j]);
        }
        printf("\n");
    }
}

bool path(int maze[M][N] , tile src ,tile dst){

    printf("row=%d\tcol=%d\n",src.row, src.col);
    printMatrix(maze , M ,N);
    if(used(maze,src))
        return false;
    if(!inBound(src , M ,N))
        return false;
    if(isEqual(src,dst))
        return true;
    maze[src.row][src.col]= USED;
    return (path(maze , mov(src,0,1) , dst)\
         || path(maze , mov(src,0,-1) , dst)\
         || path(maze , mov(src,1,0) , dst)\
         || path(maze , mov(src,-1,0) , dst))\
        ?true:false; 
}
