/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:15:56 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 22:53:16 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	judge_first(char **str, int word, int *judge)
{
	int	i;
	int	j;
	int	colon;
	int	*temp;

	temp = judge;
	colon = 0;
	i = 0;
	j = 0;
	check1 (str, judge, word);
	check2 (str, temp, word, i);
	check3 (str, judge, word, i);
}

void	check1(char **str, int *judge, int word)
{
	int	i;
	int	colon;
	int	j;

	i = 0;
	colon = 0;
	j = 0;
	while (i < word)
	{
		while (str[i][j])
		{
			if (j == 0 && !(str[i][j] >= '0' && str[i][j] <= '9'))
				*judge = -1;
			if (str[i][j + 1] != '\0' && str[i][j] == ':'
			&& str[i][j + 1] == ' ')
				colon ++;
			if (!(str[i][j] >= 32 && str[i][j] <= 126))
				*judge = -1;
			j++;
		}
		i++;
		j = 0;
	}
	if (colon != word)
		*judge = -1;
}

void	check2(char **str, int *judge, int word, int i)
{
	int	flag;
	int	j;

	j = 0;
	flag = 0;
	while (i < word)
	{
		while (str[i][j])
		{
			if (str[i][j] == ':')
				flag = 1;
			if (flag == 1)
				return ;
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
			{
				if (str[i][j] != ' ')
				{
					*judge = -1;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	check3(char **str, int *judge, int word, int i)
{
	int	flag;
	int	j;

	j = 0;
	flag = 0;
	while (i < word)
	{
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				flag = 1;
			if (flag == 1 && (str[i][j] != ' '))
			{
					*judge = -1;
			}
			j++;
			if (str[i][j] == ':')
				return ;
		}
		i++;
		j = 0;
	}
}
