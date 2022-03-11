/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:32:51 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 17:41:17 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(t_fdf *fdf)
{
	map_free(fdf->map);
	free(fdf->map);
	mlx_destroy_image(fdf->display->mlx_ptr, fdf->display->img.mlx_img);
	mlx_destroy_window(fdf->display->mlx_ptr, fdf->display->win_ptr);
	mlx_destroy_display(fdf->display->mlx_ptr);
	free(fdf->display->mlx_ptr);
	free(fdf->display);
	free(fdf->data);
	exit(0);
}
