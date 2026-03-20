#ifndef winner_H
#define winner_H

#include <stdio.h>
#include <stdbool.h>
#include "autolink.h"


extern link link_array[5000];
extern int no_of_links;
extern int board[24][24];

bool dp_winner_red(int no_of_links);
bool dp_winner_black(int no_of_links);


#endif