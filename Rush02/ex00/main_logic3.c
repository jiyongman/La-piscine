/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:13:08 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 23:32:39 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_all_zero(char *num)
{
	while (*num)
	{
		if (*num != '0')
			return (0);
		num++;
	}
	return (1);
}

void	convert(t_fair *fair, char *num, int len)
{
	int					i;
	int					j;
	unsigned int		digit;
	char				*temp;

	i = zero_print(num, ft_strlen(num), fair);
	j = i;
	while (num[i] && j <= ft_strlen(num))
	{
		digit = get_digit(ft_strlen(num), ++j);
		temp = get_temp(num, i, digit);
		if (temp[0] != '0' && !((ft_strlen(num) - j) % 3 == 0
				&& i - 1 >= 0 && num[i - 1] == '1'))
			find_first(temp, fair, i, len);
		if (digit != 10 && i + 1 < ft_strlen(num)
			&& !(temp[0] == '0' && (!((ft_strlen(num) - j) % 3 == 0))))
		{
			if (temp[0] == '0' && check_all_zero(&num[i])
				&& num[i - 1] == '0' && num[i - 2] == '0')
				break ;
			find_second(fair, digit, len);
		}
		i++;
	}
	temp_free(temp, num);
}
