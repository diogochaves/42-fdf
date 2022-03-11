/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:38:25 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 02:57:30 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// ESC: Exit | TAB: Debug info
int	handle_keypress(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_window(fdf);
	if (keysym == XK_Tab)
	{
		printf("bpp: %d\n", fdf->data->img.bits_per_pixel);
		printf("line_len: %d\n", fdf->data->img.line_len);
		printf("endian: %d\n", fdf->data->img.endian);
	}
	if (keysym == XK_x)
	{
		rotate_x(fdf);
		printf("x\n");
	}
	if (keysym == XK_Up)
		fdf->stats->y_move += -10;
	if (keysym == XK_Down)
		fdf->stats->y_move += 10;
	if (keysym == XK_Left)
		fdf->stats->x_move += -10;
	if (keysym == XK_Right)
		fdf->stats->x_move += 10;
	return (0);
}
