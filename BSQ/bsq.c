/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:51:44 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 11:43:26 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_all(int total_line, char *symbols, char **map)
{
	int	i;

	i = 0;
	while (i <= total_line)
	{
		free(map[i++]);
	}
	free(map);
	free(symbols);
}

void	search(char *file_path)
{
	int		i;
	int		total_line;
	int		line_len;
	char	*symbols;
	char	**map;

	symbols = 0;
	if (info_check(file_path) == -1
		|| get_info(&total_line, &line_len, file_path, &symbols)
		|| symbol_check(symbols))
		return ;
	i = 0;
	map = malloc(sizeof(char *) * (total_line + 1));
	if (cpy_map(total_line, line_len, map, file_path) == -1
		|| get_answer(total_line, line_len, symbols, map) == -1)
	{
		write(1, "map error\n", 10);
		free_all(total_line, symbols, map);
		return ;
	}
	printer(total_line, line_len, map);
	free_all(total_line, symbols, map);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	ch;

	i = 0;
	if (argc == 1)
	{
		fd = open("hello.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
		while (read(0, &ch, 1))
			write(fd, &ch, 1);
		search("hello.txt");
		close(fd);
	}
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "map error\n", 10);
			close(fd);
			continue ;
		}
		close(fd);
		search(argv[i]);
	}
}
