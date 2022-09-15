/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:21:24 by jukim2            #+#    #+#             */
/*   Updated: 2022/09/15 11:42:24 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int				info_check(char *file_path);
void			put_str(int len, char *file_path, char **str);
int				total_len_check(int *info_len, int total_len, char *str);
int				line_len_check(int line_len, char *symbols, char *str);
int				check_file(int total_len, int line_len, char *symbols,
					char *file_path);
int				symbol_check(char *symbols);
int				get_info(int *total_line, int *map_size, char *file_path,
					char **symbols);
int				get_normal_len(char *file_path);
int				get_info_len(char *file_path);
int				ft_atoi(char *str);
void			set_map(char **map, char *file_path);
int				get_answer(int total_line, int line_len, char *symbols,
					char **map);
void			add_padding(int total_line, int line_len, int **map);
int				to_int(int line_len, int **map_int, char *symbols,
					char **map);
int				cpy_map(int total_line, int line_len, char **map,
					char *file_path);
int				*solve(int total_line, int line_len, int *answer,
					int **map_int);
int				update(int i, int j, int **map);
void			patch(char **map, char *symbols, int answer[3]);
void			delete_n(char *str);
void			printer(int total_line, int line_len, char **map);
void			put_str(int len, char *file_path, char **str);
void			set_fd(int *fd, char *file_path);
int				check_total_line(int i, int total_line, int fd, char *str);

#endif