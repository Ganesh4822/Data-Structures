/*
In the Towers of Hanoi puzzle, we are given a platform with three pegs, a,
b, and c, sticking out of it. On peg a is a stack of n disks, each larger than
the next, so that the smallest is on the top and the largest is on the bottom.
The puzzle is to move all the disks from peg a to peg c, moving one disk
at a time, so that we never place a larger disk on top of a smaller one.
Describe a recursive algorithm for solving the Towers of Hanoi puzzle for
arbitrary n.
(Hint: Consider first the subproblem of moving all but the nth disk from
peg a to another peg using the third as “temporary storage.”)
*/
/*
Algorithm
Shift N-1 pegs from A to B using c
Shift the last Peg from A to C
shift N-1 pegs from B to C using A.
*/

#include<stdio.h>
void TowerOfHanoi(int NumberOfPegs, char FromRod, char ToRod, char HelperRod)
{
    if(NumberOfPegs == 0)
        return;
    TowerOfHanoi(NumberOfPegs - 1 , FromRod, HelperRod,ToRod);
    printf("Move %d from %c to %c\n",NumberOfPegs,FromRod,ToRod);
    TowerOfHanoi(NumberOfPegs - 1,HelperRod,ToRod,FromRod);
}


int main()
{
    int n = 5;
    TowerOfHanoi(n,'A','C','B');

}
