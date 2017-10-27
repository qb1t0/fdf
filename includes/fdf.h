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

typedef struct  s_map{
    int         y;
    int         x;
    int         xmove;
    int         ymove;
    float       zoom;
    void        *img;
    int         bpp;
    int         sl;
    int         endian;
    char        *im;
    void        *mlx;
    void        *win;

}               t_map;

typedef struct  s_o{
    float       x;
    float       y;
    float       z;       //z-coord
    int         c;       //c-color
}               t_o;

void fdf_4all(t_map *m, t_o f[m->y][m->x]);
void fdf_dda(t_o f, t_o e, int x1, int y1, t_map *m);
t_map   *fdf_open(int fd, int gnl, char *name);
int     fdf_error(int type);
void    fdf_parse(int fd, t_map *m);
t_o     fdf_checkstr(char *str);
int    fdf_endian(const char *s);

#endif //FDF_TEST_FDF_H
