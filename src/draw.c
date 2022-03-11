/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:42 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 15:04:38 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(int *)pixel = color;
	}
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


// TODO: Change to Bresenham algorithm
void	plot_line(t_img *img, t_vec3 vec0, t_vec3 vec1, int color)
{
	float	delta_x;
	float	delta_y;
	float	x_inc;
	float	y_inc;
	int	longest_side_length;

	delta_x = (vec1.x - vec0.x);
	delta_y = (vec1.y - vec0.y);

	longest_side_length = (fabs(delta_x) >= fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);

	// Find how much we should increment in both x and y each step
	x_inc = delta_x / (float)longest_side_length;
	y_inc = delta_y / (float)longest_side_length;

	for (int i = 0; i <= longest_side_length; i++)
	{
		img_pix_put(img, round(vec0.x), round(vec0.y), color);
		vec0.x += x_inc;
		vec0.y += y_inc;
	}

}

