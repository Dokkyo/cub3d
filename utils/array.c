#include "../includes/cub3d.h"

int	length_2d_array(char **a)
{
	int	i;

	i = -1;
	if (a)
	{
		i = 0;
		while (a[i])
			i++;
	}
	return (i);
}

void	free_2d_array(char **a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
}