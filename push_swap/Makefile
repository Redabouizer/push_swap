# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 18:01:49 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/06 02:58:09 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= libft/ft_split.c\
	libft/ft_strlen.c\
	libft/ft_strlcpy.c\
	libft/ft_atoi.c\
	libft/ft_lstsize_bonus.c\
	libft/ft_lstnew_bonus.c\
	libft/ft_lstlast_bonus.c\
	libft/ft_lstadd_back_bonus.c\
	ft_tokens.c \
	ft_number.c \
	ft_helps.c \
	ft_lang_swap.c \
	ft_lang_push.c \
	ft_lang_rotate.c \
	ft_lang_reverse_rotate.c \
	ft_sort_mt.c \
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
	$(CC) $(CFLAGS) -o $(NAME) push_swap.c $(LIB)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(LIB)

fclean : clean
	$(RM) $(LIB) $(NAME)

re: clean all clean

do: all clean