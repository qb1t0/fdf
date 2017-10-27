#include "includes/fdf.h"

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
            buf.c = 0xFFFFFF;
    }
    return (buf);
}

int     fdf_onmouse(int mouse, int x, int y, t_map *m)
{
    ft_printf("KEY: %d X:%d Y:%d\n", mouse, x, y);
    if (mouse == 4)
        m->zoom *= 1.1;
    else if (mouse == 5)
        m->zoom /= 1.1;
}

int     fdf_onbutton(int button, t_map *m)
{
    if (button == 124)
        m->xmove += 10;
    else if (button == 123)
        m->xmove -= 10;
    else if (button == 126)
        m->ymove -= 10;
    else if (button == 125)
        m->ymove += 10;
}
void    fdf_init(t_map *m, t_o fig[m->y][m->x])
{
    m->xmove = 0;
    m->ymove = 0;
    m->zoom = 1;
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf - ysalata");
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    fdf_4all(m, fig);
    //m->im[WIDTH / 2 * m->bpp / 8 + m->sl * HEIGHT / 2] = 0xFFFFFF;
    //m->im[WIDTH / 2  * m->bpp / 8 + m->sl * HEIGHT / 2 + 1] = (char)(0xFFFFFF>> 8);
    //m->im[WIDTH / 2  * m->bpp / 8 + m->sl * HEIGHT / 2 + 2] = (char)(0xFFFFFF >> 16);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 100, 100);
    // m->im = mlx_new_image(m->win, 100, 100);
    //mlx_hook(m->win, 17, 1L << 17, (int (*)())fdf_error(-1), m->mlx);
    mlx_hook(m->win, 2, 5, fdf_onbutton, &m);
    mlx_mouse_hook(m->win, fdf_onmouse, &m);
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
                fig[y][x].x = x * 50;
                fig[y][x].y = y * 50;
            }
            x++;
        }
        y != 0 && x < m->x ? exit(fdf_error(6)) : 0;
        y++;
        ft_strdel(&s);
    }
    fdf_init(m, fig);
}