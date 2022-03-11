/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:38:25 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 15:12:24 by dchaves-         ###   ########.fr       */
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
	if (keysym == XK_w)
		fdf->stats->x_angle += 5 * ANG_1;
	if (keysym == XK_s)
		fdf->stats->x_angle -= 5 * ANG_1;
	if (keysym == XK_a)
		fdf->stats->y_angle -= 5 * ANG_1;
	if (keysym == XK_d)
		fdf->stats->y_angle += 5 * ANG_1;
	if (keysym == XK_q)
		fdf->stats->z_angle -= 5 * ANG_1;
	if (keysym == XK_e)
		fdf->stats->z_angle += 5 * ANG_1;
	if (keysym == XK_Up)
		fdf->stats->y_move += -10.55;
	if (keysym == XK_Down)
		fdf->stats->y_move += 10.09;
	if (keysym == XK_Left)
		fdf->stats->x_move += -10.77;
	if (keysym == XK_Right)
		fdf->stats->x_move += 10.9388847439934;
	if (keysym == XK_r)
		stats_reset(fdf);
	return (0);
}
