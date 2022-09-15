/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 10:49:37 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cpy_map(int total_line, int line_len, char **map, char *file_path)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (line_len + 1));
	set_fd(&fd, file_path);
	while (read(fd, str, line_len + 1))
	{
		map[i] = str;
		if (map[i][line_len] != '\n')
		{
			close(fd);
			return (-1);
		}
		map[i++][line_len] = '\0';
		str = malloc(sizeof(char) * (line_len + 1));
	}
	if (check_total_line(i, total_line, fd, str) == -1)
		return (-1);
	free(str);
	close(fd);
	map[i] = 0;
	return (0);
}

int	to_int(int line_len, int **map_int, char *symbols, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == symbols[0])
				map_int[i + 1][j + 1] = 1;
			else if (map[i][j] == symbols[1])
				map_int[i + 1][j + 1] = 0;
			else if (map[i][j] != symbols[0] && map[i][j] != symbols[1]
				&& j != line_len)
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	free_map_int(int total_line, int **map_int)
{
	int	i;

	i = 0;
	while (i <= total_line)
		free(map_int[i++]);
	free(map_int);
}

int	get_answer(int total_line, int line_len, char *symbols, char **map)
{
	int	i;
	int	*answer;
	int	**map_int;

	i = 0;
	answer = malloc(sizeof(int) * 3);
	map_int = malloc(sizeof(int *) * (total_line + 1));
	while (i <= total_line)
		map_int[i++] = malloc(sizeof(int) * (line_len + 1));
	if (to_int(line_len, map_int, symbols, map) == -1)
		return (-1);
	add_padding(total_line, line_len, map_int);
	solve(total_line, line_len, answer, map_int);
	patch(map, symbols, answer);
	free_map_int(total_line, map_int);
	free(answer);
	return (0);
}

void	add_padding(int total_line, int line_len, int **map)
{
	int	i;
	int	j;

	j = 0;
	while (j <= line_len)
		map[0][j++] = 0;
	i = 1;
	j = 0;
	while (i <= total_line)
	{
		map[i++][0] = 0;
	}
}
