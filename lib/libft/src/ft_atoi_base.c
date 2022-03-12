/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:49:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 21:08:46 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert_from_base(char *str, char *base);
static int	ft_check_base_error(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	if (!ft_check_base_error(base))
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	if (*str == '0')
	{
		++str;
		if (*str == 'x')
			++str;
	}
	num = ft_convert_from_base(str, base);
	return (sign * num);
}

static int	ft_convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		total;
	int		base_len;

	i = 0;
	total = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, ft_tolower(str[i])))
	{
		c = 0;
		while (base[c] != ft_tolower(str[i]) && base[c])
			c++;
		total = (total * base_len) + c;
		i++;
	}
	return (total);
}

static int	ft_check_base_error(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		c = 1;
		while (str[i + c])
		{
			if (str[i + c] == str[i])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}
