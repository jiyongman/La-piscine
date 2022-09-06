/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:57:03 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/06 12:55:07 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

void	ft_address(unsigned long long addr, unsigned int cnt, char *hex)
{
	if (addr != 0)
	{
		ft_address(addr / 16, cnt + 1, hex);
		ft_putchar(hex[addr % 16]);
	}
	else
	{
		while (cnt < 16)
		{
			ft_putchar('0');
			cnt++;
		}
	}
}

void	ft_hex(unsigned char *addr, unsigned int size, char *hex)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_putchar(hex[addr[i] / 16]);
		ft_putchar(hex[addr[i] % 16]);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		write (1, "  ", 2);
		i++;
	}
}

void	ft_str(unsigned char *addr, unsigned int size, char *str)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (addr[i] >= ' ' && addr[i] <= '~')
			str[i] = addr[i];
		else
			str[i] = '.';
		ft_putchar(str[i]);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*hex;
	unsigned int	tmp;
	char			str[16];

	i = 0;
	hex = "0123456789abcdef";
	while (size > 0)
	{
		if (size > 16)
			tmp = 16;
		else
			tmp = size;
		ft_address((unsigned long long)addr + i, 0, hex);
		ft_putchar(':');
		ft_hex((unsigned char *)addr + i, tmp, hex);
		ft_putchar(' ');
		ft_str((unsigned char *)addr + i, tmp, str);
		ft_putchar('\n');
		size -= tmp;
		i += 16;
	}
	return (addr);
}
