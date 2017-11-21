/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:16:05 by ysalata           #+#    #+#             */
/*   Updated: 2017/11/21 15:56:06 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_str(const char *s1, const char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	return (0);
}

int			fdf_endian(const char *s)
{
	int		buf;
	int		i;

	buf = 0;
	i = -1;
	while (s[++i])
	{
		buf <<= 4;
		if (s[i] < 58)
			buf |= s[i] - 48;
		else if (s[i] < 91)
			buf |= s[i] - 55;
		else
			buf |= s[i] - 87;
	}
	return (buf);
}

t_o			fdf_checkstr(char *str, int i)
{
	t_o		buf;

	while (str[i])
	{
		buf.z = ft_atoi(str);
		buf.z *= str[i] == '-' && ft_isdigit(str[i + 1]) && i++ ? -1 : 1;
		buf.z *= 4;
		buf.zi = buf.z;
		while (str[i] && (ft_isdigit(str[i]) || str[i] != ','))
			i++;
		str[i] && str[i] != ',' ? exit(fdf_error(4)) : i++;
		if (str[i - 1] && str[i - 1] == ',')
		{
			i += (str[i] == '0' && str[i + 1] == 'x') ? 2 : 0;
			buf.c = fdf_endian(str + i);
			while (str[i] && ft_strchr(HEX, str[i]))
				i++;
			str[i] ? exit(fdf_error(7)) : 0;
		}
		else
			buf.c = 0xFFFFFF;
	}
	return (buf);
}

/*
** Splits string with z-values from .fdf
** Adding pixel values in pixel array of lists
** v - corner, x-axis, y-axis,
*/

void		fdf_parse(int fd, int y, t_map *m)
{
	char	*s;
	int		x;
	char	**str;

	while (get_next_line(fd, &s) > 0)
	{
		x = 0;
		str = ft_strsplit(s, ' ');
		m->f[y] = (t_o *)malloc(sizeof(t_o) * m->x);
		while (str[x] && x < m->x)
		{
			m->f[y][x] = fdf_checkstr(str[x], 0);
			m->f[y][x].c != 0xFFFFFF ? m->a = 1 : 0;
			m->f[y][x].x = (x * m->wx) + m->centerx;
			m->f[y][x].y = (y * m->wx) + m->centery;
			m->f[y][x].xi = m->f[y][x].x;
			m->f[y][x].yi = m->f[y][x].y;
			ft_strdel(&str[x]);
			x++;
		}
		y++ != 0 && x < m->x ? exit(fdf_error(6)) : 0;
		ft_strdel(&s) ? free(str) : 0;
	}
	fdf_mlxinit(m);
}

void		fdf_mapresize(t_map *m)
{
	m->f = (t_o **)malloc(sizeof(t_o *) * m->y);
	m->a = 0;
	m->wx = WIDTH / (m->x * 1.5);
	m->centerx = WIDTH / 2 - m->x / 2 * m->wx;
	m->centery = HEIGHT / 2 - m->y / 2 * m->wx;
}
