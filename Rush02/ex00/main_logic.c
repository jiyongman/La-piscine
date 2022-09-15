/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subcho <subcho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:07:26 by subcho            #+#    #+#             */
/*   Updated: 2022/09/11 22:13:46 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	find_second(t_fair *fair, unsigned int digit, int len)
{
	int	k;

	k = -1;
	while (++k < len)
	{
		if (ft_strcmp(ft_itoa(digit), fair[k].key) == 0)
		{
			write(1, " ", 1);
			putstr(fair[k].value);
			break ;
		}
	}
}

void	putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s2++;
		s1++;
	}
	return (0);
}
