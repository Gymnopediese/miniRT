# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 18:46:11 by albaud            #+#    #+#              #
#    Updated: 2022/12/11 21:36:42 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= v_add.c v_angle.c v_average.c v_dist.c v_div.c v_dotp.c v_equal.c v_mult.c v_norme.c v_null.c v_ponline.c v_rm.c v_tocol.c v_unit.c v_v3mult.c
OBJS 	= ${SRCS:.c=.o}
NAME 	= vlib.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		: fclean all

c		:
		find *.c */*.c | tr '\n' ' '

push	:
		git add *
		git commit -m save
		git push
