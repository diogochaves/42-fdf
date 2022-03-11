/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:37:35 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 15:13:26 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_stats	*stats_init()
{
	t_stats	*stats;
	
	stats = malloc(sizeof(t_stats));
	// TODO: check malloc

	stats->zoom = 10;
	stats->x_move = 0;
	stats->y_move = 0;
	stats->x_angle = 0;
	stats->y_angle = 0;
	stats->z_angle = 0;

	return(stats);
}

void	stats_reset(t_fdf *fdf)
{
	fdf->stats->zoom = 10;
	fdf->stats->x_move = 0;
	fdf->stats->y_move = 0;
	fdf->stats->x_angle = 0;
	fdf->stats->y_angle = 0;
	fdf->stats->z_angle = 0;
}
