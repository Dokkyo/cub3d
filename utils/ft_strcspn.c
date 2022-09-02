#include "../libft/libft.h"

/*
** Return an index of the first character of 's' which is not in 'rejected'
*/
int	ft_strcspn(const char *s, const char *rejected)
{
	int	len;

	len = 0;
	while (*s && ft_strchr(rejected, *s))
	{
		++s;
		if (*s == 10)
			return (len);
	}
	while (*s && !ft_strchr(rejected, *s))
	{
		++s;
		++len;
	}
	return (len);
}