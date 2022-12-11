#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ROW 5
#define COLUMN 2

void fillMatrix(int matrix[COLUMN][ROW], int column , int row );
void printMatrix(int matrix[COLUMN][ROW], int column , int row );
void printBigNum(int matrix[COLUMN][ROW], int column , int row );
void printSumOdd(int matrix[COLUMN][ROW], int column , int row );

int main(){
    //**int matrix = creatMatrix(COLUMN , ROW);
    int column= COLUMN;
    int row = ROW;
    int matrix[COLUMN][ROW];
    //int *[5] pmatrix = matrix;
    fillMatrix(matrix ,COLUMN, ROW );
    printMatrix(matrix, COLUMN ,ROW);
    printBigNum(matrix, COLUMN ,ROW);
    printSumOdd(matrix , COLUMN , ROW);
}

void fillMatrix(int matrix[COLUMN][ROW], int column , int row ){
    for(int i=0; i< column; i++){
        int k;
        for(int j=0; j< row; j++){
            scanf("%d",&k);
            *(*(matrix+i)+j)= k;
        }
    }
}

void printMatrix(int matrix[COLUMN][ROW], int column , int row ){
    for(int i=0; i<column; i++){
        for(int j=0; j< row; j++){
            printf("%d," , *(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void printBigNum(int matrix[COLUMN][ROW], int column , int row ){
    for(int i=0; i<column; i++){
        double n = -INFINITY;
        for(int j=0; j< row; j++){
            if ( *(*(matrix+i)+j) > n){
                n= *(*(matrix+i)+j);
            }
        }
        printf("%lf\n" , n );
    }
}

void printSumOdd(int matrix[COLUMN][ROW], int column , int row ){
    int sum = 0;
    for(int i=0; i<column; i++){
        for(int j=0; j< row; j++){
            if ( *(*(matrix+i)+j)%2==1){
                sum = sum +(*(*(matrix+i)+j));
            }
        }
    }
    printf("%d\n" , sum );
}
