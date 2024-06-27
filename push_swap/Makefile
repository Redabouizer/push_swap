# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 17:37:50 by rbouizer          #+#    #+#              #
#    Updated: 2024/06/27 22:39:19 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_printf/ft_printf.c \
	ft_printf/ft_putadresse.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_putnbr_hex.c \
	ft_printf/ft_putstr.c \
	libft/ft_split.c\
	libft/ft_strlen.c\
	libft/ft_strlcpy.c\
	libft/ft_atoi.c\
	libft/ft_lstsize_bonus.c\
	libft/ft_lstnew_bonus.c\
	libft/ft_lstlast_bonus.c\
	libft/ft_lstadd_back_bonus.c\
	libft/ft_lstdelone_bonus.c\
	libft/ft_lstclear_bonus.c\
	ft_tokens.c \
	ft_number.c \
	ft_language.c \
	ft_sort.c 
	

OBJS = $(SRCS:.c=.o)

AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
LIB = push_swap.a

all : $(NAME)

$(LIB) : $(OBJS)
	$(AR) $(LIB) $(OBJS)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) ft_sort.c $(LIB)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(LIB)

fclean : clean
	$(RM) $(LIB) $(NAME)

re: clean all clean

do: all clean
