/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:25:23 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 11:41:14 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (-1);
		}
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	get_info_len(char *file_path)
{
	int		fd;
	int		len;
	char	ch;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit (-1);
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
			break ;
		len++;
	}
	close(fd);
	return (len);
}

int	get_normal_len(char *file_path)
{
	int		fd;
	int		n_count;
	int		line_count;
	char	ch;

	n_count = 0;
	line_count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit (-1);
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
			n_count++;
		if (n_count == 1 && ch != '\n')
			line_count++;
		if (n_count > 1)
			break ;
	}
	close (fd);
	return (line_count);
}

int	get_info(int *total_line, int *line_len, char *file_path, char **symbols)
{
	int		fd;
	int		i;
	int		info_len;
	char	*str;

	i = 0;
	info_len = get_info_len(file_path);
	*line_len = get_normal_len(file_path);
	str = malloc(sizeof(char *) * (info_len - 3 + 1));
	*symbols = malloc(sizeof(char) * 4);
	fd = open(file_path, O_RDONLY);
	str[info_len - 3] = '\0';
	read (fd, str, info_len - 3);
	read (fd, *symbols, 3);
	close(fd);
	*total_line = ft_atoi(str);
	if (ft_atoi(str) == -1 || *total_line == 0)
	{
		free(str);
		free(*symbols);
		write(1, "map error\n", 10);
		return (-1);
	}
	free(str);
	return (0);
}
