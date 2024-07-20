# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 01:57:16 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/20 05:54:24 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/utils/ft_split.c\
	mandatory/utils/ft_strlen.c\
	mandatory/utils/ft_strlcpy.c\
	mandatory/utils/ft_atoi.c\
	mandatory/utils/ft_lstsize_bonus.c\
	mandatory/utils/ft_lstnew_bonus.c\
	mandatory/utils/ft_lstlast_bonus.c\
	mandatory/utils/ft_lstadd_back_bonus.c\
	mandatory/ft_tokens.c\
	mandatory/ft_number.c\
	mandatory/ft_helps.c\
	mandatory/ft_lang_swap.c\
	mandatory/ft_lang_push.c\
	mandatory/ft_lang_rotate.c\
	mandatory/ft_lang_reverse_rotate.c\
	mandatory/ft_sort_mt.c\
	mandatory/ft_sort.c\
	mandatory/push_swap.c

B_SRCS = bonus/ft_check.c\
	  bonus/ft_helps.c\
	  bonus/ft_lang_push.c\
	  bonus/ft_lang_reverse_rotate.c\
	  bonus/ft_lang_rotate.c\
	  bonus/ft_lang_swap.c\
	  bonus/ft_number.c\
	  bonus/ft_tokens.c\
	  bonus/push_swap.c\
	  bonus/get_next_line/get_next_line.c\
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
CC = cc
RM = rm -f

NAME = push_swap
B_NAME = checker

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS)

bonus/%.o: bonus/%.c bonus/push_swap_bonus.h bonus/get_next_line/get_next_line.h  bonus/utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

mandatory/%.o: mandatory/%.c mandatory/push_swap.h mandatory/utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all