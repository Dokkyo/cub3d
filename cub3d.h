#ifndef CUB3D_H
#define CUB3D_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_map
{
    size_t  nb_line;
    char    **map;
    char    *identifier[6];

}t_map;

typedef struct s_cub3d
{
    t_map   map;
    char    *filename;
    int     fd;

}t_cub3d;

int    ft_parse(t_cub3d *game);
int	ft_strcmp(char *s1, char *s2);

#endif