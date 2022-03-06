/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/06 21:58:13 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	plot_map(t_fdf *fdf)
{
	int	row;
	int	col;
	int	offset_x;
	int	offset_y;

	row = 0;
	col = 0;
	offset_x = 50;
	offset_y = 50;
	while(row < fdf->map->rows)
	{
		while (col < fdf->map->columns)
		{
			img_pix_put(
				&fdf->data->img, 
				fdf->map->vectors[row][col].x + offset_x, 
				fdf->map->vectors[row][col].y + offset_y,
				WHITE_PIXEL);
			col++;
			offset_y += 20;
		}
		printf("\n");
		col = 0;
		offset_y = 50;
		row++;
		offset_x += 20;
	}
}

int	create_image(t_fdf *fdf)
{
	render_background(&fdf->data->img, BACKGROUND);
	//render_rect(&fdf->data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	//render_rect(&fdf->data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	//plot_line(&fdf->data->img, 800, 100, 0, WINDOW_HEIGHT - 100, FOREGROUND);
	plot_map(fdf);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 100, FOREGROUND, "TEST");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map = read_map(argc, argv);
	fdf.data = malloc(sizeof(t_data));

	print_map(fdf.map);

	fdf.data->mlx_ptr = mlx_init();
	if (fdf.data->mlx_ptr == NULL)
		return (MLX_ERROR);
	fdf.data->win_ptr = mlx_new_window(fdf.data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (fdf.data->win_ptr == NULL)
	{
		free(fdf.data->win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */ 
	fdf.data->img.mlx_img = mlx_new_image(fdf.data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.data->img.addr = mlx_get_data_addr(fdf.data->img.mlx_img, &fdf.data->img.bits_per_pixel,
			&fdf.data->img.line_len, &fdf.data->img.endian);
	create_image(&fdf);
	mlx_loop_hook(fdf.data->mlx_ptr, &render, fdf.data);
	mlx_hook(fdf.data->win_ptr, DestroyNotify, NoEventMask, &close_window, &fdf);
	mlx_hook(fdf.data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &fdf);
	mlx_loop(fdf.data->mlx_ptr);
}
