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

void	skip_digits(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}

void	skip_spaces(char **s)
{
	while (**s == ' ')
		(*s)++;
}
