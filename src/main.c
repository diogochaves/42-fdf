/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 13:55:03 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	render(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map = map_init(argc, argv);
	fdf.display = display_init();
	fdf.data = data_init(&fdf);
	fdf.mouse = mouse_init();
	fdf.menu = 1;
	display_img_init(&fdf);
	mlx_loop_hook(fdf.display->mlx_ptr, &render, &fdf);
	mlx_hook(fdf.display->win_ptr, DestroyNotify, NoEventMask, &close_window, &fdf);
	mlx_hook(fdf.display->win_ptr, KeyPress, KeyPressMask, &key_press, &fdf);
	mlx_hook(fdf.display->win_ptr, ButtonPress, ButtonPressMask, &mouse_press, &fdf);
	mlx_hook(fdf.display->win_ptr, ButtonRelease, ButtonReleaseMask, &mouse_release, &fdf);
	mlx_hook(fdf.display->win_ptr, MotionNotify, PointerMotionMask, &mouse_move, &fdf);
	mlx_loop(fdf.display->mlx_ptr);
}

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
