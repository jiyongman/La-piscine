/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:18:39 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 10:45:14 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	delete_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	str[i] = '\0';
}

void	printer(int total_line, int line_len, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < total_line)
	{
		while (j < line_len)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

void	put_str(int len, char *file_path, char **str)
{
	int		fd;
	int		i;
	char	ch;

	i = 0;
	fd = open(file_path, O_RDONLY);
	*str = malloc(sizeof(char) * (len + 1));
	while (read(fd, &ch, 1))
		(*str)[i++] = ch;
	(*str)[i] = '\0';
}

void	set_fd(int *fd, char *file_path)
{
	char	ch;

	*fd = open(file_path, O_RDONLY);
	while (read(*fd, &ch, 1))
	{
		if (ch == '\n')
			break ;
	}
}

int	check_total_line(int i, int total_line, int fd, char *str)
{
	if (i != total_line)
	{
		free(str);
		close(fd);
		return (-1);
	}
	return (0);
}
