/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:39:45 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 10:39:48 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 strlcat() take the full size of the buffer (not just the length) and
 guarantee to NUL-terminate the result (as long as there is at least one byte
 free in DST).  Note that a byte for the NUL should be included in size.
 Also note that strlcat() only operate on true “C” strings.  This means that
 for strlcat() both SRC and DST must be NUL-terminated.

 If strlcat() traverses size characters without finding a NUL, the length of
 the string is considered to be SIZE and the destination string will not be
 NUL-terminated (since there was no space for the NUL). This keeps strlcat()
 from running off the end of a string. In practice this should not happen (as
 it means that either SIZE is incorrect or that DST is not a proper “C”
 string). The check exists to prevent potential security problems in incorrect
 code.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
