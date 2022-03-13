/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:55:13 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 14:47:29 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	status_bar(t_fdf *fdf);
static void	status_bar_txt(t_fdf *fdf);
static void	info_menu(t_fdf *fdf);
static void	info_menu_txt(t_fdf *fdf);

void	interface(t_fdf *fdf)
{
	info_menu(fdf);
	status_bar(fdf);
}

void	interface_txt(t_fdf *fdf)
{
	info_menu_txt(fdf);
	status_bar_txt(fdf);
}

static void	status_bar(t_fdf *fdf)
{
	t_rect	status_bar;

	status_bar.color = C_STATUS_BAR;
	status_bar.height = 30;
	status_bar.width = WINDOW_WIDTH;
	status_bar.x = 0;
	status_bar.y = WINDOW_HEIGHT - status_bar.height;
	plot_rectangle(&fdf->display->img, status_bar);
}

static void	info_menu(t_fdf *fdf)
{
	t_rect	info_menu;

	info_menu.color = C_MENU_BTN;
	info_menu.height = 28;
	info_menu.width = 160;
	info_menu.x = 0;
	info_menu.y = 22;
	plot_rectangle(&fdf->display->img, info_menu);
}

static void	info_menu_txt(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->display->mlx_ptr;
	win = fdf->display->win_ptr;
	if (fdf->menu)
	{
		mlx_string_put(mlx, win, 12, 40, C_FRONT, "[ TAB ] HIDE MENU");
		mlx_string_put(mlx, win, 12, 90, C_MENU_TXT, "/ KEYBOARD CONTROLS /");
		mlx_string_put(mlx, win, 12, 120, C_FRONT, "[ ESC ] QUIT");
		mlx_string_put(mlx, win, 12, 150, C_FRONT, "[ ARROW KEYS ] MOVE");
		mlx_string_put(mlx, win, 12, 170, C_FRONT, "[ A ] [ D ] X ROTATE");
		mlx_string_put(mlx, win, 12, 190, C_FRONT, "[ W ] [ S ] Y ROTATE");
		mlx_string_put(mlx, win, 12, 210, C_FRONT, "[ Q ] [ E ] Z ROTATE");
		mlx_string_put(mlx, win, 12, 230, C_FRONT, "[ + ] [ - ] ZOOM");
		mlx_string_put(mlx, win, 12, 260, C_FRONT, "[ R ] RESET CURRENT VIEW");
		mlx_string_put(mlx, win, 12, 280, C_FRONT, "[ T ] TOP VIEW");
		mlx_string_put(mlx, win, 12, 300, C_FRONT, "[ I ] ISOMETRIC VIEW");
		mlx_string_put(mlx, win, 12, 320, C_FRONT, "[ P ] PERSPECTIVE VIEW");
		mlx_string_put(mlx, win, 12, 360, C_MENU_TXT, "/ MOUSE CONTROLS /");
		mlx_string_put(mlx, win, 12, 390, C_FRONT, "[ WHEEL ] ZOOM");
		mlx_string_put(mlx, win, 12, 410, C_FRONT, "[ LEFT BTN ] MOVE");
		mlx_string_put(mlx, win, 12, 430, C_FRONT, "[ RIGHT BTN ] ROTATE X/Y");
		mlx_string_put(mlx, win, 12, 450, C_FRONT, "[ WHEEL BTN ] ROTATE Z");
	}
	else
		mlx_string_put(mlx, win, 12, 40, C_FRONT, "[ TAB ] SHOW MENU");
}	

static void	status_bar_txt(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*txt;
	int		y;

	mlx = fdf->display->mlx_ptr;
	win = fdf->display->win_ptr;
	y = WINDOW_HEIGHT - 10;
	mlx_string_put(mlx, win, 10, y, C_TXT, "SCALE:");
	txt = ft_itoa(fdf->data->scale);
	mlx_string_put(mlx, win, 50, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 90, y, C_TXT, "X OFFSET:");
	txt = ft_itoa(fdf->data->x_move);
	mlx_string_put(mlx, win, 150, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 190, y, C_TXT, "Y OFFSET:");
	txt = ft_itoa(fdf->data->y_move);
	mlx_string_put(mlx, win, 250, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 290, y, C_TXT, "X ROTATE:");
	txt = ft_itoa(fdf->data->x_angle / ANG_1);
	mlx_string_put(mlx, win, 350, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 390, y, C_TXT, "Y ROTATE:");
	txt = ft_itoa(fdf->data->y_angle / ANG_1);
	mlx_string_put(mlx, win, 450, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 490, y, C_TXT, "Z ROTATE:");
	txt = ft_itoa(fdf->data->z_angle / ANG_1);
	mlx_string_put(mlx, win, 550, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 1160, y, C_TXT, "X:");
	txt = ft_itoa(fdf->mouse->x);
	mlx_string_put(mlx, win, 1180, y, C_TXT, txt);
	free(txt);
	mlx_string_put(mlx, win, 1220, y, C_TXT, "Y:");
	txt = ft_itoa(fdf->mouse->y);
	mlx_string_put(mlx, win, 1240, y, C_TXT, txt);
	free(txt);
}
