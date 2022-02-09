/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:14:12 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 20:14:16 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	dig;

	dig = 1;
	while (n != 0)
	{
		n = n / 10;
		if (n != 0)
			dig++;
	}
	return (dig);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		dig;
	char	*num_str;

	neg = 0;
	dig = count_digits(n);
	if (n < 0)
		neg = 1;
	else
		n = -n;
	num_str = malloc(sizeof(char) * (neg + dig + 1));
	if (!num_str)
		return (0);
	num_str[neg + dig] = '\0';
	while (dig)
	{
		num_str[neg + dig - 1] = -(n % 10) + '0';
		n /= 10;
		dig--;
	}
	if (neg)
		num_str[0] = '-';
	return (num_str);
}
