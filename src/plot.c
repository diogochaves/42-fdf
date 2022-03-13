/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:42 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 13:58:59 by dchaves-         ###   ########.fr       */
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

void	fill_img(t_img *img, int color)
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

/* The x and y coordinates of the rect corresponds to its upper left corner. */
int	plot_rectangle(t_img *img, t_rect rect)
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

// TODO: Change to Bresenham algorithm
void	plot_line(t_img *img, t_vec vec0, t_vec vec1)
{
	float	delta_x;
	float	delta_y;
	float	x_inc;
	float	y_inc;
	int		longest_side_length;
	t_vec	vec_current;
	double	percentage;

	delta_x = (vec1.x - vec0.x);
	delta_y = (vec1.y - vec0.y);

	longest_side_length = (fabs(delta_x) >= fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);

	// Find how much we should increment in both x and y each step
	x_inc = delta_x / (float)longest_side_length;
	y_inc = delta_y / (float)longest_side_length;

	vec_current.x = vec0.x;
	vec_current.y = vec0.y;
	vec_current.color = vec0.color;
	
	for (int i = 0; i <= longest_side_length; i++)
	{
		if (delta_x > delta_y)
			percentage = percent(vec0.x, vec1.x, vec_current.x);
		else
			percentage = percent(vec0.y, vec1.y, vec_current.y);
		img_pix_put(
			img, 
			round(vec_current.x), 
			round(vec_current.y), 
			get_color(vec_current, vec0, vec1, percentage)
		);
		vec_current.x += x_inc;
		vec_current.y += y_inc;
	}

}

void	plot_map(t_fdf *fdf)
{
	int		row;
	int		col;
	t_vec	vec0;
	t_vec	vec1;

	row = 0;
	while(row < fdf->map->rows)
	{
		col = 0;
		while (col < fdf->map->columns)
		{
			vec0 = fdf->map->vectors[row][col];
			transform(fdf, &vec0);
			if (col < fdf->map->columns - 1)
			{
				vec1 = fdf->map->vectors[row][col + 1];
				transform(fdf, &vec1);
				plot_line(&fdf->display->img, vec0, vec1);
			}
			if (row < fdf->map->rows - 1)
			{
				vec1 = fdf->map->vectors[row + 1][col];
				transform(fdf, &vec1);
				plot_line(&fdf->display->img, vec0, vec1);
			}
			col++;
		}
		row++;
	}
}
