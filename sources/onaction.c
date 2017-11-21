/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onaction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:15:49 by ysalata           #+#    #+#             */
/*   Updated: 2017/11/21 12:36:46 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_setdefault(t_map *m)
{
	m->xmove = 0;
	m->ymove = 0;
	m->zmove = 0;
	m->a = 20;
	m->zoom = 1;
	m->xaxis = -50;
	m->yaxis = 20;
}

int		fdf_onmouse(int mouse, int x, int y, t_map *m)
{
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
	return (x + y);
}

int		fdf_onbutton(int button, t_map *m)
{
	mlx_do_sync(m->mlx);
	mlx_clear_window(m->mlx, m->win);
	m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
	m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
	if (button == 124)
		m->xmove += 10;
	else if (button == 123)
		m->xmove -= 10;
	else if (button == 126)
		m->ymove -= 10;
	else if (button == 125)
		m->ymove += 10;
	else if (button == 69)
		m->zoom *= 1.1;
	else if (button == 78)
		m->zoom /= 1.1;
	else if (button == 116)
		m->zmove += 10;
	else if (button == 121)
		m->zmove -= 10;
	else if (button == 53)
		exit(system("killall afplay"));
	(button == 49) ? fdf_drawwindow(m, -1) : fdf_drawwindow(m, 1);
	return (0);
}

/*
** Drawing new mlx window
** code == 1 ? redrawing : new draw;
*/

void	fdf_drawwindow(t_map *m, int code)
{
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

void	fdf_mlxinit(t_map *m)
{
	m->xmove = 0;
	m->ymove = 0;
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
	mlx_loop(m->mlx);
}
