# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 17:37:50 by rbouizer          #+#    #+#              #
#    Updated: 2024/06/22 01:00:30 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_tokens.c \
	ft_number.c \
	ft_language.c 

OBJS = $(SRCS:.c=.o)

AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
LIB = push_swap.a

all : $(NAME)

$(LIB) : $(OBJS)
	$(AR) $(LIB) $(OBJS)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) push_swap.c $(LIB) libft/libft.a ft_printf/libftprintf.a

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(LIB) $(NAME)

re: fclean all
