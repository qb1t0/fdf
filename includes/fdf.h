#ifndef FDF_TEST_FDF_H
# define FDF_TEST_FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../libft/ft_printf/ft_printf.h"

static char *g_e[] = {
        "Usage: ./fdf [-c] <mapname.fdf>",
        "Can't open() file",
        "Can't read() file",
        "Invalid map"
};

typedef struct s_map{
    int        size;
}              t_map;
#endif //FDF_TEST_FDF_H
