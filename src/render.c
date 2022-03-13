/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 23:22:51 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	transform(t_fdf *fdf, t_vec *vec)
{
	rotate_x(vec, fdf->data->x_angle);
	rotate_y(vec, fdf->data->y_angle);
	rotate_z(vec, fdf->data->z_angle);
	project(fdf, vec);
	scale(vec, fdf->data->scale);
	translate(vec, fdf->data->x_move, fdf->data->y_move);
}
