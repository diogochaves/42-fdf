/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:25:38 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:53:56 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	plot_line(t_img *img, t_vec vec0, t_vec vec1)
{
	t_vec	vec;
	int		i;	
	float	x_inc;
	float	y_inc;
	int		longest_side_length;

	if (fabs(vec1.x - vec0.x) >= fabs(vec1.y - vec0.y))
		longest_side_length = fabs(vec1.x - vec0.x);
	else
		longest_side_length = fabs(vec1.y - vec0.y);
	x_inc = (vec1.x - vec0.x) / (float)longest_side_length;
	y_inc = (vec1.y - vec0.y) / (float)longest_side_length;
	vec = vec0;
	i = 0;
	while (i++ <= longest_side_length)
	{
		if (fabs(vec1.x - vec0.x) >= fabs(vec1.y - vec0.y))
			img_pix_put(img, round(vec.x), round(vec.y), \
			get_color(vec, vec0, vec1, percent(vec0.x, vec1.x, vec.x)));
		else
			img_pix_put(img, round(vec.x), round(vec.y), \
			get_color(vec, vec0, vec1, percent(vec0.y, vec1.y, vec.y)));
		vec.x += x_inc;
		vec.y += y_inc;
	}
}
