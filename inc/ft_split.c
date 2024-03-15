/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:19:20 by musozer           #+#    #+#             */
/*   Updated: 2024/03/03 18:44:16 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			i++;
			count++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start++;
		i++;
	}
	return (i);
}

static char	*ft_push(char const *s, char c, int start)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = start;
	dest = malloc(sizeof(char) * (ft_wordlen(s, c, start) + 1));
	if (!dest)
		return (0);
	while (s[i] && s[i] != c)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**a;

	i = 0;
	j = -1;
	if (!s)
		return (0);
	a = malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!a)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			a[++j] = ft_push(s, c, i);
		while (s[i] != c && s[i])
			i++;
	}
	a[++j] = NULL;
	return (a);
}
