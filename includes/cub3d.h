/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:33:59 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/07 14:33:59 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "X11/X.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

//check path
//check rgb split sur virgule -> if size return split == 3 check value 0to255.

/****************************************************/
/*		Errors & Exit Values						*/
/****************************************************/
typedef enum e_errno
{
	ZERO,
	MAP_MALLOC,
	MAP_ENOENT,
	MAP_EACCES,
	MAP_EISDIR,
	MAP_OPEN,
	MAP_READ,
	MAP_FT_SPLIT,
	MAP_FT_STRNCAT,
	MAP_EXTENSION,
	MAP_NOT_CLOSE,
	MAP_DUPLICATE,
	MAP_UNDEFINED,
	MAP_LINE_FORMAT,
	MAP_NO_CARDINAL,
	MAP_MULT_CARDINALS,
	IMG_ADDR,
	MLX_INIT,
	MLX_WINDOW,
	MLX_NEW_IMAGE,
	XPM_SIZE,
	XPM_FORMAT,
	XPM_DUPLICATE,
	XPM_UNAVAILABLE,
	XPM_MISSING,
	COLOR_FORMAT,
	COLOR_MALLOC,
	COLOR_RANGE,
	COLOR_MISSING,
	COLOR_DUPLICATE,
	MAIN_ARG,
	ERRORS
}		t_errno;

/****************************************************/
/*		Keycodes									*/
/****************************************************/
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363

/****************************************************/
/*		Config for the player						*/
/****************************************************/
# define CUB_SIZE 64
# define WIN_SIZE 1024
# define FOV 66.0
# define ROTATION_UNIT 10
# define MOVEMENT_UNIT 20
# define BASE_DEC "0123456789"
# define BASE_DEC_SPACE "0123456789\t\n\r\v\f "

/****************************************************/
/*		All mlx image's useful data in one place	*/
/****************************************************/
typedef struct s_image
{
	void			*img;
	int				*addr;
	int				bpp;
	int				ll;
	int				endian;
}		t_image;

/****************************************************/
/*		All mlx images cub3d uses					*/
/****************************************************/
typedef struct s_images
{
	t_image	est;
	t_image	west;
	t_image	north;
	t_image	south;
	t_image	cub3d;
}		t_images;

/****************************************************/
/*		2D vectors									*/
/****************************************************/
typedef struct s_int_vector
{
	int	x;
	int	y;
}		t_int_vector;

typedef struct s_double_vector
{
	double	x;
	double	y;
}			t_double_vector;

/****************************************************/
/*		Player Informations Structure				*/
/****************************************************/
typedef struct s_player
{
	double			fov;
	double			rot;
	double			mov;
	double			dir;
	t_int_vector	map;
	t_double_vector	pos;
}		t_player;

/****************************************************/
/*		Pixel representation						*/
/****************************************************/
typedef struct s_color
{
	int				color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	parsed;
}		t_color;

/****************************************************/
/*		Color of the Floor and the Ceilling			*/
/****************************************************/
typedef struct s_colors
{
	t_color	floor;
	t_color	ceiling;
}		t_colors;

/****************************************************/
/*		Ray											*/
/****************************************************/

typedef struct s_ray
{
	int				column;
	double			rot;
	double			angle;
	t_int_vector	map;
	t_int_vector	step;
	t_double_vector	dist;
	t_double_vector	delta;
}		t_ray;

/****************************************************/
/*		Wall Informations Structure					*/
/****************************************************/
typedef struct s_wall
{
	int				lo;
	int				hi;
	int				height;
	int				column;
	double			dist;
	t_image			*texture;
}		t_wall;

/********************************************************************/
/*		Principal Data Structure									*/
/********************************************************************/
typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*filename;
	int			fd;
	char		**map;
	t_images	images;
	t_colors	colors;
	t_wall		wall;
	t_ray		ray;
	t_player	player;
	const char	*my_strerror[ERRORS + 1];

}		t_cub3d;

/*	Ajoutez les protos de cette maniere :
**
**	*************************************
**	*		Nom dossier					*
**	*************************************
**	\n
**	*		Nom fichier					*
**	protos du fichier (un par ligne)
**	\n
**	*		Nom fichier					*
**	protos du fichier (un par ligne)
*/

/****************************************/
/*				parsing					*/
/****************************************/


//	check_identifiers.c
bool			check_color_digits(char *tmp);
bool			check_color_range(char *tmp);

//	check_map.c
void			check_map(t_cub3d *game);
void			get_player_game(t_player *player, int x, int y, char c);

//	get_identifiers.c
void			get_identifiers(t_cub3d *game, char *line);

//	get_map.c
void			get_map(t_cub3d *game, int *fd, int map_start);

//	parse.c
int				open_map(t_cub3d *game, char *filename);
void			parse(t_cub3d *game, char *filename);

//	utils_parsing.c
void			check_get_mlx_and_raytrace(t_cub3d *game, int *fd);

/****************************************/
/*				utils					*/
/****************************************/

// 	array.c
int				length_2d_array(char **a);
void			free_2d_array(char **a);
void			skip_digits(char **s);
void			skip_spaces(char **s);

//	check_space.c
void			check_space(t_cub3d *game, char **map, int row, int col);

// 	cub3d_exit.c
void			exit_cub3d(t_cub3d *game, int my_errno);

// 	cub3d_init.c
void			init_cub3d(t_cub3d *game, char *filename);

// 	ft_isin.c
bool			ft_isin(const char *s, const char *accepted);

// 	ft_strcmp.c
int				ft_strcmp(char *s1, char *s2);

// 	ft_strnspn.c
int				ft_strcspn(const char *s, const char *rejected);
int				ft_strcspn2(const char *s, const char *rejected);

//	mlx.c
void			get_mlx_instance(t_cub3d *game);
void			get_mlx_window(t_cub3d *game);
void			get_mlx_image(t_cub3d *game);

//	pixel.c
void			pixel_to_image(t_image *image, int x, int y, int color);
int				get_image_pixel_color(t_image *image, int col, int row);

/****************************************/
/*				raycasting				*/
/****************************************/

//	graphics_effects.c
void			textured_column_to_image(t_cub3d *game);

//	hooks.c
void			define_hooks(t_cub3d *game);

//	move.c
void			move(t_cub3d *game, double dir);

//	raycasting.c
t_int_vector	get_step(double ray);
void			dda(t_cub3d *game);
void			raycasting(t_cub3d *game);

//	rotate.c
double			rotate(double ray, double angle);
void			rotate_player(t_player *player, double angle);

// int				ft_parse(t_cub3d *game);
// int				ft_strcmp(char *s1, char *s2);

#endif
