/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:04:12 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:04:25 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	scale(t_vec *vec, int scale)
{
	vec->x *= scale;
	vec->y *= scale;
}

void	translate(t_vec *vec, float x_move, float y_move)
{
	vec->x += x_move;
	vec->y += y_move;
}
