# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyochoi <jiyochoi@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:03:18 by jiyochoi          #+#    #+#              #
#    Updated: 2022/09/11 22:12:50 by semilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = rush-02
SRCS = fair_init.c \
       free.c \
       ft_split.c \
       ft_split2.c \
       itoa.c \
       judge.c \
       long_atoi.c \
       main.c \
       main_logic.c \
       main_logic2.c \
	   main_logic3.c \
       trim.c
		
INCLUDES = rush02.h
OBJS = $(SRCS:.c=.o)
rm = rm -f
all : $(TARGET)
.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o
fclean: clean
	rm $(TARGET)
re: fclean all
.PHONY: all clean fclean re
