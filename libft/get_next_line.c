/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:59:28 by bifrah            #+#    #+#             */
/*   Updated: 2022/09/09 12:00:21 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*win_line_shameless(char *buf, char **line, int *fd)
{
	int	rbytes;

	rbytes = 1;
	while (rbytes > 0 && !lookfor_nl(buf))
	{
		rbytes = read(*fd, buf, BUFFER_SIZE);
		if (rbytes)
		{
			buf[rbytes] = 0;
			line[0] = ft_strjoin_nl(line[0], buf);
		}
		else if (rbytes == -1)
			return (NULL);
		else if (rbytes == 0 && buf[0] != 0)
			return (refresh_buf(buf), line[0]);
		else
		{
			free(line[0]);
			line[0] = NULL;
			return (line[0]);
		}
	}
	return (line[0]);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (NULL);
	line = ft_strdup_nl("");
	line = ft_strjoin_nl(line, buf);
	line = win_line_shameless(buf, &line, &fd);
	refresh_buf(buf);
	return (line);
}
