/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:41:28 by semilee           #+#    #+#             */
/*   Updated: 2022/09/11 17:42:34 by semilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

char	**ft_split2(char *str, char *charset)
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
	return (arr);
}
