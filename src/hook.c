/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:38:25 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/06 20:20:09 by dchaves-         ###   ########.fr       */
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
	return (0);
}
