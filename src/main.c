/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:43 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/15 12:50:37 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	void	*win_ptr;

	fdf.map = map_init(argc, argv);
	fdf.display = display_init();
	fdf.data = data_init(&fdf);
	fdf.mouse = mouse_init();
	fdf.menu = 1;
	fdf.mod_key = 0;
	fdf.animation = 0;
	win_ptr = fdf.display->win_ptr;
	display_img_init(&fdf);
	mlx_loop_hook(fdf.display->mlx_ptr, &render, &fdf);
	mlx_hook(win_ptr, DestroyNotify, NoEventMask, &close_window, &fdf);
	mlx_hook(win_ptr, KeyPress, KeyPressMask, &key_press, &fdf);
	mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, &key_release, &fdf);
	mlx_hook(win_ptr, ButtonPress, ButtonPressMask, &mouse_press, &fdf);
	mlx_hook(win_ptr, ButtonRelease, ButtonReleaseMask, &mouse_release, &fdf);
	mlx_hook(win_ptr, MotionNotify, PointerMotionMask, &mouse_move, &fdf);
	mlx_loop(fdf.display->mlx_ptr);
}
