/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:04:22 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ANG_30);
	*y = -z + (previous_x + previous_y) * sin(ANG_30);
}

void	dimetric(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ANG_26);
	*y = -z + (previous_x + previous_y) * sin(ANG_26);
}

void	perspective(t_vec *vec, float s)
{
	float	z;

	rotate_x(vec, 3 * -ANG_45);
	z = vec->z + s;
	vec->x /= z;
	vec->y /= -z;
	scale(vec, s);
}

void	project(t_fdf *fdf, t_vec *vec)
{
	float	perspective_z;

	if (fdf->data->projection == ISOMETRIC)
		isometric(&vec->x, &vec->y, vec->z);
	if (fdf->data->projection == DIMETRIC)
		dimetric(&vec->x, &vec->y, vec->z);
	if (fdf->data->projection == PERSPECTIVE)
	{
		perspective_z = max(
				(fdf->map->z_max - fdf->map->z_min),
				max(fdf->map->columns, fdf->map->rows));
		perspective(vec, perspective_z);
	}
}
