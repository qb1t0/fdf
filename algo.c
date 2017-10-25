#include "includes/fdf.h"

/*
 * DDA-algorithm implementation
 */

void fdf_dda(t_o f, t_o e, int x1, int y1 , t_map *m)
{
    float deltax;
    float deltay;
    int len;

    deltax = abs((int)f.x - (int)e.x);
    deltay = abs((int)f.y - (int)e.y);
    x1 = (int)f.x;
    y1 = (int)f.y;
    len = deltax < deltay ? (int)deltay : (int)deltax;
    deltax = (e.x - f.x) / len;
    deltay = (e.y - f.y) / len;
    len++;
    while (len--)
    {
        x1 += deltax;
        y1 += deltay;
        char k = (char)f.c;
        k = (char)(f.c >> 8);
        k = (char)(f.c >> 16);
        //mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
        m->im[x1 * m->bpp / 8 + m->sl * y1] = (char)f.c;
        m->im[x1 * m->bpp / 8 + m->sl * y1 + 1] = (char)(f.c >> 8);
        m->im[x1 * m->bpp / 8 + m->sl * y1 + 2] = (char)(f.c >> 16);
        //print here
    }
}

void fdf_4all(t_map *m, t_o f[m->y][m->x])
{
    int i,j;

    i = -1;
    j = -1;
    while (++i < m->y - 1)
        while (++j < m->x - 1)
        {
            fdf_dda(f[i][j], f[i][j + 1], 0 ,0, m);
            fdf_dda(f[i][j], f[i + 1][j], 0, 0, m);
        }
}