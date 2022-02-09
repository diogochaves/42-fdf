/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:34:41 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 10:34:43 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 If the destination is above the source, we have to copy
 back to front to avoid overwriting the data we want to
 copy.

      dest:       dddddddd
      src:    ssssssss   ^
              |   ^  |___|
              |___|

 If the destination is below the source, we have to copy
 front to back.

      dest:   dddddddd
      src:    ^   ssssssss
              |___|  ^   |
                     |___|

*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
