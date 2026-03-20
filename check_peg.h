#ifndef check_peg_H
#define check_peg_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

extern int board[24][24];
extern int turns;

bool check_can_be_placed(int x, int y);
void mark_board(int x, int y);


#endif