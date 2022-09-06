/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:44:24 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 14:53:49 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			cnt++;
		i++;
	}
	if (i == cnt || str[0] == '\0')
		return (1);
	else
		return (0);
}
