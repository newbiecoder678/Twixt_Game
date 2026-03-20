#include <stdio.h>
#include <stdbool.h>
#include "autolink.h"



int two_d_det(int a, int b, int c, int d)
{
    return a*d-b*c;
}

bool check_if_line_intersects(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
   
    if((x1==x3 && y1==y3) || (x1==x4 && y1==y4) || (x2==x3 && y2==y3) || (x2==x4 && y2==y4))
    {
        return false;
    }

    int det = two_d_det(x2-x1, x3-x4, y2-y1, y3-y4);

    if(det==0) return false;

    if(det!=0)
    {
        int det_1 = two_d_det(x3-x1, x3-x4, y3-y1, y3-y4);
        float value_1 = (float)det_1/(float)det;

        int det_2 = two_d_det(x2-x1, x3-x1, y2-y1, y3-y1);
        float value_2 = (float)det_2/(float)det;

        if(value_1>=0 && value_1<=1 && value_2>=0 && value_2<=1)
        {
            return true;
        }
    }
    return false;
}