/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:51:00 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 23:21:28 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	go_free(t_fair *fair, int *len)
{
	int	i;
	int	temp;

	temp = *len;
	i = 0;
	if (fair != 0)
		free(fair);
}

void	dic_free(char **dic, int *len)
{
	int	i;
	int	temp;

	i = 0;
	temp = *len;
	while (dic[i] != 0)
	{
		free(dic[i]);
		i++;
	}
	if (dic != 0)
		free(dic);
}

void	temp_free(char *temp, char *num)
{
	if (*num != '0')
	{
		free(temp);
	}
}
