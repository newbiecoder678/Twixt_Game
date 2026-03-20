#include <stdio.h>
#include <stdbool.h>
#include "autolink.h"
#include "intersection.h"



bool link_exists(int x1, int y1, int x2, int y2, int player)
{
    for(int i=0; i<no_of_links; i++)
    {
        if(link_array[i].player == player)
        {
            
            if((link_array[i].x1==x1 && link_array[i].y1==y1 && link_array[i].x2==x2 && link_array[i].y2==y2) ||(link_array[i].x1==x2 && link_array[i].y1==y2 && link_array[i].x2==x1 && link_array[i].y2==y1))
            {
                return true;
            }
        }
    }
    return false;
}


void create_link_red(int x, int y, int nx, int ny)
{

    if(link_exists(x,y,nx,ny,1)) return;

    link current_link;
    current_link.x1=x;
    current_link.y1=y;
    current_link.x2=nx;
    current_link.y2=ny;
    current_link.player=1;


    

    if(check_if_link_possible(current_link, no_of_links))
    {
        link_array[(no_of_links)++]=current_link;
    }
    
}   

void create_link_black(int x, int y, int nx, int ny)
{
    if(link_exists(x,y,nx,ny,2)) return;

    link current_link;
    current_link.x1=x;
    current_link.y1=y;
    current_link.x2=nx;
    current_link.y2=ny;
    current_link.player=2;
    

    if(check_if_link_possible(current_link, no_of_links))
    {
        link_array[no_of_links++]=current_link;
    }
}  




int knight_moves[8][2]={{1,2}, {2,1}, {1,-2}, {2,-1},
{-1,2}, {-2,1}, {-1,-2}, {-2,-1}};


void link_make(int x, int y)
{   
    for(int i=0; i<8;i++)
    {
        int new_x = x+knight_moves[i][0];
        int new_y = y+knight_moves[i][1];
        
        if(new_x>=24 || new_y <0 || new_x<0 || new_y>=24) continue;

        if(turns%2==0)
        {
            if(board[new_x][new_y]==1)
            {
                create_link_red(x,y,new_x,new_y);
            }
            
        }
        else
        {
            if(board[new_x][new_y]==2)
            {
                create_link_black(x,y,new_x,new_y);
            }
            
        }
    }
}



bool check_if_link_possible(link current_link, int no_of_links)
{
    if(no_of_links==0) return true;

    for(int i=0; i<no_of_links;i++)
    {
        if(check_if_line_intersects(current_link.x1,current_link.y1, current_link.x2, current_link.y2, link_array[i].x1, link_array[i].y1, link_array[i].x2, link_array[i].y2))
        {
            return false;
        }
    }
    return true;
}




