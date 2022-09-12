/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:22:49 by kichlee           #+#    #+#             */
/*   Updated: 2022/09/12 19:58:20 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**init_room(void)
{
	int	**room;
	int	i;
	int	j;

	room = (int **) malloc(sizeof(int *) * 4);
	if (room == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		room[i] = (int *) malloc(sizeof(int) * 4);
		if (room[i] == 0)
			return (0);
		i++;
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			room[i][j] = 0;
	}
	return (room);
}

void	free_room(int **room)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(room[i]);
		i++;
	}
	free(room);
}

int	is_blank(char ch)
{
	if (ch == '\n' || ch == '\t' || ch == '\v' \
			|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

int	is_valid_view(char *view)
{
	int	i;
	int	num;
	int	was_space;

	i = 0;
	num = 0;
	was_space = 1;
	while (view[i] != '\0')
	{
		if (is_blank(view[i]) == 1)
			was_space++;
		else if (view[i] >= '1' && view[i] <= '4' && was_space >= 1)
		{
			was_space = 0;
			num++;
		}
		else
			return (0);
		i++;
	}
	if (num == 16)
		return (1);
	else
		return (0);
}

int	init_view(int *list, char *view)
{
	int	i;
	int	valid;

	i = 0;
	valid = is_valid_view(view);
	if (valid == 0)
		return (0);
	else
	{
		while (*view != '\0')
		{
			if (*view >= '1' && *view <= '4')
			{
				list[i] = *view - '0';
				i++;
			}
			view++;
		}
		return (1);
	}
}
