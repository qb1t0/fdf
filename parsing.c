#include "includes/fdf.h"

int		ft_str(const char *s1, const char *s2)
{
    while (*s1 || *s2)
        if (*s1++ != *s2++)
            return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
    return (0);
}

int    fdf_endian(const char *s)
{
    int key = 0;
    int buf = 0;
    int i = 0;

    while(s[i])
    {
        buf = s[i];
        buf <<= i * 4;
        key |= buf;
        i++;
    }
    return (key);
}

t_o     fdf_checkstr(char *str, int i)
{
    t_o buf;

    while (str[i])
    {
        buf.z = ft_atoi(str);
        buf.z *= str[i] == '-' && ft_isdigit(str[i + 1]) && i++ ? -1 : 1;
        buf.zi = buf.z;
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
            buf.c = 0xFFFFFF;
    }
    return (buf);
}

/*
** Splits string with z-values from .fdf
** Adding pixel values in pixel array of lists
** v - corner, x-axis, y-axis,
*/

void    fdf_parse(int fd, t_map *m)
{
    char *s;
    int  y;
    int  x;
    char **str;

    y = 0;
    while (get_next_line(fd, &s) > 0)
    {
        x = 0;
        str = ft_strsplit(s, ' ');
        m->f[y] = (t_o *)malloc(sizeof(t_o) * m->x);
        while (str[x] && x < m->x)
        {
            m->f[y][x] = fdf_checkstr(str[x], 0);
            m->f[y][x].v = 0.01;
            m->f[y][x].x = (x * m->wx) + m->centerx;
            m->f[y][x].y = (y * m->wx) + m->centery;
            m->f[y][x].xi = m->f[y][x].x;
            m->f[y][x].yi = m->f[y][x].y;
            x++;
        }
        y++ != 0 && x < m->x ? exit(fdf_error(6)) : 0;
        ft_strdel(&s);
    }
    fdf_mlxinit(m);
}

void    fdf_mapresize(t_o **f, t_map *m)
{
    m->f = (t_o **)malloc(sizeof(t_o *) * m->y);
    m->wx = WIDTH/(m->x * 2);
    printf("X: % d\n", m->x);
    printf("Y: % d\n", m->y);
    m->centerx = WIDTH/2 - m->x/2 * m->wx;
    m->centery = HEIGHT/2 - m->y/2 * m->wx;
}