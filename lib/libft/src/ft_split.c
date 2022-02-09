/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:58:41 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:58:42 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	token_count(char const *s, char c)
{
	size_t	flag;
	size_t	count;

	flag = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}

static void	create_tokens(char **group, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		pos;

	i = 0;
	j = 0;
	pos = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && pos == -1)
			pos = i;
		else if ((s[i] == c || i == ft_strlen(s)) && pos != -1)
		{
			group[j] = ft_substr(s, pos, i - pos);
			j++;
			pos = -1;
		}
		i++;
	}
	group[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**group;

	group = malloc((token_count(s, c) + 1) * sizeof(char *));
	if (!s || !group)
		return (0);
	create_tokens(group, s, c);
	return (group);
}
