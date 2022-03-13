/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:52:23 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 03:59:56 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	map_check(t_map *map, char *argv);
static void	map_load(t_map *map, char *argv);
static int	map_get_columns(char const *s, char c, int col_count);

t_map	*map_init(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error(ERROR_ARGC);
	map = malloc(sizeof(t_map));
	if (!map)
		error(ERROR_MALLOC);
	map->name = argv[1];
	printf("\033[1;32m\n   Loading map...\033[0m\n");
	map_check(map, argv[1]);
	map_load(map, argv[1]);
	printf("\033[1;32m   [ok]\033[0m\n\n");
	return(map);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->vectors[i]);
		i++;
	}
	free(map->vectors);
}

static void	map_check(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (!fd)
		error(ERROR_OPEN);
	map->rows = 0;
	map->columns = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		map->columns = map_get_columns(line, ' ', map->columns);
		free(line);
	}
	close(fd);
	if (map->rows == 0 || map->columns == 0)
		error(ERROR_MAP);
}

static int	map_get_columns(char const *s, char c, int col_count)
{
	size_t	flag;
	int		count;

	flag = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	if (col_count != 0 && col_count != count)
		error(ERROR_MAP);
	return (count);
}

int	get_map_color(char *str)
{
	int		color;

	str = ft_strchr(str, ',');
	if (!str)
		return (COLOR_GREEN);
	++str;
	color = ft_atoi_base(str, HEX_BASE);
	return(color);
}

static void	map_load(t_map *map, char *argv)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**z;

	fd = open(argv, O_RDONLY);
	y = 0;
	map->vectors = malloc(map->rows * sizeof(t_vec *));
	while (y < map->rows)
	{
		map->vectors[y] = malloc(map->columns * sizeof(t_vec));
		line = get_next_line(fd);
		z = ft_split(line, ' ');
		x = 0;
		while (x < map->columns)
		{
			map->vectors[y][x].x = x - map->columns / 2;
			map->vectors[y][x].y = y - map->rows / 2;
			map->vectors[y][x].z = ft_atoi(z[x]);
			map->vectors[y][x].color = get_map_color(z[x]);
			x++;
		}
		y++;
		x = 0;
		free(line);
		/*
		while(z[x])
		{
			free(z[x]);
			x++;
		}
		free(z);
		*/
	}
	line = get_next_line(fd); // needed to free the GNL buffer
	close(fd);
}
