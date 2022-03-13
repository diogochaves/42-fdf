/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:52:23 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/13 23:13:52 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	map_get_info(t_map *map, char *argv);
static int	map_get_columns(t_map *map, char const *s, char c);
static void	map_load(t_map *map, char *argv);

t_vec **vectors_malloc(t_map *map)
{
	t_vec	**vectors;
	int		y;
	int		x;

	vectors = malloc(map->rows * sizeof(t_vec *));
	if (!vectors)
		return (NULL);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		vectors[y] = malloc(map->columns * sizeof(t_vec));
		while (x < map->columns)
		{
			vectors[y][x].x = x - map->columns / 2;
			vectors[y][x].y = y - map->rows / 2;
			vectors[y][x].z = 0;
			vectors[y][x].color = C_FRONT;
			x++;
		}
		y++;
	}
	return (vectors);
}

t_map	*map_init(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		error(ERROR_ARGC);
	map = malloc(sizeof(t_map));
	if (!map)
		error(ERROR_MALLOC);
	map_get_info(map, argv[1]);
	map->vectors = vectors_malloc(map);
	printf("\033[1;32m\n   Loading map...\033[0m\n");
	map_load(map, argv[1]);
	printf("\033[1;32m   [ok]\033[0m\n\n");
	return (map);
}

static void	map_get_info(t_map *map, char *argv)
{
	int		fd;
	int		col_count_error;
	char	*line;

	map->z_max = 0;
	map->z_min = 0;
	map->rows = 0;
	map->columns = 0;
	col_count_error = 0;
	fd = open(argv, O_RDONLY);
	if (!fd)
		error(ERROR_OPEN);	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		col_count_error = map_get_columns(map, line, ' ');
		free(line);
	}
	close(fd);
	if (map->rows == 0 || map->columns == 0 || col_count_error)
		error(ERROR_MAP);
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		z = ft_split(line, ' ');
		x = 0;
		while (x < map->columns)
		{
			map->vectors[y][x].z = ft_atoi(z[x]);
			map->vectors[y][x].color = get_map_color(z[x]);
			if (map->vectors[y][x].z > map->z_max)
				map->z_max = map->vectors[y][x].z;
			if (map->vectors[y][x].z < map->z_min)
				map->z_min = map->vectors[y][x].z;
			x++;
		}
		y++;
		x = 0;
		free(line);
		while (z[x])
		{
			free(z[x]);
			x++;
		}
		free(z);
	}
	close(fd);
}

static int	map_get_columns(t_map *map, char const *s, char c)
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
	if (map->columns != 0 && map->columns != count)
		return(1);
	map->columns = count;
	return (0);
}
