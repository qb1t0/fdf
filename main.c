#include "includes/fdf.h
#include <stdio.h>
#include <fcntl.h>

int fdf_error(int type)
{
    type -= 1;
    if (type == 0)
        ft_printf("%s", g_e[type]);
    else
        ft_printf(COL_RED"%s"COL_EOC, g_e[type]);
    return (0);
}

int     fdf_checkstr(char *s)
{
    int i;

    !s[i] ?
    while(s[i])

}

t_map   *fdf_parse(int fd, int gnl)
{
    t_map *m;
    char *s;

    fd <= 0 ? exit(fdf_error(2)) : 0;
    m = (t_map *)malloc(sizeof(t_map));
    m->size = 0;
    while ((gnl = get_next_line(fd, &s)) > 0)
    {
        s[0] ? fdf_checkstr(s) : exit(fdf_error(3));
        ++m->size;
    }
    gnl < 0 ? exit(fdf_error(3)) : 0;
}

int main(int ac, char **av)
{
    t_map *map;

    ac != 2 ? exit(fdf_error(1)) : fdf_parse(open(av[1], O_RDONLY), 0);
    printf("Hello, World!\n");
    return 0;
}