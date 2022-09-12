/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:51:18 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:42:23 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_valid(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
			return (1);
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_baselen(base);
	if (ft_valid(base) == 1)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_check_base(str[i], base) != -1)
	{
		result = result * base_len + ft_check_base(str[i], base);
		i++;
	}
	return (sign * result);
}
