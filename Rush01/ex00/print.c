/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:23:18 by kichlee           #+#    #+#             */
/*   Updated: 2022/09/04 21:23:21 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_room(int **room)
{
	int	x;
	int	y;

	y = 0;
	if (room[0][0] == 0)
	{
		print_error();
		return ;
	}
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar('0' + room[y][x]);
			if (x != 3)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
