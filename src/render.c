/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 19:08:07 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	transform(t_fdf *fdf, t_vec3 *vec)
{
	vec3_rotate_x(vec, fdf->data->x_angle);
	vec3_rotate_y(vec, fdf->data->y_angle);
	vec3_rotate_z(vec, fdf->data->z_angle);
	isometric(&vec->x, &vec->y, vec->z);
	scale(vec, fdf->data->scale);
	translate(vec, fdf->data->x_move, fdf->data->y_move);
}

void	plot_map(t_fdf *fdf)
{
	int		row;
	int		col;
	t_vec3	vec0;
	t_vec3	vec1;

	row = 0;
	col = 0;

	while(row < fdf->map->rows)
	{
		while (col < fdf->map->columns)
		{
			vec0 = fdf->map->vectors[row][col];
			transform(fdf, &vec0);
			if (col < fdf->map->columns - 1)
			{
				vec1 = fdf->map->vectors[row][col + 1];
				transform(fdf, &vec1);
				plot_line(&fdf->display->img, vec0, vec1, WHITE_PIXEL);
			}
			if (row < fdf->map->rows - 1)
			{
				vec1 = fdf->map->vectors[row + 1][col];
				transform(fdf, &vec1);
				plot_line(&fdf->display->img, vec0, vec1, WHITE_PIXEL);
			}
			col++;
		}
		col = 0;
		row++;
	}
}
