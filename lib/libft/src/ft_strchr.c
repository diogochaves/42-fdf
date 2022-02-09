/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:31:49 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:34:15 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The terminating null byte is considered part of the string, so that if C is
 specified as '\0', the function return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
