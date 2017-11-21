/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:39:59 by ysalata           #+#    #+#             */
/*   Updated: 2017/11/21 12:51:01 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Setting colors(RGB) for each pixel in 4 bytes of f->im(char *)
*/

void	im_draw(t_map *f, t_o f1, int x, int y)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		f->im[x * f->bpp / 8 + f->sl * y] = (char)f1.c;
		f->im[x * f->bpp / 8 + f->sl * y + 1] = (char)(f1.c >> 8);
		f->im[x * f->bpp / 8 + f->sl * y + 2] = (char)(f1.c >> 16);
	}
}

/*
** Calculating && Initializing delta's for algorithm
*/

void	fdf_delta_init(t_map *f, t_o f1, t_o f2)
{
	f->dx = (int)(f2.xi - f1.xi);
	f->dy = (int)(f2.yi - f1.yi);
	f->incr_x = f->dx > 0 ? 1 : -1;
	f->incr_y = f->dy > 0 ? 1 : -1;
	f->dx = abs(f->dx);
	f->dy = abs(f->dy);
	if (f->dx > f->dy)
	{
		f->incdeltax = f->incr_x;
		f->incdeltay = 0;
		f->dh = f->dx;
		f->de = f->dy;
	}
	else
	{
		f->incdeltax = 0;
		f->incdeltay = f->incr_y;
		f->dh = f->dy;
		f->de = f->dx;
	}
	f->e = f->dh / 2;
}

/*
** Brezenham's algorithm implementation:
*/

void	fdf_brezenhem(t_map *f, t_o f1, t_o f2)
{
	int	k;
	int	x;
	int	y;

	fdf_delta_init(f, f1, f2);
	x = (int)f1.xi;
	y = (int)f1.yi;
	k = -1;
	im_draw(f, f1, x, y);
	while (++k < f->dh)
	{
		f->e -= f->de;
		if (f->e < 0)
		{
			f->e += f->dh;
			x += f->incr_x;
			y += f->incr_y;
		}
		else
		{
			x += f->incdeltax;
			y += f->incdeltay;
		}
		im_draw(f, f1, x, y);
	}
}

/*
** Pixel list array traversal
*/

void	fdf_printmap(t_map *m)
{
	int i;
	int	j;

	i = -1;
	while (++i < m->y)
	{
		j = -1;
		while (++j < m->x)
		{
			if (j != m->x - 1)
				fdf_brezenhem(m, m->f[i][j], m->f[i][j + 1]);
			if (i != m->y - 1)
				fdf_brezenhem(m, m->f[i][j], m->f[i + 1][j]);
		}
	}
}
