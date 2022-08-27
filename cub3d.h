#ifndef CUB3D_H
# define CUB3D_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdbool.h>

// Ouverture du fichier (sauf si lien symbolique et repertoire)
// Recuperer les elements textures et couleurs
// Detecter le debut de la map
// check path
// check rgb split sur virgule -> if size return split == 3 check value 0to255.

typedef struct s_textures
{
	int		img_width;
	int		img_height;
	void	*textures[4];
}t_textures;

typedef struct s_map
{
	size_t	nb_line;
	char	**map;
}t_map;

typedef struct s_cub3d
{
	char		*filename;
	char		*file_line;
	int			fd;
	t_map		map;
	t_textures	tex;
	void		*mlx;
}t_cub3d;

bool	is_parsed(t_cub3d *game);
int		wrong_file(t_cub3d *game);
bool	is_valid_character(char c);
int		is_empty(char *s);
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
*
*/