/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:53:46 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/05 17:13:36 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char ch)
{
	write (1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	ch;

	i = 0;
	while (str[i])
	{
		ch = str[i];
		if (ch < ' ' || ch > '~')
		{
			ft_putchar2('\\');
			ft_putchar2("0123456789abcdef"[ch / 16]);
			ft_putchar2("0123456789abcdef"[ch % 16]);
		}
		else
			ft_putchar2(ch);
		i++;
	}
}
