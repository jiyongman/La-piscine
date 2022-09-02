/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhan2 <jhan2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:11:45 by jhan2             #+#    #+#             */
/*   Updated: 2022/09/02 20:35:52 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch);

void	ft_put_nline(void)
{
	write(1, "\n", 1);
}

void	ft_first_line(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i == x -1)
			ft_putchar('C');
		else
			ft_putchar('B');
		i++;
	}
	ft_put_nline();
}

void	ft_middle_line(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y - 2)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || i == x -1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_put_nline();
		j++;
	}
}

void	ft_last_line(int x, int y)
{
	int	i;

	i = 0;
	if (y > 1)
	{
		while (i < x)
		{
			if (i == 0)
				ft_putchar('C');
			else if (i == x -1)
				ft_putchar('A');
			else
				ft_putchar('B');
			i++;
		}
		ft_put_nline();
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_first_line (x);
		ft_middle_line (x, y);
		ft_last_line (x, y);
	}
}
