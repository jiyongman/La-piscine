/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:08:03 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 23:37:25 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned int	my_pow(int x, int y)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 1;
	if (y == 0)
		return (1);
	while (i++ < y)
		result *= x;
	return (result);
}

int	zero_print(char *num, int length, t_fair *fair)
{
	int	count;
	int	i;

	i = 0;
	while (fair[0].value[i])
		i++;
	count = 0;
	while (num[count] == '0')
		count++;
	if (length == count)
		write(1, fair[0].value, i);
	return (count);
}

unsigned int	get_digit(int length, int j)
{
	unsigned int	digit;

	if ((length - j) % 3 == 0)
		digit = my_pow(10, length - j);
	else
		digit = my_pow(10, ((length - j) % 3));
	return (digit);
}

char	*get_temp(char *num, int i, int digit)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * 3);
	if (digit == 10)
	{
		if (num[i] == '1')
		{
			temp[0] = num[i++];
			temp[1] = num[i];
			temp[2] = 0;
			i--;
		}
		else
		{
			temp[0] = num[i];
			temp[1] = '0';
			temp[2] = 0;
		}
	}
	else
	{
		temp[0] = num[i];
		temp[1] = 0;
	}
	return (temp);
}

void	find_first(char *temp, t_fair *fair, int i, int len)
{
	int	k;

	k = -1;
	while (++k < len)
	{
		if (ft_strcmp(temp, fair[k].key) == 0)
		{
			if (i != 0)
				write(1, " ", 1);
			putstr(fair[k].value);
			break ;
		}
	}
}
