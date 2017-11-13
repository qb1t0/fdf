#include "includes/fdf.h"

//x - value, t - type : t ? HEIGHT : WEIGHT;
# define C(x, t) ((t) ? (HEIGHT/2 - (x)) : (WIDTH/2 - (x)))

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
//    if (mouse == 4)
//        m->zoom *= 1.1;
//    else if (mouse == 5)
//        m->zoom /= 1.1;
    mlx_destroy_image(m->mlx, m->img);
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    fdf_recalc(m, m->f);
    fdf_4all(m);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    return (0);
}

int     fdf_onbutton(int button, t_map *m)
{
    if (button == 69)
        m->zoom *= 1.1;
    else if (button == 78)
        m->zoom /= 1.1;
    else if (button == 124)
        m->xmove += 10;
    else if (button == 123)
        m->xmove -= 10;
    else if (button == 126)
        m->ymove -= 10;
    else if (button == 125)
        m->ymove += 10;
    else if (button == 91)
        m->a += 5;
    else if (button == 84)
        m->a -= 5;
    else if (button == 53)
        exit(0);
    fdf_draw(m, 1);
    mlx_destroy_image(m->mlx, m->img);
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    fdf_recalc(m, m->f);
    fdf_4all(m);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
}
void    fdf_init(t_map *m)
{
    m->xmove = 0;
    m->ymove = 0;
    m->zoom = 1;
    m->mlx = mlx_init();
    m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf - ysalata");
    m->img = mlx_new_image(m->win, WIDTH, HEIGHT);
    m->im = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
    m->a = 50;
    //m->im[WIDTH / 2 * m->bpp / 8 + m->sl * HEIGHT / 2] = 0xFFFFFF;
    //m->im[WIDTH / 2  * m->bpp / 8 + m->sl * HEIGHT / 2 + 1] = (char)(0xFFFFFF>> 8);
    //m->im[WIDTH / 2  * m->bpp / 8 + m->sl * HEIGHT / 2 + 2] = (char)(0xFFFFFF >> 16);
    // m->im = mlx_new_image(m->win, 100, 100);
    //mlx_hook(m->win, 17, 1L << 17, (int (*)())fdf_error(-1), m->mlx);
    fdf_4all(m);
    mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
    mlx_hook(m->win, 2, 5, fdf_onbutton, m);
    //mlx_mouse_hook(m->win, fdf_onmouse, m);
    mlx_loop(m->mlx);
}


void    fdf_parse(int fd, t_map *m)
{
    char *s;
    int  y;
    int  x;
    //int  centerx;
    //int  centery;
    char **str;
    t_o  **f;

    f = (t_o **)malloc(sizeof(t_o *) * m->y);
    y = 0;
    m->centerx = C(m->x, 0) / 2;
    m->centery = C(m->y, 1) / 2;
    while (get_next_line(fd, &s) > 0)
    {
        x = 0;
        str = ft_strsplit(s, ' ');
        f[y] = (t_o *)malloc(sizeof(t_o) * m->x);
        while (str[x] && x < m->x)
        {
            f[y][x] = fdf_checkstr(str[x]);
            f[y][x].v = 0.01;
            f[y][x].x = (x * 50) + m->centerx;
            f[y][x].y = (y * 50) + m->centery;
            f[y][x].xi = f[y][x].x;
            f[y][x].yi = f[y][x].y;
            f[y][x].vi = f[y][x].v;
            x++;
        }
        y != 0 && x < m->x ? exit(fdf_error(6)) : 0;
        y++;
        ft_strdel(&s);
    }
    m->f = f;
    fdf_init(m);
}