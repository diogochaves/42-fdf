/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:32:54 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 10:32:57 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Strlcpy() take the full size of the buffer (not just the length) and
 guarantee to NUL-terminate the result (as long as size is larger than 0).
 Note that a byte for the NUL should be included in size.  Also note that
 strlcpy() only operate on true “C” strings.  This means that for strlcpy()
 src must be NUL-terminated.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
