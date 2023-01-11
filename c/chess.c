#include <stdio.h>
#include <math.h>

#define LENGTH 8
static int bord[LENGTH][LENGTH];
static int count=0;

void printBord(){
    //printf("count = %d\n",++count);
    for(int i=0;i<LENGTH;++i){
        for(int j=0;j<LENGTH;++j){
            if(bord[i][j]){
                printf("\033[1;31m%d\033[0m | ",bord[i][j]);
            }
            else{
                printf("%d | ",bord[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int func(int row){
    if(row >=LENGTH)
        return 1;
    
    
    for(int i=0;i<LENGTH ;++i){
        int test=1;
        bord[row][i]=1;
        //printBord();
        count++;
        for(int j=0;j<LENGTH && bord[row][i];++j){
            if((bord[j][i] && j!=row) || (bord[row][j] && j!=i) ){
                test =0;
                bord[row][i]=0;
                //break;
            }
            
            for(int k=0;k<LENGTH && bord[row][i] ;++k){
                if(bord[j][k] && j!=row && fabs(j-row)==fabs(k-i)){
                    test =0;
                    bord[row][i]=0;
                    //break;
                }
            }
        }
        if(!test){
            continue;
        }
        test = func(row+1);
        if(test){
            return 1;
        }
        bord[row][i]=0;
    }
    return 0;
}

int main(){
    //bord[0][3]=1;
    func(0);
    printBord();
}