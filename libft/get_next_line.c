#include "libft.h"

int	lookfor_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	refresh_buf(char *b)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = ft_strlen_nl(b);
	if (b[j] == '\n')
		++j;
	i = 0;
	while (b[i] != '\0')
		b[i++] = b[j++];
	while (b[i] != '\0')
		b[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			rbytes;
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (NULL);
	rbytes = 1;
	line = ft_strdup_nl("");
	line = ft_strjoin_nl(line, buf);
	while (rbytes > 0 && !lookfor_nl(buf))
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes)
		{
			buf[rbytes] = 0;
			line = ft_strjoin_nl(line, buf);
		}
		else if (rbytes == -1)
			return (NULL);
		else if (rbytes == 0 && buf[0] != 0)
		{
			refresh_buf(buf);
			return (line);
		}
		else
		{
			free(line);
			line = NULL;
			return (line);
		}
	}
	refresh_buf(buf);
	return (line);
}
