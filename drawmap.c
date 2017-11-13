#include "includes/fdf.h"

/*
 * Drawing new mlx window
 * code == 1 ? redrawing : new draw;
 */
void    fdf_draw(t_map *m, int code)
{
    if (code)
        mlx_destroy_image(m->mlx, m->img);
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);

}