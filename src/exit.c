/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:01:44 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 20:33:51 by dchaves-         ###   ########.fr       */
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
	free(fdf->mouse);
	exit(0);
}

void	error(int error_code)
{
	if (error_code == ERROR_MALLOC)
		ft_putstr_fd("\033[31;1m\n   MALLOC ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_OPEN)
		ft_putstr_fd("\033[33;1m\n   ERROR OPENING FILE\033[0m\n\n", 1);
	if (error_code == ERROR_ARGC)
		ft_putstr_fd("\033[33;1m\n   WRONG NUMBER OF ARGUMENTS\033[0m\n\n", 1);
	if (error_code == ERROR_MAP)
		ft_putstr_fd("\033[31;1m\n   MAP ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_DISPLAY)
		ft_putstr_fd("\033[31;1m\n   DISPLAY ERROR\033[0m\n\n", 1);
	exit(error_code);
}
