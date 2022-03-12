/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 14:07:55 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	transform(t_fdf *fdf, t_vec *vec)
{
	rotate_x(vec, fdf->data->x_angle);
	rotate_y(vec, fdf->data->y_angle);
	rotate_z(vec, fdf->data->z_angle);
	isometric(&vec->x, &vec->y, vec->z);
	scale(vec, fdf->data->scale);
	translate(vec, fdf->data->x_move, fdf->data->y_move);
}
