/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:01:44 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 14:07:19 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(int error_code)
{
	if (error_code == ERROR_MALLOC)
		ft_putstr_fd("\033[31;1m\n   MALLOC ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_OPEN)
		ft_putstr_fd("\033[33;1m\n   ERROR OPENING FILE\033[0m\n\n", 1);
	if (error_code == ERROR_ARGC)
		ft_putstr_fd("\033[33;1m\n   WRONG NUMBER OF ARGUMENTS\033[0m\n\n", 1);
	if (error_code == ERROR_MAP)
		ft_putstr_fd("\033[31;1m\n   MAP ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_DISPLAY)
		ft_putstr_fd("\033[31;1m\n   DISPLAY ERROR\033[0m\n\n", 1);
	exit(error_code);
}
