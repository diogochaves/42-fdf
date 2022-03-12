/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:44:47 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 02:34:43 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mouse	*mouse_init(void)
{
	t_mouse	*mouse;

	mouse = malloc(sizeof(t_mouse));
	if (!mouse)
		return (NULL);
	mouse->left_button = 0;
	mouse->right_button = 0;
	mouse->third_button = 0;
	mouse->x = 0;
	mouse->y = 0;
	return(mouse);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	
	if (button == MOUSE_SCROLL_UP)
		fdf->data->scale *= 1.2;
	if (button == MOUSE_SCROLL_DOWN)
		fdf->data->scale /= 1.2;
	if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->left_button = 1;
	if (button == MOUSE_RIGHT_BUTTON)
		fdf->mouse->right_button = 1;
	if (button == MOUSE_THIRD_BUTTON)
		fdf->mouse->third_button = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	(void)button;
	
	fdf->mouse->left_button = 0;
	fdf->mouse->right_button = 0;
	fdf->mouse->third_button = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse->left_button)
	{
		fdf->data->x_move += x - fdf->mouse->x;
		fdf->data->y_move += y - fdf->mouse->y;
	}
	else if (fdf->mouse->right_button)
	{
		fdf->data->y_angle += (x - fdf->mouse->x) * ANG_1;
		fdf->data->x_angle -= (y - fdf->mouse->y) * ANG_1;
	}	
	else if (fdf->mouse->third_button)
	{
		fdf->data->z_angle -= (x - fdf->mouse->x) * ANG_1;
		fdf->data->z_angle += (y - fdf->mouse->y) * ANG_1;
	}		
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	return (0);
}
