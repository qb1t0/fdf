/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculating.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:16:19 by ysalata           #+#    #+#             */
/*   Updated: 2017/11/21 13:01:23 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Rotating each coordinate axis on corner (xaxis/yaxis)
*/

void		fdf_rotation(float *x, float *y, float *z, t_map *m)
{
	float	xs;
	float	xc;
	float	ys;
	float	yc;

	xs = (float)sin(m->xaxis * M_PI / 180);
	xc = (float)cos(m->xaxis * M_PI / 180);
	ys = (float)sin(m->yaxis * M_PI / 180);
	yc = (float)cos(m->yaxis * M_PI / 180);
	*y = ((*y - m->f[m->y / 2][m->x / 2].y) * xc) + (*z * xs) + \
		m->f[m->y / 2][m->x / 2].y;
	*x = ((*x - m->f[m->y / 2][m->x / 2].x) * yc) + (*z * ys) + \
		m->f[m->y / 2][m->x / 2].x;
	*z = (-1 * (*x) * ys) + (*z * yc);
}

void		fdf_recalculate(t_map *m, t_o **f)
{
	int		i;
	int		j;

	i = -1;
	m->centerx = m->f[m->y / 2][m->x / 2].x;
	m->centery = m->f[m->y / 2][m->x / 2].y;
	while (++i < m->y && (j = -1))
		while (++j < m->x)
		{
			if (f[i][j].z)
			{
				f[i][j].zi = (m->f[i][j].z + m->zmove) * m->zoom;
				if (!m->a)
					f[i][j].c -= 500;
			}
			else
				f[i][j].zi = (m->f[i][j].z) * m->zoom;
			f[i][j].xi = ((f[i][j].x - m->centerx + m->xmove) * m->zoom) \
				+ m->centerx;
			f[i][j].yi = ((f[i][j].y - m->centery + m->ymove) * m->zoom) \
				+ m->centery;
			fdf_rotation(&f[i][j].xi, &f[i][j].yi, &f[i][j].zi, m);
		}
}
