# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 01:57:16 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/19 05:48:17 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = utils/ft_split.c\
       utils/ft_strlen.c\
       utils/ft_strlcpy.c\
       utils/ft_atoi.c\
       utils/ft_lstsize_bonus.c\
       utils/ft_lstnew_bonus.c\
       utils/ft_lstlast_bonus.c\
       utils/ft_lstadd_back_bonus.c\
       ft_tokens.c\
       ft_number.c\
       ft_helps.c\
       ft_lang_swap.c\
       ft_lang_push.c\
       ft_lang_rotate.c\
       ft_lang_reverse_rotate.c\
       ft_sort_mt.c\
       ft_sort.c\
       push_swap.c

B_SRCS = bonus/ft_check.c\
         bonus/ft_helps.c\
         bonus/ft_lang_push.c\
         bonus/ft_lang_reverse_rotate.c\
         bonus/ft_lang_rotate.c\
         bonus/ft_lang_swap.c\
         bonus/ft_number.c\
         bonus/ft_tokens.c\
         bonus/get_next_line/get_next_line.c\
         bonus/push_swap.c\
         bonus/utils/ft_atoi.c\
         bonus/utils/ft_lstadd_back_bonus.c\
         bonus/utils/ft_lstlast_bonus.c\
         bonus/utils/ft_lstnew_bonus.c\
         bonus/utils/ft_lstsize_bonus.c\
         bonus/utils/ft_split.c\
         bonus/utils/ft_strchr.c\
         bonus/utils/ft_strdup.c\
         bonus/utils/ft_strjoin.c\
         bonus/utils/ft_strlcpy.c\
         bonus/utils/ft_strlen.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

NAME = push_swap
B_NAME = checker

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS)

%.o: %.c push_swap.h utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/get_next_line/get_next_line.h bonus/push_swap_bonus.h bonus/utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all