#ifndef FDF_TEST_FDF_H
# define FDF_TEST_FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
//# include <mlx.h>
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
#include <math.h>

# define HEX "01234567890abcdef"
# define WIDTH 1900
# define HEIGHT 1200
//x - value, t - type : t ? HEIGHT : WEIGHT;
# define C(x, t) ((t) ? (WIDTH/(x)) : (HEIGHT/(x)))


static char *g_e[] = {
        "Usage: ./fdf [-c] <mapname.fdf>",
        "Can't open() file",
        "Can't read() file",
        "Invalid coordinate",
        "Empty file",
        "Invalid number of coordinates in string",
        "Invalid color value",
};

typedef struct  s_o{
    float       x;
    float       y;
    float       z;       //z-coord
    int         c;       //c-color
    double      v;
    float       xi;
    float       yi;
    double      vi;
    float       zi;
    int         ci;
}               t_o;

typedef struct  s_map{
    int         y;
    int         x;
    int         a;
    int         xmove;
    int         ymove;
    int         zmove;
    float       zoom;
    void        *img;
    int         bpp;
    int         sl;
    int         endian;
    char        *im;
    void        *mlx;
    void        *win;
    float       centerx;
    float       centery;
    int			dx;
    int			dy;
    int			dh;
    int			de;
    int         wx;
    int			e;
    int         on;
    int			incdeltax;
    int			incdeltay;
    int			incr_x;
    int			incr_y;
    int         xaxis;
    int         yaxis;
    int         zaxis;
    t_o             **f;
}               t_map;

void    fdf_printmap(t_map *m);
void    im_draw(t_map *f, t_o f1, int x, int y);
void	fdf_brezenhem(t_map *f, t_o f1, t_o f2);
void	fdf_delta_init(t_map *f, t_o f1, t_o f2);

void    fdf_mlxinit(t_map *m);
int     fdf_onmouse(int mouse,int x, int y, t_map *m);
int     fdf_onbutton(int button, t_map *m);
void    fdf_drawwindow(t_map *m, int code);

void    fdf_recalculate(t_map *m, t_o **f);
void    fdf_rotation(float *x, float *y, float *z, t_map *m);


int     fdf_endian(const char *s);
t_o     fdf_checkstr(char *str, int i);
void    fdf_mapresize(t_o **f, t_map *m);
void    fdf_parse(int fd, t_map *m);


int     fdf_error(int type);
int		ft_str(const char *s1, const char *s2);
t_map   *fdf_open(int fd, int gnl, char *name);

#endif //FDF_TEST_FDF_H
