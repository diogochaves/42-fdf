/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:25:04 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 12:47:24 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	3
# define MOUSE_THIRD_BUTTON	2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define WINDOW_WIDTH		1280
# define WINDOW_HEIGHT		720
# define PADDING			200

# define MLX_ERROR 			1

# define COLOR_BACK			0x21252b
# define COLOR_FRONT		0xf8f8f2
# define COLOR_STATUS_BAR	0x282a36
# define COLOR_MENU_BTN		0x383a59
# define COLOR_MENU_TXT		0X8c929e
# define COLOR_TXT			0xbd93f9
# define COLOR_WHITE		0xFFFFFF
# define COLOR_BLACK		0x000000
# define COLOR_RED			0xff5555
# define COLOR_YELLOW		0xf1fa8c
# define COLOR_GREEN		0x50fa7b
# define COLOR_CYAN			0x8be9fd
# define COLOR_PINK			0xff79c6
# define COLOR_PURPLE		0xbd93f9
# define COLOR_ORANGE		0xffb86c

# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

# define HEX_BASE			"0123456789abcdef"

# define ERROR_MALLOC		1
# define ERROR_OPEN			2
# define ERROR_ARGC			3
# define ERROR_MAP			4

enum e_projection
{
	TOP,
	ISOMETRIC,
	PERSPECTIVE
};

#endif
