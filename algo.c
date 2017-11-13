#include "includes/fdf.h"

/*
 * DDA-algorithm implementation
 */

void	make_variables(t_map *f, t_o f1, t_o f2)
{
    f->deltax = f2.xi - f1.xi;
    f->deltay = f2.yi - f1.yi;
    f->incr_x = f->deltax > 0 ? 1 : -1;
    f->incr_y = f->deltay > 0 ? 1 : -1;
    f->deltax = abs(f->deltax);
    f->deltay = abs(f->deltay);
    if (f->deltax > f->deltay)
    {
        f->incdeltax = f->incr_x;
        f->incdeltay = 0;
        f->h_delta = f->deltax;
        f->delta_err = f->deltay;
    }
    else
    {
        f->incdeltax = 0;
        f->incdeltay = f->incr_y;
        f->h_delta = f->deltay;
        f->delta_err = f->deltax;
    }
    f->err = f->h_delta / 2;
}

void	draw(t_map *f, t_o f1, t_o f2)
{
    int k;
    int x;
    int y;

    make_variables(f, f1, f2);
    x = f1.xi;
    y = f1.yi;
    k = -1;
    f->im[x * f->bpp / 8 + f->sl * y] = (char) f1.c;
    f->im[x * f->bpp / 8 + f->sl * y + 1] = (char) (f1.c >> 8);
    f->im[x * f->bpp / 8 + f->sl * y + 2] = (char) (f1.c >> 16);
    while (++k < f->h_delta)
    {
        f->err -= f->delta_err;
        if (f->err < 0)
        {
            f->err += f->h_delta;
            x += f->incr_x;
            y += f->incr_y;
        }
        else
        {
            x += f->incdeltax;
            y += f->incdeltay;
        }
        f->im[x * f->bpp / 8 + f->sl * y] = (char) f1.c;
        f->im[x * f->bpp / 8 + f->sl * y + 1] = (char) (f1.c >> 8);
        f->im[x * f->bpp / 8 + f->sl * y + 2] = (char) (f1.c >> 16);
    }
}


void fdf_dda(t_o f, t_o e, int x1, int y1 , t_map *m)
{
    float deltax;
    float deltay;
    int len;

    x1 = (int)f.xi;
    y1 = (int)f.yi;
    deltax = abs((int)(f.xi - e.xi));
    deltay = abs((int)(f.yi - e.yi));
    len = deltax < deltay ? (int)deltay : (int)deltax;
    deltax = (e.xi - f.xi) / len;
    deltay = (e.yi - f.yi) / len;
    while (len--)
    {
        x1 += deltax;
        y1 += deltay;
        if (x1 > 0 && x1 < WIDTH && y1 > 0 && y1 < HEIGHT)
        {
            m->im[x1 * m->bpp / 8 + m->sl * y1] = (char) f.c;
            m->im[x1 * m->bpp / 8 + m->sl * y1 + 1] = (char) (f.c >> 8);
            m->im[x1 * m->bpp / 8 + m->sl * y1 + 2] = (char) (f.c >> 16);
        }
    }
}

void fdf_4all(t_map *m)
{
    int i,j;

    i = -1;
    while (++i < m->y)
    {
        j = -1;
        while (++j < m->x)
        {
            if (j != m->x - 1)

                //fdf_dda(m->f[i][j], m->f[i][j + 1], 0, 0, m);
                draw(m, m->f[i][j], m->f[i][j + 1]);
            if (i != m->y - 1)
                draw(m, m->f[i][j], m->f[i + 1][j]);
               // fdf_dda(m->f[i][j], m->f[i + 1][j], 0, 0, m);
        }
    }
}

void    fdf_rot(float *x, float *y, float *z, int *v)
{
    float vs;
    float vc;

    vs = (float)sin(*v * M_PI / 180);
    vc = (float)cos(*v * M_PI / 180);

    // revert on x
//    *y = (*y * vc) + (*z * vs);
//    *z = ((*y) * vs * -1) + (*z * vc);
//     revert on Y
    *x = (*x * vc) + (*z * vs);
    *z = (-1 * (*x) * vs) + (*z * vc);
//    //re
// vert on Z
//    *x = (*x * vc) + (*y * vs);
//    *y = (-(*x) * vs) + (*y * vc);
}

void    fdf_recalc(t_map *m, t_o **f)
{
    int i,j;

    i = -1;
    while (++i < m->y)
    {
        j = -1;
        while (++j < m->x)
        {
           // if (fi[i][j].v != fi[i][j].vi)
            //if (fi[i][j].zi)
            f[i][j].xi = ((f[i][j].x + m->xmove) * m->zoom);
            f[i][j].yi = ((f[i][j].y + m->ymove) * m->zoom);
            f[i][j].zi = (m->f[i][j].z + m->zmove) * m->zoom;
            fdf_rot(&f[i][j].xi, &f[i][j].yi, &f[i][j].zi, &m->a);
        }
    }
}