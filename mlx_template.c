/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_template.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:07:39 by dchaves-          #+#    #+#             */
/*   Updated: 2022/02/09 21:07:39 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	(void) data;
	return (0);
}

int main(void)
{
	t_data	data;
	void	*img;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");

	img = mlx_new_image(&data, 1280, 720);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &close_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
}
