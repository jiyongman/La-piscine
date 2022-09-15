/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:05:13 by semilee           #+#    #+#             */
/*   Updated: 2022/09/13 14:58:44 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long long	long_atoi(char *str)
{
	long long	result;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!double_sign(str[i]))
		return (0);
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		return (-1);
	return (sign * result);
}

int	double_sign(char str)
{
	if (str == '-' || str == '+')
		return (-1);
	return (1);
}
