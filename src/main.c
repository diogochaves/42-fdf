/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 02:42:08 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	render(t_fdf *fdf)
{
	if (fdf->data->win_ptr == NULL)
		return (1);
	create_image(fdf);
	mlx_put_image_to_window(fdf->data->mlx_ptr, fdf->data->win_ptr, fdf->data->img.mlx_img, 0, 0);
	mlx_string_put(fdf->data->mlx_ptr, fdf->data->win_ptr, 10, 100, FOREGROUND, "TEST");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map = map_init(argc, argv);
	fdf.data = data_init();
	data_img_init(&fdf);
	fdf.stats = stats_init();
	
	/* Setup hooks */ 
	mlx_loop_hook(fdf.data->mlx_ptr, &render, &fdf);
	mlx_hook(fdf.data->win_ptr, DestroyNotify, NoEventMask, &close_window, &fdf);
	mlx_hook(fdf.data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &fdf);
	mlx_loop(fdf.data->mlx_ptr);
}
