/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:55:25 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:55:26 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	ptr_size;
	char	*ptr;

	s1_len = ft_strlen(s1);
	ptr_size = s1_len + ft_strlen(s2) + 1;
	ptr = malloc(ptr_size);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, ptr_size);
	return (ptr);
}
