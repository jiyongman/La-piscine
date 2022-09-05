/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:32:04 by gyoon             #+#    #+#             */
/*   Updated: 2022/05/29 18:44:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_unique_row(int **room)
{
	int	x;
	int	y;
	int	check[4];

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
			check[x++] = 0;
		x = 0;
		while (x < 4)
		{
			if (room[y][x] > 0)
				check[room[y][x] - 1]++;
			x++;
		}
		x = 0;
		while (x < 4)
			if (check[x++] > 1)
				return (0);
		y++;
	}
	return (1);
}

int	is_unique_col(int **room)
{
	int	x;
	int	y;
	int	check[4];

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
			check[y++] = 0;
		y = 0;
		while (y < 4)
		{
			if (room[y][x] > 0)
				check[room[y][x] - 1]++;
			y++;
		}
		y = 0;
		while (y < 4)
			if (check[y++] > 1)
				return (0);
		x++;
	}
	return (1);
}

int	is_unique(int **room)
{
	int	check_row;
	int	check_col;

	check_row = is_unique_row(room);
	check_col = is_unique_col(room);
	if (check_row == 1 && check_col == 1)
		return (1);
	else
		return (0);
}
