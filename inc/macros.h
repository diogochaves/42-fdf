/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:25:04 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 14:39:43 by dchaves-         ###   ########.fr       */
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

# define C_BACK			0x21252b
# define C_FRONT		0xf8f8f2
# define C_STATUS_BAR	0x282a36
# define C_MENU_BTN		0x383a59
# define C_MENU_TXT		0x8c929e
# define C_TXT			0xbd93f9
# define C_WHITE		0xFFFFFF
# define C_BLACK		0x000000
# define C_RED			0xff5555
# define C_YELLOW		0xf1fa8c
# define C_GREEN		0x50fa7b
# define C_CYAN			0x8be9fd
# define C_PINK			0xff79c6
# define C_PURPLE		0xbd93f9
# define C_ORANGE		0xffb86c

# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

# define HEX_BASE			"0123456789abcdef"

# define ERROR_MALLOC		1
# define ERROR_OPEN			2
# define ERROR_ARGC			3
# define ERROR_MAP			4
# define ERROR_DISPLAY		5

enum e_projection
{
	TOP,
	ISOMETRIC,
	PERSPECTIVE
};

#endif
