/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:20:34 by gyoon             #+#    #+#             */
/*   Updated: 2022/05/28 21:29:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_unique(int **room);
int	is_answer(int **room, int *view);

int	solve(int **room, int *view, int solved)
{
	int	ret;
	int	i;

	ret = 0;
	i = 1;
	if (solved == 16)
	{
		ret = is_answer(room, view);
		return (ret);
	}
	while (i <= 4)
	{
		room[solved / 4][solved % 4] = i;
		if (is_unique(room) == 1)
		{
			ret = solve(room, view, solved + 1);
			if (ret == 1)
				break ;
		}
		room[solved / 4][solved % 4] = 0;
		i++;
	}
	return (ret);
}
