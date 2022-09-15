/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:00:58 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 15:02:04 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		j = size - 1 - i;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
	}
}
