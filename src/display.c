/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:30:56 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 14:40:33 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_display	*display_init(void)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
		error(ERROR_MALLOC);
	display->mlx_ptr = mlx_init();
	if (display->mlx_ptr == NULL)
		return (0);
	display->win_ptr = mlx_new_window(
			display->mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"FDF");
	if (display->win_ptr == NULL)
	{
		free(display->win_ptr);
		error(ERROR_DISPLAY);
	}	
	return (display);
}

void	display_img_init(t_fdf *fdf)
{
	fdf->display->img.mlx_img = mlx_new_image(
			fdf->display->mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	fdf->display->img.addr = mlx_get_data_addr(
			fdf->display->img.mlx_img,
			&fdf->display->img.bits_per_pixel,
			&fdf->display->img.line_len,
			&fdf->display->img.endian);
}

int	create_image(t_fdf *fdf)
{
	fill_img(&fdf->display->img, C_BACK);
	plot_map(fdf);
	return (0);
}
