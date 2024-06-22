# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 17:11:58 by rbouizer          #+#    #+#              #
#    Updated: 2024/06/21 13:43:09 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_memset.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_strcmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c 

SRCS_B = ft_lstnew_bonus.c \
		 ft_lstadd_front_bonus.c \
		 ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c \
		 ft_lstadd_back_bonus.c \
		 ft_lstdelone_bonus.c \
		 ft_lstclear_bonus.c \
		 ft_lstiter_bonus.c \
		 ft_lstmap_bonus.c

OBJS_B = ${SRCS_B:.c=.o}

OBJS = ${SRCS:.c=.o}


CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	cc $(CFLAGS) -c $< 

bonus: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all bonus

.PHONY: clean