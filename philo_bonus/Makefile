# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 10:31:51 by javrodri          #+#    #+#              #
#    Updated: 2021/07/05 12:08:03 by javrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus	

SRCS	=	philo_bonus.c \
			utils.c		\
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
