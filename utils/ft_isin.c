#include "../libft/libft.h"
#include <stdbool.h>

/*
** Return true only if s contain accepted chars
*/
bool	ft_isin(const char *s, const char *accepted)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(accepted, s[i]))
			i++;
		else
			return (false);
	}
	return (true);
}