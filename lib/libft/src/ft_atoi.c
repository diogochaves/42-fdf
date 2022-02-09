/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:47:53 by dchaves-          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:04 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		++nptr;
	}
	num = 0;
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr - '0';
		++nptr;
	}
	return (sign * num);
}
