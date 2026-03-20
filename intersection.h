#ifndef intersection_H
#define intersection_H

#include <stdio.h>
#include <stdbool.h>
#include "autolink.h"


int two_d_det(int a, int b, int c, int d);
bool check_if_line_intersects(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);


#endif