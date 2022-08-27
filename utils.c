#include "cub3d.h"

bool	is_valid_character(char c)
{
	if (c == '0' || c == '1')
		return (true);
	return (false);
}

int		is_empty(char *s)
{
	size_t		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] > 32)
				return (0);
			++i;
		}
	}
	return (1);
}