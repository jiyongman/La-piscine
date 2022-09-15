/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:03:37 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 11:42:43 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	info_check(char *file_path)
{
	int		fd;
	int		len;
	int		line_break;
	char	ch;

	len = 0;
	line_break = -1;
	fd = open(file_path, O_RDONLY);
	while (read(fd, &ch, 1))
	{
		len++;
		if (line_break == -1 && ch == '\n')
			line_break = len;
	}
	close(fd);
	if (line_break < 5)
	{
		write(1, "map error\n", 10);
		return (-1);
	}
	return (len);
}

int	total_len_check(int *info_len, int total_len, char *str)
{
	int	cnt_n;

	*info_len = 1;
	cnt_n = 0;
	while (*str != '\n')
	{
		str++;
		(*info_len)++;
	}
	while (*str)
	{
		str++;
		if (*str == '\n')
			cnt_n++;
	}
	if (cnt_n == total_len)
		return (0);
	return (1);
}

int	line_len_check(int line_len, char *symbols, char *str)
{
	int	cnt;

	cnt = -1;
	while (*str != '\n')
		str++;
	str++;
	while (*str)
	{
		cnt++;
		if (*str != symbols[0] && *str != symbols[1]
			&& *str != symbols[2] && *str != '\n')
			return (1);
		if (*str == '\n')
		{
			if (cnt != line_len)
				return (1);
			cnt = -1;
		}
		str++;
	}
	return (0);
}

int	symbol_check(char *symbols)
{
	if (symbols[0] == symbols[1]
		|| symbols[0] == symbols[2]
		|| symbols[2] == symbols[1]
		|| (symbols[0] < 32 || symbols[0] > 126)
		|| (symbols[1] < 32 || symbols[1] > 126)
		|| (symbols[2] < 32 || symbols[2] > 126))
	{
		write(1, "map error\n", 10);
		free(symbols);
		return (1);
	}
	return (0);
}

int	check_file(int total_len, int line_len, char *symbols, char *file_path)
{
	int		len;
	int		info_len;
	char	*str;

	len = info_check(file_path);
	put_str(len, file_path, &str);
	if (total_len_check(&info_len, total_len, str)
		|| line_len_check(line_len, symbols, str)
		|| symbol_check(symbols)
		|| (len - info_len) != total_len * line_len + total_len)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	return (0);
}
