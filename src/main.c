/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 18:53:27 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	render(t_fdf *fdf)
{
	if (fdf->display->win_ptr == NULL)
		return (1);
	create_image(fdf);
	mlx_put_image_to_window(fdf->display->mlx_ptr, fdf->display->win_ptr, fdf->display->img.mlx_img, 0, 0);
	mlx_string_put(fdf->display->mlx_ptr, fdf->display->win_ptr, 10, 100, FOREGROUND, "TEST");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map = map_init(argc, argv);
	fdf.display = display_init();
	fdf.data = data_init(&fdf);	
	display_img_init(&fdf);
	
	/* Setup hooks */ 
	mlx_loop_hook(fdf.display->mlx_ptr, &render, &fdf);
	mlx_hook(fdf.display->win_ptr, DestroyNotify, NoEventMask, &close_window, &fdf);
	mlx_hook(fdf.display->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &fdf);
	mlx_loop(fdf.display->mlx_ptr);
}
