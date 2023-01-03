#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution4.h"

int main(){
    int maze[M][N]={{0,0,-1,0,0},
                    {0,0,-1,0,0},
                    {0,0,-1,0,0},
                    {0,0,-1,0,0},
                    {0,0,-1,0,0},
                    {0,0,-1,0,0},
                    {0,0,0,-1,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0}};
    tile src ={0,0};
    tile dst ={8,4};
    printf("%d\n",path(maze,src,dst));
    return 0;
}