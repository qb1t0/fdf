#ifndef FDF_TEST_FDF_H
# define FDF_TEST_FDF_H

# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
# include <mlx.h>
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
#include <math.h>

# define HEX "01234567890abcdef"
# define WIDTH 1900
# define HEIGHT 1200


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
    int         centerx;
    int         centery;
    int				deltax;
    int				deltay;
    int				incdeltax;
    int				incdeltay;
    int				h_delta;
    int				err;
    int				delta_err;
    int				incr_x;
    int				incr_y;
    t_o             **f;

}               t_map;

void    fdf_redraw(t_map *m);
void fdf_4all(t_map *m);
void    fdf_recalc(t_map *m, t_o **f);
void fdf_dda(t_o f, t_o e, int x1, int y1, t_map *m);
t_map   *fdf_open(int fd, int gnl, char *name);
int     fdf_error(int type);
void    fdf_parse(int fd, t_map *m);
t_o     fdf_checkstr(char *str);
int    fdf_endian(const char *s);

#endif //FDF_TEST_FDF_H
