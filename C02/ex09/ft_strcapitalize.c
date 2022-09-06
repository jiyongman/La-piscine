/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:51:04 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:37 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	ft_strlowcase(str);
	while (str[i])
	{
		if ((str[i - 1] < 'a' || str[i - 1] > 'z')
			&& (str[i - 1] < 'A' || str[i - 1] > 'Z')
			&& (str[i - 1] < '0' || str[i - 1] > '9')
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 32;
		i++;
	}
	return (str);
}
