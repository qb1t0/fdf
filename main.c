#include "includes/fdf.h"
#include <stdio.h>
#include <fcntl.h>

int fdf_error(int type)
{
    type -= 1;
    if (type == 0)
        ft_printf("%s\n", g_e[type]);
    else
        ft_printf(COL_RED"%s\n"COL_EOC, g_e[type]);
    return (0);
}

long    fdf_endian(char *s)
{
    long key = 0;
    long buf = 0;
    int i = 0;

    while(s[i])
    {
        buf = s[i];
        buf <<= i * 8;
        key |= buf;
        i++;
    }
    return (key);
}

t_o     fdf_checkstr(char *str)
{
    int i;
    t_o *buf;

    i = 0;
    buf = (t_o *)malloc(sizeof(t_o));
    while (str[i])
    {
        buf->z = ft_atoi(str);
        buf->z *= str[i] == '-' && ft_isdigit(str[i + 1]) && i++ ? -1 : 1;
        while(ft_isdigit(str[i]) || str[i] != ',')
            i++;
        if (str[i] && str[i] == ',' ? i++ : exit(fdf_error(4)))
        {
            i += (str[i] == '0' && str[i + 1] == 'x') ? 2 : 0;
            buf->c = fdf_endian(str + i);
        }
        else
            buf->c = 0;
    }
    return (*buf);
}

void    fdf_parse(int fd, t_map *m, t_o ***t)
{
    char *s;
    int  y;
    int  x;
    char **str;
    t_o  **fig;

    fig = *t;
    x = 0;
    y = 0;
    fig = (t_o **)malloc(sizeof(t_o *) * m->size);
    while (get_next_line(fd, &s) > 0)
    {
        str = ft_strsplit(s, ' ');
        while (str[y] && )
        {
            fig[x][y] = fdf_checkstr(str[y]);
            y++;
        }
        x == 0 ? m->width = y - 1 : 0;
        x++;
        ft_strdel(&s);
    }
}

t_map   *fdf_open(int fd, int gnl, char *name)
{
    t_map *m;
    char *s;
    int  l;

    l = (int)ft_strlen(name);
    (l < 5 || ft_strcmp(name + l - 4, ".fdf")) ? exit(fdf_error(1)) : 0;
    fd <= 0 ? exit(fdf_error(2)) : m = (t_map *)malloc(sizeof(t_map));
    m->size = 0;
    m->width = 10000;
    while ((gnl = get_next_line(fd, &s)) > 0)
        s[0] ? ++m->size : exit(fdf_error(4));
    gnl < 0 ? exit(fdf_error(3)) : 0;
}

int main(int ac, char **av)
{
    t_map *map;
    t_o   **t;

    ac != 2 ? \
     exit(fdf_error(1)) : map = fdf_open(open(av[1], O_RDONLY), 0, av[0]);
    map->size == 0 ? \
        exit(fdf_error(5)) : fdf_parse(open(av[1], O_RDONLY), map, &t);
    printf("Hello, World!\n");
    return 0;
}