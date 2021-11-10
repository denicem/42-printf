# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 02:35:37 by dmontema          #+#    #+#              #
#    Updated: 2021/11/10 17:57:57 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
HEADERFILES		=	./ft_printf.h

FT_PRINTF_SRCS	=	ft_printf.c ft_printers.c ft_helpers.c

FT_PRINTF_OBJS	=	$(FT_PRINTF_SRCS:.c=.o)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rc

all:	$(NAME)

$(NAME):	$(FT_PRINTF_OBJS)
	$(AR) $(NAME) $(FT_PRINTF_OBJS)

bonus: all

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:	
	rm -f $(FT_PRINTF_OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all