/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:15:40 by ysalata           #+#    #+#             */
/*   Updated: 2017/11/21 15:56:35 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Force exit function, if error was handled
** Error message on output
*/

int			fdf_error(int type)
{
	type -= 1;
	type == -2 ? exit(1) : 0;
	if (type == 0)
		ft_printf("%s\n", g_e[type]);
	else
		ft_printf(COL_RED"%s\n"COL_EOC, g_e[type]);
	return (0);
}

/*
** Opening input map
** Check 4 empty string ("") or !.fdf in file name
** Calculate number of lines in file in m->y
** Calculate width of the first line in m->x
*/

t_map		*fdf_open(int fd, int gnl, char *name)
{
	t_map	*m;
	char	*s;
	char	**xlen;
	int		l;

	xlen = NULL;
	l = (int)ft_strlen(name);
	(l < 5 || ft_str(name + l - 4, ".fdf")) ? exit(fdf_error(1)) : 0;
	fd <= 0 ? exit(fdf_error(2)) : 0;
	m = (t_map *)malloc(sizeof(t_map));
	m->x = 0;
	m->y = 0;
	while ((gnl = get_next_line(fd, &s)) > 0)
	{
		m->y == 0 ? xlen = ft_strsplit(s, ' ') : 0;
		s[0] ? ++m->y : exit(fdf_error(4));
		ft_strdel(&s);
	}
	gnl < 0 ? exit(fdf_error(3)) : 0;
	if (m->y > 0)
		while (xlen[m->x] != NULL && xlen[m->x][0])
			m->x++;
	return (m);
}

int			main(int ac, char **av)
{
	t_map	*map;
	t_o		**f;

	ac != 2 ? exit(fdf_error(1)) : 0;
	map = fdf_open(open(av[1], O_RDONLY), 0, av[1]);
	if (map->y == 0 || map->x == 0)
		exit(fdf_error(5));
	if (map->y >= 100 || map->x >= 100)
		system("afplay bonus/fdf_epic.mp3 &");
	else
		system("afplay bonus/fdf_easy.mp3 &");
	f = NULL;
	fdf_mapresize(map);
	fdf_parse(open(av[1], O_RDONLY), 0, map);
	return (0);
}
