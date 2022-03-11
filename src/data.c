/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:37:35 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:26 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static float	scale_init(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = (WINDOW_WIDTH - PADDING) / map->columns;
	scale_y = (WINDOW_HEIGHT - PADDING) / map->rows;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

t_data	*data_init(t_fdf *fdf)
{
	t_data	*data;
	(void)fdf;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return(NULL);
	data->scale = scale_init(fdf->map);
	data->x_move = WINDOW_WIDTH / 2;
	data->y_move = WINDOW_HEIGHT / 2;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;

	return(data);
}

void	data_reset(t_fdf *fdf)
{
	fdf->data->scale = scale_init(fdf->map);
	fdf->data->x_move = WINDOW_WIDTH / 2;
	fdf->data->y_move = WINDOW_HEIGHT / 2;
	fdf->data->x_angle = 0;
	fdf->data->y_angle = 0;
	fdf->data->z_angle = 0;
}
