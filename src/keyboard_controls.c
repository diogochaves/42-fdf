/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:44:30 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 23:45:22 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_press(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_window(fdf);
	if (keysym == XK_Tab)
	{
		printf("WINDOW_WIDTH: %d\n", WINDOW_WIDTH);
		printf("fdf->map->columns: %d\n", fdf->map->columns);
		printf("fdf->data->x_move: %f\n", fdf->data->x_move);
	}
	if (keysym == XK_w)
		fdf->data->x_angle += 5 * ANG_1;
	if (keysym == XK_s)
		fdf->data->x_angle -= 5 * ANG_1;
	if (keysym == XK_a)
		fdf->data->y_angle -= 5 * ANG_1;
	if (keysym == XK_d)
		fdf->data->y_angle += 5 * ANG_1;
	if (keysym == XK_q)
		fdf->data->z_angle -= 5 * ANG_1;
	if (keysym == XK_e)
		fdf->data->z_angle += 5 * ANG_1;
	if (keysym == XK_Up)
		fdf->data->y_move += -10;
	if (keysym == XK_Down)
		fdf->data->y_move += 10;
	if (keysym == XK_Left)
		fdf->data->x_move += -10;
	if (keysym == XK_Right)
		fdf->data->x_move += 10;
	if (keysym == XK_r)
		data_reset(fdf);
	if (keysym == XK_equal || keysym == XK_KP_Add)
		fdf->data->scale *= 1.2;
	if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fdf->data->scale /= 1.2;
	return (0);
}
