/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:37:35 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 02:48:45 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_stats	*stats_init()
{
	t_stats	*stats;
	
	stats = malloc(sizeof(t_stats));
	// TODO: check malloc

	stats->x_move = 0;
	stats->y_move = 0;

	return(stats);
}
