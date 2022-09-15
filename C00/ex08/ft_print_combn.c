/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:01:13 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/08 21:54:35 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(char *str, int i, int num, int n)
{
	if (i == n)
	{
		write (1, str, n);
		if (str[0] != '9' - n + 1)
		{
			write (1, ", ", 2);
		}
		return ;
	}
	while (num + '0' <= '9' - n + i + 1)
	{
		str[i] = num + '0';
		ft_recursive(str, i + 1, num + 1, n);
		num++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_recursive(arr, 0, 0, n);
}
