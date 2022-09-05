/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:00:57 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/04 22:43:48 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_unique(int **room);

int	match_col_up(int **room, int *view)
{
	int	x;
	int	y;
	int	v;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 0;
		v = 0;
		before = 0;
		while (y < 4)
		{
			if (room[y][x] > before)
			{
				before = room[y][x];
				v++;
			}
			y++;
		}
		if (v != view[x])
			return (0);
		x++;
	}
	return (1);
}

int	match_col_down(int **room, int *view)
{
	int	x;
	int	y;
	int	v;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 3;
		v = 0;
		before = 0;
		while (y >= 0)
		{
			if (room[y][x] > before)
			{
				before = room[y][x];
				v++;
			}
			y--;
		}
		if (v != view[x + 4])
			return (0);
		x++;
	}
	return (1);
}

int	match_row_left(int **room, int *view)
{
	int	x;
	int	y;
	int	v;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 0;
		v = 0;
		before = 0;
		while (x < 4)
		{
			if (room[y][x] > before)
			{
				before = room[y][x];
				v++;
			}
			x++;
		}
		if (v != view[y + 8])
			return (0);
		y++;
	}
	return (1);
}

int	match_row_right(int **room, int *view)
{
	int	x;
	int	y;
	int	v;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 3;
		v = 0;
		before = 0;
		while (x >= 0)
		{
			if (room[y][x] > before)
			{
				before = room[y][x];
				v++;
			}
			x--;
		}
		if (v != view[y + 12])
			return (0);
		y++;
	}
	return (1);
}

int	is_answer(int **room, int *view)
{
	int	check_up;
	int	check_down;
	int	check_left;
	int	check_right;

	if (is_unique(room) != 1)
		return (0);
	check_up = match_col_up(room, view);
	check_down = match_col_down(room, view);
	check_left = match_row_left(room, view);
	check_right = match_row_right(room, view);
	if (check_up == 1 && check_down == 1 && check_left == 1 && check_right == 1)
		return (1);
	else
		return (0);
}
