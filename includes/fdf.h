#ifndef FDF_TEST_FDF_H
# define FDF_TEST_FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../libft/ft_printf/ft_printf.h"
# define HEX "01234567890abcdef"

static char *g_e[] = {
        "Usage: ./fdf [-c] <mapname.fdf>",
        "Can't open() file",
        "Can't read() file",
        "Invalid coordinate",
        "Empty file",
        ""
};

typedef struct s_map{
    int        size;
    int        width;
}              t_map;

typedef struct s_o{
    int        z;       //z-coord
    long       c;       //c-color
}              t_o;
#endif //FDF_TEST_FDF_H
