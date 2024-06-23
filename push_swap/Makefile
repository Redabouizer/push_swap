# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 17:37:50 by rbouizer          #+#    #+#              #
#    Updated: 2024/06/23 19:36:24 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_tokens.c \
	ft_lstnew_bonus.c \
	ft_atoi.c \
	ft_lstadd_back_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstclear_bonus.c \
	ft_number.c \
	ft_language.c \
	ft_lstclear_bonus.c \
	ft_lstlast_bonus.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_split.c \
	ft_lstdelone_bonus.c
	

OBJS = $(SRCS:.c=.o)

AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
LIB = push_swap.a

all : $(NAME)

$(LIB) : $(OBJS)
	$(AR) $(LIB) $(OBJS)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) ft_sort.c $(LIB) ft_printf/libftprintf.a

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(LIB) $(NAME)

re: clean all clean

do: all clean
