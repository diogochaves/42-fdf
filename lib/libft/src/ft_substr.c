/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:53:29 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:53:34 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	j;

	substr = malloc(sizeof(char) * (len + 1));
	if (!s || !substr)
		return (0);
	j = 0;
	while (start < ft_strlen(s) && j < len)
		substr[j++] = s[start++];
	substr[j] = '\0';
	return (substr);
}
