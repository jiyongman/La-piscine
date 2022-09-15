/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:30:30 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 21:58:49 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

char	*rtrim(char	*str)
{
	char	*t;
	char	*end;

	t = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(t, str);
	end = t + ft_strlen(t) - 1;
	while (end != t && *end == ' ')
		end--;
	*(end + 1) = '\0';
	str = t;
	return (str);
}

char	*ltrim(char *str)
{
	char	*begin;

	begin = str;
	while (*begin != '\0')
	{
		if (*begin == ' ')
			begin++;
		else
		{
			str = begin;
			break ;
		}
	}
	return (str);
}

char	*trim(char *str)
{
	return (rtrim(ltrim(str)));
}
