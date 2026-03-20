#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "check_peg.h"


bool check_can_be_placed(int x, int y)
{
    if(x==0 && y==0 || x==0 && y==23 || x==23 && y==0 || x==23 && y==23)
    {
        return false;
    }
    if(board[x][y]==0 && x>=0 && x<24 && y>=0 && y<24)
    {
        return true;
    }
    return false;
}  


void mark_board(int x, int y)
{
    if(check_can_be_placed(x,y))
    {
        if(turns%2==0)
        {
            board[x][y]=1;
        }
        else
        {
            board[x][y]=2;
        }
    }
}





 













