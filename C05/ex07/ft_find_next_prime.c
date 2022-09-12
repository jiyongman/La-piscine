/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:14:51 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/12 13:28:08 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime2(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb <= 3)
		return (1);
	else
	{
		while (i <= nb / i)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime2(nb) == 0)
		nb++;
	return (nb);
}
