/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:45:24 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 14:53:58 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cnt++;
		i++;
	}
	if (i == cnt || str[0] == '\0')
		return (1);
	else
		return (0);
}
