# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 10:31:51 by javrodri          #+#    #+#              #
#    Updated: 2021/04/07 09:13:25 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_one	

SRCS	=	philo_one.c \
			utils.c		\
			initialize.c\
			print.c		\
			routine.c	\
			routine2.c


OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I.

LIBS	=	-lpthread

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean	:
		@/bin/rm -f $(OBJS)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
