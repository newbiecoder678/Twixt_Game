#ifndef autolink_H
#define autolink_H


#include <stdio.h>
#include <stdbool.h>

typedef struct link
{
    int x1;
    int y1;
    int x2;
    int y2;
    int player;
}link;

extern link link_array[5000]; 
extern int no_of_links;
extern int board[24][24];
extern int turns;



extern int knight_moves[8][2];

void link_make(int x, int y);
void create_link_red(int x, int y, int nx, int ny);
void create_link_black(int x, int y, int nx, int ny);
bool link_exists(int x1, int y1, int x2, int y2, int player);
bool check_if_link_possible(link current_link, int no_of_links);
bool check_if_line_intersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
int two_d_det(int a, int b, int c, int d);


#endif