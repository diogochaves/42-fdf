/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:42 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 00:46:04 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	plot_line(t_img *img, t_vec3 vec0, t_vec3 vec1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int e2; /* error value e_xy */

	dx =  fabs (vec1.x - vec0.x);
	sx = vec0.x < vec1.x ? 1 : -1;
	dy = -fabs (vec1.y - vec0.y);
	sy = vec0.y < vec1.y ? 1 : -1; 
	err = dx + dy; 

	while (1){
		img_pix_put(img, vec0.x, vec0.y, color);
		if (vec0.x == vec1.x && vec0.y == vec1.y) 
			break;
		e2 = 2 * err;
		if (e2 >= dy) { /* e_xy+e_x > 0 */
			err += dy;
			vec0.x += sx;
		} 
		if (e2 <= dx) { /* e_xy+e_y < 0 */
			err += dx;
			vec0.y += sy;
		}
	}
}
