/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:01:13 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/08/30 00:14:04 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(char *str, int idx, int num, int n);

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_recursive(arr, 0, 0, n);
}

void	ft_recursive(char *str, int idx, int num, int n)
{
	if (idx == n)
	{
		write (1, str, n);
		if (str[0] != '9' - n + 1)
		{
			write (1, ", ", 2);
		}
		return ;
	}
	while (num + '0' <= '9' - n + idx + 1)
	{
		str[idx] = num + '0';
		ft_recursive(str, idx + 1, num + 1, n);
		num++;
	}
}
