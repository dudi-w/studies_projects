#include <stdio.h>

/*The "Towers of Hanoi" is a famous game in which three rods are threaded with rings
of different sizes in descending order (i.e. the largest at the bottom). At the beginning
of the game the rings are all threaded onto the first rod. The goal of the game is to
move them all to the third rod in the same order they were on the first rod.
However, you may move only one ring at a time, and cannot place a small ring on a
larger one.
Write a function that receives the number of rings in the Towers of Hanoi and prints
the steps of the solution to transfer all the rings from rod A to rod C in order (you may
use rod B as an auxiliary rod).*/

void towersofHanoi(int n ,char a , char b, char c){
    if(n<1)
        return;
    towersofHanoi(n-1, a , c , b);
    printf("Move the %dth ring from rod %c to rod %c\n", n ,a, b);
    towersofHanoi(n-1, c , b , a);
}

int main(){
    towersofHanoi(3, 'x', 'y', 'z');
    return 0;
}

