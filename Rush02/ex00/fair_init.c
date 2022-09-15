/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fair_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:23:34 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 22:10:03 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	str_len_dubble(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

t_fair	*fair_init(char **dic, int *len_out)
{
	int		len;
	t_fair	*fair;
	char	**temp;
	char	*temp_free;

	len = 0;
	*len_out = str_len_dubble(dic);
	fair = (t_fair *)malloc(sizeof(t_fair) * (*len_out));
	if (!fair)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	while (dic[len])
	{
		temp = ft_split2(dic[len], ":");
		fair[len].key = temp[0];
		temp_free = temp[1];
		fair[len].value = trim(temp[1]);
		free(temp_free);
		len++;
	}
	return (fair);
}

int	ft_atoi(char *str)
{
	int	answer;
	int	i;
	int	sign;

	answer = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		answer *= 10;
		answer += str[i] - '0';
		i++;
	}
	return (sign * answer);
}
