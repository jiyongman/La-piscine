/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semilee <semilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:36:48 by semilee           #+#    #+#             */
/*   Updated: 2022/09/13 14:57:30 by jiyochoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_fair
{
	char	*key;
	char	*value;
}t_fair;

char			**ft_split(char *str, char *charset, int *judge);
char			**ft_split2(char *str, char *charset);
void			split_words(char **arr, char *str, char *charset);
int				count_word(char *str, char *charset);
int				ft_atoi(char *str);
int				check_charset(char *str, char *charset);
char			*word_add(char *arr, char *str, char *charset);
void			putstr(char *str);
void			convert(t_fair *fair, char *num, int len);
void			judge_first(char **str, int word, int *judge);
void			str_strcpy(char *dest, char *src);
unsigned int	my_pow(int x, int y);
int				zero_print(char *num, int length, t_fair *fair);
unsigned int	get_digit(int length, int j);
char			*get_temp(char *num, int i, int digit);
void			find_first(char *temp, t_fair *fair, int i, int len);
void			find_second(t_fair *fair, unsigned int digit, int len);
int				ft_strlen(char *str);
int				str_len_dubble(char **str);
int				ft_strcmp(char *s1, char *s2);
int				len(long nb);
int				double_sign(char str);
char			*ft_itoa(unsigned int nb);
char			*rev_num(char *arr);
char			*ltrim(char *str);
char			*trim(char *str);
char			*rtrim(char *str);
t_fair			*fair_init(char **dic, int *len_out);
long long		long_atoi(char *str);
int				check_all_zero(char *num);
void			check1(char **str, int *judge, int word);
void			check2(char **str, int *judge, int word, int i);
void			check3(char **str, int *judge, int word, int i);
void			go_free(t_fair *fair, int *len);
void			dic_free(char **dic, int *len);
void			temp_free(char *temp, char *num);

#endif
