/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:44:58 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:45:00 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!little[0])
		return ((char *)big);
	while (big[j])
	{
		i = 0;
		while (big[j + i] == little[i] && little[i] && len > (j + i))
			i++;
		if (!little[i])
			return ((char *)big + j);
		j++;
	}
	return (0);
}
