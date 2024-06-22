# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 17:37:50 by rbouizer          #+#    #+#              #
#    Updated: 2024/01/07 16:46:32 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= ft_printf.c \
	ft_putadresse.c \
	ft_putchar.c \
	ft_putnbr_hex.c \
	ft_putstr.c

OBJS = $(SRCS:.c=.o)

AR =ar rc

LIBRARY = ft_printf.h

CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o : %.c $(LIBRARY)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all