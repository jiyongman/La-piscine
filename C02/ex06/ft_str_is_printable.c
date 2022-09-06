/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:48:48 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 14:54:12 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			cnt++;
		i++;
	}
	if (i == cnt || str[0] == '\0')
		return (1);
	else
		return (0);
}
