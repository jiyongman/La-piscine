/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:41:45 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 20:13:13 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_charset(char *str, char *charset)
{
	while (*charset && *str)
	{
		if (*charset == *str)
			return (1);
		charset++;
	}
	return (0);
}

char	*word_add(char *arr, char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!(check_charset(str, charset)) && *str != '\0')
	{
		i++;
		str++;
	}
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (0);
	arr[0] = 0;
	str = str - i;
	while (j < i)
	{
		arr[j] = *str;
		j++;
		str++;
	}
	arr[j] = 0;
	return (arr);
}

int	count_word(char *str, char *charset)
{
	int	word_count;
	int	len;

	len = 0;
	word_count = 0;
	while (*str)
	{
		while (check_charset(str, charset) && *str != '\0')
			str++;
		if (*str == '\0')
			break ;
		word_count++;
		while (!(check_charset(str, charset)) && *str != '\0')
			str++;
	}
	return (word_count);
}

void	split_words(char **arr, char *str, char *charset)
{
	int	index;
	int	len;

	len = 0;
	index = 0;
	while (*str)
	{
		while (check_charset(str, charset) && *str != '\0')
			str++;
		if (*str != '\0')
		{
			arr[index] = word_add(arr[index], str, charset);
			index++;
		}
		while (!(check_charset(str, charset)) && *str != '\0')
			str++;
	}
}

char	**ft_split(char *str, char *charset, int *judge)
{
	int		word;
	char	**arr;

	word = count_word(str, charset);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	arr[0] = 0;
	if (!arr)
		return (NULL);
	split_words(arr, str, charset);
	arr[word] = 0;
	judge_first (arr, word, judge);
	return (arr);
}
