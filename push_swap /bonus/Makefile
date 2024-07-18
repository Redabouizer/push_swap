# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 01:54:53 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/18 18:30:23 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= get_next_line/get_next_line.c\
	get_next_line/get_next_line.c\
	libft/ft_split.c\
	libft/ft_strlen.c\
	libft/ft_strlcpy.c\
	libft/ft_atoi.c\
	libft/ft_strchr.c\
	libft/ft_strdup.c\
	libft/ft_strjoin.c\
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
	ft_check.c

OBJS = $(SRCS:.c=.o)

AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
NAME = checker
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

re: clean all