/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:52:23 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:59:46 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	map_get_info(t_map *map, char *argv);
static int	map_get_columns(t_map *map, char const *s, char c);
static void	map_load(t_map *map, char *argv);
static void	map_get_data(t_map *map, char *line, int line_num);

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
	int		line_num;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line_num = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_get_data(map, line, line_num);
		line_num++;
		free(line);
	}
	close(fd);
}

static void	map_get_data(t_map *map, char *line, int line_num)
{
	int		col_num;
	char	**data;

	data = ft_split(line, ' ');
	col_num = 0;
	while (col_num < map->columns)
	{
		map->vectors[line_num][col_num].z = ft_atoi(data[col_num]);
		map->vectors[line_num][col_num].color = get_map_color(data[col_num]);
		if (map->vectors[line_num][col_num].z > map->z_max)
			map->z_max = map->vectors[line_num][col_num].z;
		if (map->vectors[line_num][col_num].z < map->z_min)
			map->z_min = map->vectors[line_num][col_num].z;
		col_num++;
	}
	col_num = 0;
	while (data[col_num])
	{
		free(data[col_num]);
		col_num++;
	}
	free(data);
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
		return (1);
	map->columns = count;
	return (0);
}
