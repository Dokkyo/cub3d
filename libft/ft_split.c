/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:40:57 by naben-za          #+#    #+#             */
/*   Updated: 2021/06/03 12:41:43 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

static void	cpy(char *tab, char *from, char *until)
{
	while (from < until)
		*(tab++) = *(from++);
	*tab = 0;
}

static char	**free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (NULL);
}

static char	**fill_tab(char **tab, char const *s, char c)
{
	char			*from;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			from = (char *)&s[i];
			while (s[i] && s[i] != c)
				++i;
			tab[j] = malloc(sizeof(char) * (&s[i] - from + 1));
			if (!tab)
				return (free_tab(tab));
			cpy(tab[j++], from, (char *)&s[i]);
		}
		else
			++i;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	fill_tab(tab, s, c);
	return (tab);
}
