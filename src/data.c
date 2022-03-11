/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:30:56 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 15:08:39 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_data	*data_init()
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	// TODO: check malloc

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}	

	return(data);
}

void	data_img_init(t_fdf *fdf)
{
	fdf->data->img.mlx_img = mlx_new_image(fdf->data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->data->img.addr = mlx_get_data_addr(fdf->data->img.mlx_img, &fdf->data->img.bits_per_pixel,
			&fdf->data->img.line_len, &fdf->data->img.endian);
}

int	create_image(t_fdf *fdf)
{
	render_background(&fdf->data->img, BACKGROUND);
	//render_rect(&fdf->data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	//render_rect(&fdf->data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	plot_map(fdf);
	return (0);
}

void project(t_vec3 *vec, int zoom)
{
	vec->x = vec->x * zoom + 400;
	vec->y = vec->y * zoom + 400 - vec->z;
}

/*
static void iso(float *x, float *y, float z)
{
	float previous_x;
	float previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
*/

void	transform(t_fdf *fdf, t_vec3 *vec)
{
	vec3_rotate_x(vec, fdf->stats->x_angle);
	vec3_rotate_y(vec, fdf->stats->y_angle);
	vec3_rotate_z(vec, fdf->stats->z_angle);	
	project(vec, fdf->stats->zoom);
	vec3_translate(vec, fdf->stats->x_move, fdf->stats->y_move);
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
				plot_line(&fdf->data->img, vec0, vec1, WHITE_PIXEL);
			}
			if (row < fdf->map->rows - 1)
			{
				vec1 = fdf->map->vectors[row + 1][col];
				transform(fdf, &vec1);
				plot_line(&fdf->data->img, vec0, vec1, WHITE_PIXEL);
			}
			col++;
		}
		col = 0;
		row++;
	}
}
