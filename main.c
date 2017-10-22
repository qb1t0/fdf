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

int     fdf_checkstr(int x, int minus, char *str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        minus = str[i] == '-' && i++ ? 1 : 0;
        while(ft_isdigit(str[i]) || str[i][j] != ',')
            j++;
        if (str[i][j] && str[i][j] == ',' ? j++ : exit(fdf_error(4)))
        {
            j += str[i][j] == '0' && str[i][j + 1] == 'x' ? 2 : 0;

        }
        ft_isaldigit(str[i]) ? i++ : exit(fdf_error(4));
    }

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
        while (s[y])
        {

            y++;
        }
        x++;
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