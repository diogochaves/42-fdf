/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:44:30 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/15 13:00:58 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	keycode_projection(int key, t_fdf *fdf);
static int	keycode_data(int key, t_fdf *fdf);
static int	keycode_scale(int key, t_fdf *fdf);

int	key_press(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		close_window(fdf);
	else if (key == XK_Tab)
		fdf->menu = toggle(fdf->menu);
	else if (key == XK_slash)
		fdf->animation = toggle(fdf->animation);	
	else if (key == XK_Control_L || key == XK_Control_R)
		fdf->mod_key = 1;
	else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4)
		keycode_projection(key, fdf);
	else if (key == XK_w || key == XK_s || key == XK_a || key == XK_d \
		|| key == XK_q || key == XK_e || key == XK_Up || key == XK_Down \
		|| key == XK_Left || key == XK_Right || key == XK_r)
		keycode_data(key, fdf);
	else if (key == XK_equal || key == XK_KP_Add || key == XK_minus \
		|| key == XK_KP_Subtract || key == XK_z || key == XK_x)
		keycode_scale(key, fdf);
	return (0);
}

int	key_release(int key, t_fdf *fdf)
{
	if (key == XK_Control_L || key == XK_Control_R)
		fdf->mod_key = 0;
	return (0);
}

static int	keycode_projection(int key, t_fdf *fdf)
{
	if (key == XK_1)
	{
		fdf->data->projection = ISOMETRIC;
		data_reset(fdf);
	}
	else if (key == XK_2)
	{
		fdf->data->projection = DIMETRIC;
		data_reset(fdf);
	}	
	else if (key == XK_3)
	{
		fdf->data->projection = PERSPECTIVE;
		data_reset(fdf);
	}
	else if (key == XK_4)
	{
		fdf->data->projection = TOP;
		data_reset(fdf);
	}	
	return (0);
}

static int	keycode_data(int key, t_fdf *fdf)
{
	if (key == XK_w)
		fdf->data->x_angle += 5 * ANG_1;
	else if (key == XK_s)
		fdf->data->x_angle -= 5 * ANG_1;
	else if (key == XK_a)
		fdf->data->y_angle -= 5 * ANG_1;
	else if (key == XK_d)
		fdf->data->y_angle += 5 * ANG_1;
	else if (key == XK_q)
		fdf->data->z_angle -= 5 * ANG_1;
	else if (key == XK_e)
		fdf->data->z_angle += 5 * ANG_1;
	else if (key == XK_Up)
		fdf->data->y_move += -10;
	else if (key == XK_Down)
		fdf->data->y_move += 10;
	else if (key == XK_Left)
		fdf->data->x_move += -10;
	else if (key == XK_Right)
		fdf->data->x_move += 10;
	else if (key == XK_r)
		data_reset(fdf);
	return (0);
}

static int	keycode_scale(int key, t_fdf *fdf)
{
	if (key == XK_equal || key == XK_KP_Add)
		fdf->data->scale *= 1.1;
	else if (key == XK_minus || key == XK_KP_Subtract)
		fdf->data->scale /= 1.1;
	else if (key == XK_z && fdf->data->z_scale < 1)
		fdf->data->z_scale += 0.1;
	else if (key == XK_x && fdf->data->z_scale > -1)
		fdf->data->z_scale -= 0.1;
	return (0);
}
