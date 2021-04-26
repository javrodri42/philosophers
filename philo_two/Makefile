# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 10:31:51 by javrodri          #+#    #+#              #
#    Updated: 2021/04/26 13:41:46 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_two	

SRCS	=	philo_two.c \
			utils.c		\
			utils2.c	\
			initialize.c\
			routine.c	\
			routine2.c	\
			semaphore.c


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
