#include "../inc/fdf.h"

void	free_map(t_map *map);

static int	get_map_columns(char const *s, char c)
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

static void	check_map(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	// TODO: check opened file
	printf("fd: %d\n", fd);

	map->rows = 0;
	map->columns = 0;

	while(1)
	{
		// TODO: check if each line has the same number of elements
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		map->columns = get_map_columns(line, ' ');
		printf("%s", line);
		free(line);
	}
	close(fd);
}

static void	load_map(t_map *map, char *argv)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**z;

	fd = open(argv, O_RDONLY);
	// TODO: check opened file	

	printf("LOAD_MAP: %p | %s\n", map, argv);

	i = 0;
	j = 0;
	map->vectors = malloc(map->rows * sizeof(t_vec3 *));
	while (i < map->rows)
	{
		line = get_next_line(fd);
		z = ft_split(line, ' ');
		map->vectors[i] = malloc(map->columns * sizeof(t_vec3));
		while (j < map->columns)
		{
			map->vectors[i][j].x = i;
			map->vectors[i][j].y = j;
			map->vectors[i][j].z = ft_atoi(z[j]);
			j++;
		}
		i++;
		j = 0;
		free(line);
		while(z[j])
		{
			free(z[j]);
			j++;
		}
		free(z);
		j = 0;
	}
	line = get_next_line(fd); // needed to free the GNL buffer
	close(fd);
}

t_map	*read_map(int argc, char **argv)
{
	t_map	*map;

	printf("argc: %d | argv[0]: %s | argv[1]: %s\n", argc, argv[0], argv[1]);
	// TODO: check_args();

	map = malloc(sizeof(t_map));
	// TODO: check malloc

	check_map(map, argv[1]);

	printf("map.rows: %d\n", map->rows);
	printf("map.columns: %d\n", map->columns);

	load_map(map, argv[1]);

	return(map);
}

void	free_map(t_map *map)
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

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n\nt_map\n");
	while (i < map->rows)
	{
		while (j < map->columns)
		{
			printf("%2d ", map->vectors[i][j].z);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
}
