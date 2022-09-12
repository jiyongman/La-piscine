/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:17:59 by jiyochoi          #+#    #+#             */
/*   Updated: 2022/09/07 13:45:23 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

int	main(int argc, char *argv[])
{
	int	j;

	j = 0;
	if (argc == 1)
	{
		while (argv[0][j])
		{
			ft_putchar(argv[0][j]);
			j++;
		}
		ft_putchar('\n');
	}
}
