/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:32:51 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/10 13:26:35 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(t_fdf *fdf)
{
	map_free(fdf->map);
	free(fdf->map);
	mlx_destroy_image(fdf->data->mlx_ptr, fdf->data->img.mlx_img);
	mlx_destroy_window(fdf->data->mlx_ptr, fdf->data->win_ptr);
	mlx_destroy_display(fdf->data->mlx_ptr);
	free(fdf->data->mlx_ptr);
	free(fdf->data);
	exit(0);
}
