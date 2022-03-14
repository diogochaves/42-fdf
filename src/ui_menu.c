/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:37:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:13:15 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	info_menu_txt_show(t_fdf *fdf);

void	info_menu(t_fdf *fdf)
{
	t_rect	info_menu;
	t_rect	selected;

	info_menu.color = C_MENU_BTN;
	info_menu.height = 28;
	info_menu.width = 160;
	info_menu.x = 0;
	info_menu.y = 22;
	plot_rectangle(&fdf->display->img, info_menu);
	selected.color = C_PURPLE;
	selected.height = 14;
	selected.width = 5;
	selected.x = 0;
	if (fdf->data->projection == ISOMETRIC)
		selected.y = 109;
	if (fdf->data->projection == DIMETRIC)
		selected.y = 129;
	if (fdf->data->projection == PERSPECTIVE)
		selected.y = 149;
	if (fdf->data->projection == TOP)
		selected.y = 169;
	if (fdf->menu)
		plot_rectangle(&fdf->display->img, selected);
}

void	info_menu_txt(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->display->mlx_ptr;
	win = fdf->display->win_ptr;
	if (fdf->menu)
	{
		info_menu_txt_show(fdf);
	}
	else
		mlx_string_put(mlx, win, 12, 40, C_FRONT, "[ TAB ] SHOW MENU");
}	

static void	info_menu_txt_show(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->display->mlx_ptr;
	win = fdf->display->win_ptr;
	mlx_string_put(mlx, win, 12, 40, C_FRONT, "[ TAB ] HIDE MENU");
	mlx_string_put(mlx, win, 12, 90, C_MENU_TXT, "/ KEYBOARD CONTROLS /");
	mlx_string_put(mlx, win, 12, 120, C_FRONT, "[ 1 ] ISOMETRIC VIEW");
	mlx_string_put(mlx, win, 12, 140, C_FRONT, "[ 2 ] DIMETRIC VIEW");
	mlx_string_put(mlx, win, 12, 160, C_FRONT, "[ 3 ] PERSPECTIVE VIEW");
	mlx_string_put(mlx, win, 12, 180, C_FRONT, "[ 4 ] TOP VIEW");
	mlx_string_put(mlx, win, 12, 200, C_FRONT, "[ R ] RESET CURRENT VIEW");
	mlx_string_put(mlx, win, 12, 230, C_FRONT, "[ ARROW KEYS ] MOVE");
	mlx_string_put(mlx, win, 12, 250, C_FRONT, "[ A ] [ D ] X ROTATE");
	mlx_string_put(mlx, win, 12, 270, C_FRONT, "[ W ] [ S ] Y ROTATE");
	mlx_string_put(mlx, win, 12, 290, C_FRONT, "[ Q ] [ E ] Z ROTATE");
	mlx_string_put(mlx, win, 12, 320, C_FRONT, "[ + ] [ - ] ZOOM");
	mlx_string_put(mlx, win, 12, 340, C_FRONT, "[ Z ] [ X ] Z SCALE");
	mlx_string_put(mlx, win, 12, 370, C_FRONT, "[ ESC ] QUIT");
	mlx_string_put(mlx, win, 12, 410, C_MENU_TXT, "/ MOUSE CONTROLS /");
	mlx_string_put(mlx, win, 12, 440, C_FRONT, "[ LEFT BTN ] MOVE");
	mlx_string_put(mlx, win, 12, 460, C_FRONT, "[ RIGHT BTN ] ROTATE X/Y");
	mlx_string_put(mlx, win, 12, 480, C_FRONT, "[ WHEEL BTN ] ROTATE Z");
	mlx_string_put(mlx, win, 12, 510, C_FRONT, "[ WHEEL ] ZOOM");
	mlx_string_put(mlx, win, 12, 530, C_FRONT, "[ WHEEL + CTRL ] Z SCALE");
}
