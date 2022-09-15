/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:35:59 by semilee           #+#    #+#             */
/*   Updated: 2022/09/13 14:57:04 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_dic(char *strs)
{
	int		fd;
	int		len;
	char	buf[30000];
	char	**dic;
	t_fair	*fair;

	len = 1;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		write(2, "Error\n", 6);
	read(fd, buf, 30000);
	dic = ft_split(buf, "\n", &len);
	if (len == -1)
	{
		dic_free(dic, &len);
		write(1, "Dict Error\n", 11);
		return ;
	}
	fair = fair_init(dic, &len);
	dic_free(dic, &len);
	convert(fair, strs, len);
	close(fd);
	go_free(fair, &len);
}

void	print_dic2(char *strs, char *argv)
{
	int		fd;
	int		len;
	char	buf[30000];
	char	**dic;
	t_fair	*fair;

	len = 1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		write(2, "Error\n", 6);
	read(fd, buf, 30000);
	dic = ft_split(buf, "\n", &len);
	if (len == -1)
	{
		dic_free(dic, &len);
		write(1, "Dict Error\n", 11);
		return ;
	}
	fair = fair_init(dic, &len);
	dic_free(dic, &len);
	convert(fair, strs, len);
	close(fd);
	go_free(fair, &len);
}

int	check_input_value(char *str)
{
	long long	value;

	value = 0;
	value = long_atoi(str);
	if (value < 0 || value > 4294967295)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 3 || argc == 1)
		write (2, "Error\n", 6);
	else if (argc == 2)
	{
		if (!check_input_value(argv[1]) || long_atoi(argv[1]) == -1)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		argv[1] = ft_itoa(long_atoi(argv[1]));
		print_dic(argv[1]);
		write(1, "\n", 1);
	}
	else if (argc == 3)
	{
		if (!check_input_value(argv[2]) || long_atoi(argv[2]) == -1)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		argv[2] = ft_itoa(long_atoi(argv[2]));
		print_dic2(argv[2], argv[1]);
		write(1, "\n", 1);
	}	
	return (0);
}
