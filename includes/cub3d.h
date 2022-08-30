#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx_linux/mlx.h"
#include "X11/X.h"
#include "../libft/libft.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <fcntl.h>

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
#define W 119
#define A 97
#define S 115
#define D 100
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363

/****************************************************/
/*		Config for the player						*/
/****************************************************/
#define CUB_SIZE 64
#define WIN_SIZE 1024
#define FOV 66.0
#define ROTATION_UNIT 10
#define MOVEMENT_UNIT 20
#define BASE_DEC "0123456789"

/****************************************************/
/*		All mlx image's useful data in one place	*/
/****************************************************/
typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp;
	int		ll;
	int		endian;
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

// /****************************************************/
// /*		Map Informations structure					*/
// /****************************************************/
// typedef struct s_map
// {
// 	size_t	nb_line;
// 	char	*identifier[6];
// }		t_map;

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
	// t_map		map;
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

//	check_map.c
void	check_map(t_cub3d game/*, autre si besoin*/);

//	get_identifiers.c
void	get_identifiers(t_cub3d *game, char *line);

//	get_map.c
void	get_map(t_cub3d game, int fd, char **line);

//	parse.c
void	parse(t_cub3d *game, char *filename);

/****************************************/
/*				utils					*/
/****************************************/

// 	array.c
int		length_2d_array(char **a);
void	free_2d_array(char **a);
void	skip_digits(char **s);
void	skip_spaces(char **s);

// 	cub3d_exit.c
void	exit_cub3d(t_cub3d *game, int my_errno);

// 	cub3d_init.c
void	init_cub3d(t_cub3d *game);

// 	ft_strcmp.c
int		ft_strcmp(char *s1, char *s2);

// 	ft_strnspn.c
int		ft_strcspn(const char *s, const char *rejected);

//	mlx.c
void	get_mlx_instance(t_cub3d *game);
void	get_mlx_window(t_cub3d *game);
void	get_mlx_image(t_cub3d *game);

//	pixel.c
void	pixel_to_image(t_image *image, int x, int y, int color);
int		get_image_pixel_color(t_image *image, int col, int row);

/****************************************/
/*				raycasting				*/
/****************************************/

//	graphics_effects.c
void	textured_column_to_image(t_cub3d *game);

//	hooks.c
void	define_hooks(t_cub3d *game);

//	move.c
void	move(t_cub3d *game, double dir);

//	raycasting.c
void	dda(t_cub3d *game);
void	raycasting(t_cub3d *game);

//	rotate.c
void	rotate_player(t_player *player, double angle);

// int		ft_parse(t_cub3d *game);
// int		ft_strcmp(char *s1, char *s2);

#endif

/*
*
*	Lors du parsing de la map :
*	- Creer un int (compteur)
*	- Pour le remplir, il suffirait de checket grace a un tableau de chaine de caractere (char**) qui contiendrait chaque identifieur.
*		Lors du scan du fichier, des qu'on rencontre un identifieur, ajouter +1 au compteur.
*		Save cette ligne pour checker son format et la validite par la suite.
*
*	Quand le compteur arrive a 6, on n'est cense rencontrer que des isspace (ou des /n) ou des 1/0 (debut de map).
*
*	Si l'on rencontre tout autre caractere (excepte isspace) avant un 1/0 : map invalide.
*	Lors de la rencontre d'un 1 ou d'un 0, la map commence.
*		Normalement, La premiere et deniere ligne sont seulement des 1 (pour une map ferme).
*		Le premier et dernier octet de chaque ligne contient soit un isspace soit un 1.
*
*/