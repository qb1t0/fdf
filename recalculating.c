//
// Created by Yaroslav Salata on 11/16/17.
//
#include "includes/fdf.h"

/*
** Rotating each coordinate axis on corner (xaxis/yaxis)
*/

void    fdf_rotation(float *x, float *y, float *z, t_map *m)
{
    float xs;
    float xc;
    float ys;
    float yc;
    float z1;

    xs = (float)sin(m->xaxis * M_PI / 180);
    xc = (float)cos(m->xaxis * M_PI / 180);
    ys = (float)sin(m->yaxis * M_PI / 180);
    yc = (float)cos(m->yaxis * M_PI / 180);
//  revert on x
    z1 = *z;
    *y = ((*y - m->f[m->y/2][m->x/2].y) * xc) + (*z * xs) + m->f[m->y/2][m->x/2].y;
    *z = (*y * xs * -1) + (*z * xc);
//  revert on Y
    *x = ((*x - m->f[m->y/2][m->x/2].x) * yc) + (z1 * ys) + m->f[m->y/2][m->x/2].x;
    *z = (-1 * (*x) * ys) + (z1 * yc);
////  revert on Z
//    *x = (*x * xc) + (*y * xs);
//    *y = (-1 * (*x) * xs) + (*y * xc);
}

void    fdf_recalculate(t_map *m, t_o **f)
{
    int i,j;

    i = -1;
    m->centerx =  m->f[m->y/2][m->x/2].x;//WIDTH/2 - m->x/2;
    m->centery =  m->f[m->y/2][m->x/2].y;//HEIGHT/2 - m->y/2;

    while (++i < m->y)
    {
        j = -1;
        while (++j < m->x)
        {
            f[i][j].c -= 500;
            if (f[i][j].z) {
                f[i][j].zi = (m->f[i][j].z + m->zmove) * m->zoom;
            }
            else {
                f[i][j].zi = (m->f[i][j].z) * m->zoom;
            }
            f[i][j].xi = ((f[i][j].x  - m->centerx + m->xmove) * m->zoom) + m->centerx;
            f[i][j].yi = ((f[i][j].y - m->centery + m->ymove) * m->zoom) + m->centery;
            fdf_rotation(&f[i][j].xi, &f[i][j].yi, &f[i][j].zi, m);
        }
    }
}