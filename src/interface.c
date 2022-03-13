/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:55:13 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 13:03:42 by dchaves-         ###   ########.fr       */
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

	status_bar.color = COLOR_STATUS_BAR;
	status_bar.height = 30;
	status_bar.width = WINDOW_WIDTH;
	status_bar.x = 0;
	status_bar.y = WINDOW_HEIGHT - status_bar.height;
	plot_rectangle(&fdf->display->img, status_bar);
}

static void	info_menu(t_fdf *fdf)
{
	t_rect	info_menu;

	info_menu.color = COLOR_MENU_BTN;
	info_menu.height = 28;
	info_menu.width = 160;
	info_menu.x = 0;
	info_menu.y = 20;
	plot_rectangle(&fdf->display->img, info_menu);
}

static void	info_menu_txt(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	int		y;

	mlx = fdf->display->mlx_ptr;
	win = fdf->display->win_ptr;
	y = 38;
	if (fdf->menu) {
		mlx_string_put(mlx,win,12,y,COLOR_FRONT,"[ TAB ] HIDE MENU");
		mlx_string_put(mlx,win,12,y+50,COLOR_MENU_TXT,"/ KEYBOARD CONTROLS /");
		mlx_string_put(mlx,win,12,y+80,COLOR_FRONT,"[ ESC ] QUIT");
		mlx_string_put(mlx,win,12,y+110,COLOR_FRONT,"[ ARROW KEYS ] MOVE");
		mlx_string_put(mlx,win,12,y+130,COLOR_FRONT,"[ A ] [ D ] X ROTATE");
		mlx_string_put(mlx,win,12,y+150,COLOR_FRONT,"[ W ] [ S ] Y ROTATE");
		mlx_string_put(mlx,win,12,y+170,COLOR_FRONT,"[ Q ] [ E ] Z ROTATE");
		mlx_string_put(mlx,win,12,y+190,COLOR_FRONT,"[ + ] [ - ] ZOOM");
		mlx_string_put(mlx,win,12,y+220,COLOR_FRONT,"[ R ] RESET CURRENT VIEW");
		mlx_string_put(mlx,win,12,y+240,COLOR_FRONT,"[ T ] TOP VIEW");
		mlx_string_put(mlx,win,12,y+260,COLOR_FRONT,"[ I ] ISOMETRIC VIEW");
		mlx_string_put(mlx,win,12,y+280,COLOR_FRONT,"[ P ] PERSPECTIVE VIEW");
		mlx_string_put(mlx,win,12,y+330,COLOR_MENU_TXT,"/ MOUSE CONTROLS /");
		mlx_string_put(mlx,win,12,y+360,COLOR_FRONT,"[ WHEEL ] ZOOM");
		mlx_string_put(mlx,win,12,y+380,COLOR_FRONT,"[ LEFT CLICK ] MOVE");
		mlx_string_put(mlx,win,12,y+400,COLOR_FRONT,"[ RIGHT CLICK ] ROTATE X/Y");
		mlx_string_put(mlx,win,12,y+420,COLOR_FRONT,"[ WHEEL CLICK ] ROTATE Z");
	}
	else
		mlx_string_put(mlx,win,12,y,COLOR_FRONT,"[ TAB ] SHOW MENU");
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
	mlx_string_put(mlx,win,10,y,COLOR_TXT,"SCALE:");
	txt = ft_itoa(fdf->data->scale);
	mlx_string_put(mlx,win,50,y,COLOR_TXT,txt);
	free(txt);
	mlx_string_put(mlx,win,90,y,COLOR_TXT,"X OFFSET:");
	txt = ft_itoa(fdf->data->x_move);
	mlx_string_put(mlx,win,150,y,COLOR_TXT,txt);
	free(txt);
	mlx_string_put(mlx,win,190,y,COLOR_TXT,"Y OFFSET:");
	txt = ft_itoa(fdf->data->y_move);
	mlx_string_put(mlx,win,250,y,COLOR_TXT,txt);
	free(txt);
	mlx_string_put(mlx,win,290,y,COLOR_TXT,"X ROTATE:");
	txt = ft_itoa(fdf->data->x_angle / ANG_1);
	mlx_string_put(mlx,win,350,y,COLOR_TXT,txt); 
	free(txt);
	mlx_string_put(mlx,win,390,y,COLOR_TXT,"Y ROTATE:");
	txt = ft_itoa(fdf->data->y_angle / ANG_1);
	mlx_string_put(mlx,win,450,y,COLOR_TXT,txt);
	free(txt);	
	mlx_string_put(mlx,win,490,y,COLOR_TXT,"Z ROTATE:");
	txt = ft_itoa(fdf->data->z_angle / ANG_1);
	mlx_string_put(mlx,win,550,y,COLOR_TXT,txt);
	free(txt);
	mlx_string_put(mlx,win,1160,y,COLOR_TXT,"X:");
	txt = ft_itoa(fdf->mouse->x);
	mlx_string_put(mlx,win,1180,y,COLOR_TXT,txt);
	free(txt);	
	mlx_string_put(mlx,win,1220,y,COLOR_TXT,"Y:");
	txt = ft_itoa(fdf->mouse->y);
	mlx_string_put(mlx,win,1240,y,COLOR_TXT,txt);
	free(txt);		
}
