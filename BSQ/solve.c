/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:38:43 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/14 22:35:02 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	update(int i, int j, int **map)
{
	char	value;

	if (map[i][j] == 0)
		return (0);
	value = map[i - 1][j - 1] + 1;
	if (value > map[i - 1][j] + 1)
		value = map[i - 1][j] + 1;
	if (value > map[i][j - 1] + 1)
		value = map[i][j - 1] + 1;
	map[i][j] = value;
	return (value);
}

int	*solve(int total_line, int line_len, int *answer, int **map_int)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 1;
	(answer)[2] = 0;
	while (i <= total_line)
	{
		while (j <= line_len)
		{
			size = update(i, j, map_int);
			if (size > answer[2])
			{
				(answer)[2] = size;
				(answer)[0] = i - 1;
				(answer)[1] = j - 1;
			}
			j++;
		}
		i++;
		j = 1;
	}
	return (answer);
}

void	patch(char **map, char *symbols, int answer[3])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < answer[2])
	{
		while (j < answer[2])
		{
			map[answer[0] - i][answer[1] - j] = symbols[2];
			j++;
		}
		i++;
		j = 0;
	}
}
