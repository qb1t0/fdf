#include "includes/fdf.h"


int fdf_error(int type)
{
    type -= 1;
    type == -2 ? exit(1) : 0;
    if (type == 0)
        ft_printf("%s\n", g_e[type]);
    else
        ft_printf(COL_RED"%s\n"COL_EOC, g_e[type]);
    return (0);
}

int		ft_str(const char *s1, const char *s2)
{
    while (*s1 || *s2)
        if (*s1++ != *s2++)
            return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
    return (0);
}

t_map   *fdf_open(int fd, int gnl, char *name)
{
    t_map *m;
    char *s;
    char **xlen;
    int  l;

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
    }
    gnl < 0 ? exit(fdf_error(3)) : 0;
    if (m->y > 0)
        while (xlen[m->x] != NULL && xlen[m->x][0])
            m->x++;
    return (m);
}

int main(int ac, char **av)
{
    t_map *map;

    ac != 2 ? exit(fdf_error(1)) : 0;
    map = fdf_open(open(av[1], O_RDONLY), 0, av[1]);
    map->y == 0 || map->x == 0? \
        exit(fdf_error(5)) : fdf_parse(open(av[1], O_RDONLY), map);
    printf("Hello, World!\n");
    return 0;
}