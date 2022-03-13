/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 14:03:53 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	perspective(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x / z;
	*y = -previous_y / z;
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

void	project(t_fdf *fdf, t_vec *vec)
{
	if (fdf->data->projection == ISOMETRIC)
		isometric(&vec->x, &vec->y, vec->z);
	if (fdf->data->projection == PERSPECTIVE)
		perspective(&vec->x, &vec->y, vec->z);
}
