#ifndef CUB3D_H
# define CUB3D_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

//check path
//check rgb split sur virgule -> if size return split == 3 check value 0to255.

typedef struct s_map
{
	size_t	nb_line;
	char	**map;
	char	*identifier[6];
}t_map;

typedef struct s_cub3d
{
	t_map	map;
	char	*filename;
	int		fd;

}t_cub3d;

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