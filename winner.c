#include <stdio.h>
#include <stdbool.h>
#include "autolink.h"

bool dp_winner_red(int no_of_links)
{
    bool dp[24][24];
    
    for(int i=0; i<24;i++)
    {
        for(int j=0; j<24;j++)
        {
            dp[i][j]=false;
        }
    }

    for(int j=0; j<24;j++)
    {
        if(board[0][j]==1)
        {
            dp[0][j]=true;
        }
    }


    for(int a=0; a<24;a++)
    {
        for(int i=0; i<24;i++)
        {
            for(int j=0; j<24;j++)
            {
                if(dp[i][j]==true)
                {
                    for(int k=0; k<no_of_links;k++)
                    {
                        if(link_array[k].player==1 && ((link_array[k].x1==i && link_array[k].y1==j) || (link_array[k].x2==i && link_array[k].y2==j)))
                        {
                            int next_x, next_y;

                            if(link_array[k].x1==i && link_array[k].y1==j)
                            {
                                next_x=link_array[k].x2;
                                next_y=link_array[k].y2;
                            }
                            else
                            {
                                next_x=link_array[k].x1;
                                next_y=link_array[k].y1;
                            }
                            if(dp[next_x][next_y]==false)
                            {
                                dp[next_x][next_y]=true;
                            }
                        }
                    }
                }
            }
        }   
    }

    for(int i=0; i<24;i++)
    {
        if(board[23][i]==1 && dp[23][i]==true)
        {
            return true;
        }
    }

    return false;
}

bool dp_winner_black(int no_of_links)
{
    bool dp[24][24];
    
    for(int i=0; i<24;i++)
    {
        for(int j=0; j<24;j++)
        {
            dp[i][j]=false;
        }
    }

    for(int j=0; j<24;j++)
    {
        if(board[j][0]==2)
        {
            dp[j][0]=true;
        }
    }

    
    for(int a=0; a<24;a++)
    {
        for(int i=0; i<24;i++)
        {
            for(int j=0; j<24;j++)
            {
                if(dp[j][i]==true)
                {
                    for(int k=0; k<no_of_links;k++)
                    {
                        if(link_array[k].player==2 && ((link_array[k].x1==j && link_array[k].y1==i) || (link_array[k].x2==j && link_array[k].y2==i)))
                        {
                            int next_x, next_y;

                            if(link_array[k].x1==j && link_array[k].y1==i)
                            {
                                next_x=link_array[k].x2;
                                next_y=link_array[k].y2;
                            }
                            else
                            {
                                next_x=link_array[k].x1;
                                next_y=link_array[k].y1;
                            }
                            if(dp[next_x][next_y]==false)
                            {
                                dp[next_x][next_y]=true;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<24;i++)
    {
        if(board[i][23]==2 && dp[i][23]==true)
        {
            return true;
        }
    }

    return false;
}


