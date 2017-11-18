//
// Created by Yaroslav Salata on 11/16/17.
//
#include "includes/fdf.h"


void    fdf_setdefault(t_map *m)
{
    m->xmove = 0;
    m->ymove = 0;
    m->zmove = 0;
    m->a = 20;
    m->zoom = 1;
    m->xaxis = -50;
    m->yaxis = 20;
}

int     fdf_onmouse(int mouse, int x, int y, t_map *m)
{
    printf("mouse buttn: %d\n", mouse);
    if (mouse == 1 || !mouse)
    {
        m->on = mouse ? 1 : 0;
        return (0);
    }
    mlx_do_sync(m->mlx);
    mlx_clear_window(m->mlx, m->win);
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    if (mouse == 4)
        m->xaxis < 90 ? m->xaxis += 5 : 0;
    else if (mouse == 5)
        m->xaxis > -90 ? m->xaxis -= 5 : 0;
    else if (mouse == 6)
        m->yaxis < 90 ? m->yaxis += 5 : 0;
    else if (mouse == 7)
        m->yaxis > -90 ? m->yaxis -= 5 : 0;
    fdf_drawwindow(m, 1);
    return (0);
}

int     fdf_onbutton(int button, t_map *m)
{
    mlx_do_sync(m->mlx);
    mlx_clear_window(m->mlx, m->win);
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    printf("lol");
    if (button == 124)
        m->xmove += 10;
    else if (button == 123)
        m->xmove -= 10;
    else if (button == 126)
        m->ymove -= 10;
    else if (button == 125)
        m->ymove += 10;
    else if (button == 91)
        m->zoom *= 1.1;
    else if (button == 84)
        m->zoom /= 1.1;
    else if (button == 116)
        m->zmove += 10;//m->zoom *= 1.1;//m->zmove += 10;
    else if (button == 121)
        m->zmove -= 10;//m->zoom /= 1.1;//m->zmove -= 10;
    else if (button == 53)
        exit(0);
    if (button == 49)
        fdf_drawwindow(m, -1);
    else
        fdf_drawwindow(m, 1);
}

/*
** Drawing new mlx window
** code == 1 ? redrawing : new draw;
*/

void    fdf_drawwindow(t_map *m, int code)
{
    //mlx_clear_window(m->mlx, m->win);
    if (!code)
    {
        m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
        m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    }

    if (code < 0)
        fdf_setdefault(m);
    fdf_recalculate(m, m->f);
    fdf_printmap(m);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    mlx_destroy_image(m->mlx, m->img);
}

void    fdf_mlxinit(t_map *m)
{
    m->xmove = 0;
    m->ymove = 0;
    m->on = 1;
    m->xaxis = -50;
    m->yaxis = 20;
    m->zoom = 1;
    m->sl = 0;
    m->bpp = 0;
    m->zmove = 0;
    m->win = NULL;
    m->mlx = NULL;
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf - ysalata");
    fdf_drawwindow(m, 0);
    mlx_mouse_hook(m->win, fdf_onmouse, m);
    mlx_hook(m->win, 2, 5, fdf_onbutton, m);
   // mlx_hook(m->win, 6, 5, fdf_lol, m);
    mlx_loop(m->mlx);
}