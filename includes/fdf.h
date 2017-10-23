#ifndef FDF_TEST_FDF_H
# define FDF_TEST_FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# define HEX "01234567890abcdef"

static char *g_e[] = {
        "Usage: ./fdf [-c] <mapname.fdf>",
        "Can't open() file",
        "Can't read() file",
        "Invalid coordinate",
        "Empty file",
        "Invalid number of coordinates in string",
        "Invalid color value",
};

typedef struct s_map{
    int        y;
    int        x;
    void       *mlx;
    void       *win;
}              t_map;

typedef struct s_o{
    int        x;
    int        y;
    int        z;       //z-coord
    long       c;       //c-color
}              t_o;

t_map   *fdf_open(int fd, int gnl, char *name);
int     fdf_error(int type);
void    fdf_parse(int fd, t_map *m);
t_o     fdf_checkstr(char *str);
long    fdf_endian(const char *s);

#endif //FDF_TEST_FDF_H
