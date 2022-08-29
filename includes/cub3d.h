#ifndef CUB3D_H
# define CUB3D_H

#include "mlx_linux/mlx.h"
#include "X11/X.h"
#include "libft/libft.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <fcntl.h>

//check path
//check rgb split sur virgule -> if size return split == 3 check value 0to255.

/********************************************************************/
/*		Errors & Exit Values										*/
/********************************************************************/
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

/*********************************************************************/
/*		Keycodes													 */
/*********************************************************************/

#define W 119
#define A 97
#define S 115
#define D 100
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363

/*********************************************************************/
/*		Config for the player										 */
/*********************************************************************/

#define CUB_SIZE 64
#define WIN_SIZE 1024
#define FOV 66.0
#define ROTATION_UNIT 10
#define MOVEMENT_UNIT 20
#define BASE_DEC "0123456789"

/*********************************************************************/
/*		All mlx image's useful data in one place                     */
/*********************************************************************/

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		bpp;
	int		ll;
	int		endian;
}		t_image;

/*********************************************************************/
/*		All mlx images cub3d uses                                    */
/*********************************************************************/

typedef struct s_images
{
	t_image	est;
	t_image	west;
	t_image	north;
	t_image	south;
	t_image	cub3d;
}		t_images;

/*********************************************************************/
/*		Player Informations Structure								 */
/*********************************************************************/

typedef struct s_player
{
	double			fov;
	double			rot;
	double			mov;
	double			dir;
	t_int_vector	map;
	t_double_vector	pos;
}		t_player;

/*********************************************************************/
/*		Pixel representation										 */
/*********************************************************************/

typedef struct s_color
{
	int				color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	parsed;
}		t_color;

/*********************************************************************/
/*		Color of the Floor and the Ceilling							 */
/*********************************************************************/

typedef struct s_colors
{
	t_color	floor;
	t_color	ceiling;
}		t_colors;

/*********************************************************************/
/*		Wall Informations Structure									 */
/*********************************************************************/

typedef struct s_wall
{
	int				lo;
	int				hi;
	int				height;
	int				column;
	double			dist;
	t_image			*texture;
}		t_wall;

/*********************************************************************/
/*		Map Informations structure									 */
/*********************************************************************/

typedef struct s_map
{
	size_t	nb_line;
	char	**map;
	char	*identifier[6];
}		t_map;

/********************************************************************/
/*		Principal Data Structure									*/
/********************************************************************/

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*filename;
	int			fd;
	t_map		map;
	t_images	images;
	t_colors	colors;
	t_wall		wall;
	t_player	player;
	const char	*my_strerror[ERRORS + 1];

}		t_cub3d;

int		ft_parse(t_cub3d *game);
int		ft_strcmp(char *s1, char *s2);

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