/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:52:23 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 20:24:16 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	map_check(t_map *map, char *argv);
static void	map_load(t_map *map, char *argv);
static int	map_get_columns(char const *s, char c);

t_map	*map_init(int argc, char **argv)
{
	t_map	*map;

	// TODO: better check_args();
	if (argc != 2)
		return(0);

	map = malloc(sizeof(t_map));
	if (!map)
		return(NULL);

	map->name = argv[1];
	map_check(map, argv[1]);
	map_load(map, argv[1]);
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
	// TODO: check opened file

	map->rows = 0;
	map->columns = 0;

	while(1)
	{
		// TODO: check if each line has the same number of elements
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		map->columns = map_get_columns(line, ' ');
		free(line);
	}
	close(fd);
}

static void	map_load(t_map *map, char *argv)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**z;

	fd = open(argv, O_RDONLY);
	// TODO: check opened file	

	y = 0;
	map->vectors = malloc(map->rows * sizeof(t_vec3 *));
	while (y < map->rows)
	{
		line = get_next_line(fd);
		z = ft_split(line, ' ');
		map->vectors[y] = malloc(map->columns * sizeof(t_vec3));
		x = 0;
		while (x < map->columns)
		{
			map->vectors[y][x].x = x - map->columns / 2;
			map->vectors[y][x].y = y - map->rows / 2;
			map->vectors[y][x].z = ft_atoi(z[x]);
			x++;
		}
		y++;
		x = 0;
		free(line);
		while(z[x])
		{
			free(z[x]);
			x++;
		}
		free(z);
	}
	line = get_next_line(fd); // needed to free the GNL buffer
	close(fd);
}

static int	map_get_columns(char const *s, char c)
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
	return (count);
}
