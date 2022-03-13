/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:16:35 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 21:55:11 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	get_light(int start, int end, double percentage);

int	get_color(t_vec current, t_vec start, t_vec end, double percentage)
{
	int	red;
	int	green;
	int	blue;

	if (current.color == end.color)
		return (current.color);
	red = get_light(
			(start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF,
			percentage);
	green = get_light(
			(start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF,
			percentage);
	blue = get_light(
			start.color & 0xFF,
			end.color & 0xFF,
			percentage);
	return ((red << 16) | (green << 8) | blue);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return (placement / distance);
}

int	get_map_color(char *str)
{
	int		color;

	str = ft_strchr(str, ',');
	if (!str)
		return (C_GREEN);
	++str;
	color = ft_atoi_base(str, HEX_BASE);
	return (color);
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
