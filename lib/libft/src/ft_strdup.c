/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:50:49 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:50:51 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s) + 1;
	ptr = malloc(size);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, size);
	return (ptr);
}
