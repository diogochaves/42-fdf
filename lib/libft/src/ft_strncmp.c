/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:37:06 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 15:37:12 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	diff;

	diff = 0;
	while ((*s1 || *s2) && n--)
	{
		diff = (unsigned char)*s1 - (unsigned char)*s2;
		if (diff != 0)
			break ;
		s1++;
		s2++;
	}
	return (diff);
}
