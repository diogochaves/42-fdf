/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 23:01:29 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	render(t_fdf *fdf)
{
	if (fdf->display->win_ptr == NULL)
		return (1);
	create_image(fdf);
	interface(fdf);
	mlx_put_image_to_window(
		fdf->display->mlx_ptr,
		fdf->display->win_ptr,
		fdf->display->img.mlx_img,
		0,
		0);
	interface_txt(fdf);
	return (0);
}

void	transform(t_fdf *fdf, t_vec *vec)
{
	vec->z *= fdf->data->z_scale;
	rotate_x(vec, fdf->data->x_angle);
	rotate_y(vec, fdf->data->y_angle);
	rotate_z(vec, fdf->data->z_angle);
	project(fdf, vec);
	scale(vec, fdf->data->scale);
	translate(vec, fdf->data->x_move, fdf->data->y_move);
}
