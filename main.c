#include <stdio.h>
#include "check_peg.h"
#include "autolink.h"
#include "winner.h"
#include <string.h>
#include <ctype.h>

int no_of_links=0;
link link_array[5000]={0};

int board[24][24];
int turns=0;

int end()
{
    char c;
    printf("DO YOU WANT TO PLAY AGAIN(Y/N): \n");
    scanf(" %c", &c);
    if(c=='y'|| c=='Y') return 1;
    if(c=='n' || c=='N') return 0;

}

void reset_board()
{
    for(int i=0; i<24;i++)
    {
        for(int j=0; j<24;j++)
        {
            board[i][j]=0;
        }
    }

    no_of_links=0;
}

void display_board()
{
    printf("    ");

    for(int i=0; i<24;i++)
    {
        printf("%2d ", i);
    }

    printf("\n");

    printf("%2d ",0);

    for(int j=0; j<24;j++)
    {
        if(j==0)
        {
            printf("   |");
            continue;
        }

        else if(j==23)
        {
            continue;
        }

        else
        {
            if(board[0][j]==0) printf(" . ");
            else if(board[0][j]==1) printf(" R ");
            else printf(" B ");

            if(j==0 || j==22)
            {
                printf("|");
            }
        }
    }
    printf("\n");

    printf("   ");
    for (int i=0; i<24; i++) 
    {
        printf("---");  
    }
    printf("\n");

    for(int i=1; i<23;i++)
    {
        printf("%2d ", i);

        for(int j=0; j<24;j++)
        {
            if(board[i][j]==0) printf(" . ");
            else if(board[i][j]==1) printf(" R ");
            else printf(" B ");

            if(j==0 || j==22)
            {
                printf("|");
            }
        }

        printf("\n"); 
    }

    printf("   ");

    for(int i=0; i<24;i++)
    {
        printf("---");
    }
    printf("\n");

    printf("%2d ", 23);
        for(int j=0; j<24;j++)
        {
            if(j==0)
            {
                printf("   |");
                continue;
            }
            else if(j==23)
            {
                continue;
            }
            else
            {
                if(board[23][j]==0) printf(" . ");
                else if(board[23][j]==1) printf(" R ");
                else printf(" B ");
                if(j==0 || j==22)
                {
                    printf("|");
                }
            }
        }
        printf("\n");

        
}


int main(void)
{
    printf("WELCOME TO THE GAME OF TWIXT\n");
    printf("THE GAME WOULD BE PLAYED BETWEEN TWO PLAYERS ASSIGNED AS RED AND BLACK\n");
    printf("ENJOY AND LET THE BEST ONE WIN\n");
    printf("NOTE - RED NEEDS TO REACH FROM THE TOP FROM BOTTOM AND BLACK NEEEDS TO REACH FROM THE LEFT TO RIGHT\n");


    while(1)
    {
        display_board();
        int x,y;
        while(1)
        {
            
            int value;
            int value_1;
            char c;
            printf("ENTER THE COORDINATES (FORMAT - x <space> y: ) - \n");
            if(turns%2==0)
            {
                printf("RED's TURN:  ");
            }
            else
            {
                printf("BLACK's TURN : ");
            }

            int number = scanf("%d %d", &value, &value_1);

            if(number!=2)
            {
                printf("INAVLID INPUT. TRY AGAIN\n");
                    
                while((c=getchar())!='\n');

                continue;
            }

            c=getchar();

            if(c!='\n')
            {
                printf("INVALID INPUT. TRY AGAIN\n");
                while(c=getchar()!='\n');

                continue;
                    
            }

            x=value;
            y=value_1;
            break;
        }
        if(board[x][y]==1)
        {
            printf("RED HAS ALREADY PLACED A PIN THERE\n");
            continue;
        }
        else if(board[x][y]==2)
        {
            printf("BLACK HAS ALREADY PLACED A PIN THERE\n");
            continue;
        }
        else if(x==0 || x==23 || y==0 || y==23)
        {
            if(turns%2!=0 && (x==0 || x==23))
            {
                printf("CANNOT PLACE PIN HERE\n");
                continue;
            }
            else if(turns%2==0 && (y==0 || y==23))
            {
                printf("CANNOT PLACE PIN HERE\n");
                continue;
            }
        }

        if(check_can_be_placed(x,y))
        {
            mark_board(x,y);
            link_make(x,y);
            if(turns%2==0)
            {
                if(dp_winner_red(no_of_links))
                {
                    printf("RED WON\n");
                    if(!end())
                    {
                        break;
                    }
                    else
                    {
                        reset_board();
                        turns=0;
                        continue;
                    }

                }
                
            }

            else
            {
                if(dp_winner_black(no_of_links))
                {
                    printf("BLACK WON\n");
                    if(!end())
                    {
                        break;
                    }
                    else
                    {
                        reset_board();
                        turns=0;
                        continue;
                    }
                }
            }
            turns++;
        }
        else
        {
            printf("INVALID COORDINATES\n");
        }
    }

    

}