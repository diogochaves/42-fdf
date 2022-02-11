/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/02/11 20:59:12 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

// ESC: Exit | TAB: Debug info
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_Tab)
	{
		printf("bpp: %d\n", data->img.bits_per_pixel);
		printf("line_len: %d\n", data->img.line_len);
		printf("endian: %d\n", data->img.endian);
	}		
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	
	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}



void	plot_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int e2; /* error value e_xy */

	dx =  abs (x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs (y1 - y0);
	sy = y0 < y1 ? 1 : -1; 
	err = dx + dy; 

	while (1){
		img_pix_put(img, x0, y0, color);
		if (x0 == x1 && y0 == y1) 
			break;
		e2 = 2 * err;
		if (e2 >= dy) { /* e_xy+e_x > 0 */
			err += dy;
			x0 += sx;
		} 
		if (e2 <= dx) { /* e_xy+e_y < 0 */
			err += dx;
			y0 += sy;
		}
	}
}

int	create_image(t_data *data)
{
	render_background(&data->img, BACKGROUND);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	plot_line(&data->img, 800, 100, 0, WINDOW_HEIGHT - 100, FOREGROUND);	
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

void	load_map(int argc, char **argv)
{
	int		fd;
	char	*map;
	int		lines;
	int		columns;

	printf("argc: %d | argv[0]: %s | argv[1]: %s\n", argc, argv[0], argv[1]);
	//check_args();
	fd = open(argv[1], O_RDONLY);
	printf("fd: %d\n", fd);

	lines = 0;
	columns = 0;
	while(1)
	{
		map = get_next_line(fd);
		if (!map)
			break ;
		lines++;
		printf("%s", map);
		free(map);
	}
	printf("lines: %d\n", lines);
	printf("columns: %d\n", columns);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_data	data;

	load_map(argc, argv);

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */ 
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel,
			&data.img.line_len, &data.img.endian);
	create_image(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &close_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
}
