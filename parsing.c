#include "includes/fdf.h"

long    fdf_endian(const char *s)
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
    t_o buf;

    i = 0;
    while (str[i])
    {
        buf.z = ft_atoi(str);
        buf.z *= str[i] == '-' && ft_isdigit(str[i + 1]) && i++ ? -1 : 1;
        while (str[i] && (ft_isdigit(str[i]) || str[i] != ','))
            i++;
        str[i] && str[i] != ',' ? exit(fdf_error(4)) : 0;
        if (str[i] && str[i] == ',')
        {
            i += (str[i] == '0' && str[i + 1] == 'x') ? 3 : 1;
            buf.c = fdf_endian(str + i);
            while (str[i] && ft_strchr(HEX, str[i]))
                i++;
            str[i] ? 0 : exit(fdf_error(7));
        }
        else
            buf.c = 0;
    }
    return (buf);
}

void    fdf_init(t_map *m, t_o fig[m->y][m->x])
{
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, 1900, 1200, "fdf - ysalata");
    mlx_loop(m->mlx);
}

void    fdf_parse(int fd, t_map *m)
{
    char *s;
    int  y;
    int  x;
    char **str;
    t_o  fig[m->y][m->x];

    y = 0;
    while (get_next_line(fd, &s) > 0)
    {
        x = 0;
        str = ft_strsplit(s, ' ');
        while (str[x])
        {
            if (x < m->x)
            {
                fig[y][x] = fdf_checkstr(str[x]);
                fig[y][x].x = x;
                fig[y][x].y = y;
            }
            x++;
        }
        y != 0 && x < m->x ? exit(fdf_error(6)) : 0;
        y++;
        ft_strdel(&s);
    }
    fdf_init(m, fig);
}