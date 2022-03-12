/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 14:07:55 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, float z)
{
	float previous_x;
	float previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	scale(t_vec *vec, int scale)
{
	vec->x *= scale;
	vec->y *= scale;
}

void	translate(t_vec *vec, float x_move, float y_move)
{
	vec->x += x_move;
	vec->y += y_move;
}

void	project(t_vec *vec, int scale)
{
	vec->x = vec->x * scale + 400;
	vec->y = vec->y * scale + 400 - vec->z;
}
