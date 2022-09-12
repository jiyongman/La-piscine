/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:16:27 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:14:10 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

int	ft_check(int arr[], int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[i] == arr[j])
			return (0);
		else if (i - j == arr[i] - arr[j] || i - j == arr[j] - arr[i])
			return (0);
		j++;
	}
	return (1);
}

void	ft_print(int arr[])
{
	int		i;
	char	ch;

	i = 0;
	while (i < 10)
	{
		ch = arr[i] + '0';
		ft_putchar(ch);
		i++;
	}
	ft_putchar('\n');
}

void	ft_recursive(int arr[], int *cnt, int i, int j)
{
	if (i == 10)
	{
		ft_print(arr);
		(*cnt)++;
		return ;
	}
	while (j < 10)
	{
		arr[i] = j;
		if (ft_check(arr, i))
			ft_recursive(arr, cnt, i + 1, 0);
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	cnt;

	cnt = 0;
	ft_recursive(arr, &cnt, 0, 0);
	return (cnt);
}
