/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:44:30 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 16:30:38 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_press(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_window(fdf);
	if (keysym == XK_Tab)
		fdf->menu = toggle(fdf->menu);
	if (keysym == XK_1)
	{
		fdf->data->projection = ISOMETRIC;
		data_reset(fdf);
	}
	if (keysym == XK_2)
	{
		fdf->data->projection = DIMETRIC;
		data_reset(fdf);
	}	
	if (keysym == XK_3)
	{
		fdf->data->projection = PERSPECTIVE;
		data_reset(fdf);
	}
	if (keysym == XK_4)
	{
		fdf->data->projection = TOP;
		data_reset(fdf);
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
		fdf->data->scale *= 1.1;
	if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fdf->data->scale /= 1.1;
	if (keysym == XK_z)
		fdf->data->z_scale += 0.1;
	if (keysym == XK_x)
		fdf->data->z_scale -= 0.1;
	if (keysym == XK_Control_L || keysym == XK_Control_R)
		fdf->mod_key = 1;
	return (0);
}

int	key_release(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Control_L || keysym == XK_Control_R)
		fdf->mod_key = 0;	
	return (0);
}
