/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:34:59 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:35:03 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The terminating null byte is considered part of the string, so that if C is
 specified as '\0', the function return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && (char)c != s[len])
		len--;
	if ((char)c == s[len])
		return ((char *)&s[len]);
	return (0);
}
