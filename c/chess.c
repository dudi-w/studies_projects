#include <stdio.h>
#include <math.h>

#define LENGTH 8
static int bord[LENGTH][LENGTH];

void printBord(){
    for(int i=0;i<LENGTH;++i){
        for(int j=0;j<LENGTH;++j){
            printf("%d | ",bord[i][j]);
        }
        printf("\n");
    }
}

int func(int row){
    printf("bord[%d]\n",row);
    if(row >=LENGTH)
        return 1;
    
    int test=1;
    int i=0;
    for(;i<LENGTH ;++i){
        bord[row][i]=1;
        printf("bord[%d][%d]\n",row,i);

        for(int j=0;j<LENGTH;++j){
            if(bord[j][i] && j!=row){
                test =0;
                bord[row][i]=0;
            }
            else{
                for(int k=0;k<LENGTH;++k){
                    if(bord[j][k] && fabs(j-row)==fabs(k-i)){
                        test =0;
                        bord[row][i]=0;
                    }
                }
            }
        }
        printf("test = %d\n",test);
        if(!test){
            continue;
        }
        test = func(++row);
        if(test){
            return 1;
        }
    }
}

int main(){
    printf("%d\n",func(0));
    printBord();
}