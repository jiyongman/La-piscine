/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:47:10 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 14:54:04 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cnt++;
		i++;
	}
	if (i == cnt || str[0] == '\0')
		return (1);
	else
		return (0);
}
