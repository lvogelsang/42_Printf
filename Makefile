# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:28:32 by lvogelsa          #+#    #+#              #
#    Updated: 2022/10/15 13:45:59 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f

SRCS = ft_format.c \ft_format_adjustment.c \ft_format_default.c \ft_print_chars.c \
	ft_print_nbrs.c \ft_printf.c

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all
