# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/12/12 12:22:28 by albaud           ###   ########.fr        #
=======
#    Updated: 2022/12/12 14:02:31 by bphilago         ###   ########.fr        #
>>>>>>> acd9356d16ff4b7667baf1770e07518279c59d86
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
<<<<<<< HEAD
MAIN 		= dammier.c main.c ray_tracing.c uvmapping.c background/gradient.c parser/atoi_life.c parser/init_objs.c parser/init_shapes.c parser/parser.c parser/parser_utils.c shapes/sphere.c utils/debug.c utils/errors.c utils/inputs.c utils/iterate_objects.c utils/v_utils.c
=======
MAIN 		= dammier.c main.c uvmapping.c background/gradient.c parser/atoi_life.c\
				parser/init_objs.c parser/init_shapes.c parser/parser.c parser/parser_utils.c\
				shapes/sphere.c utils/debug.c utils/errors.c utils/inputs.c utils/iterate_objects.c\
				utils/v_utils.c disperse.c
>>>>>>> acd9356d16ff4b7667baf1770e07518279c59d86
OBJS		= ${MAIN:.c=.o}
LIB 		= koflibc/libft.a vectors/vlib.a
CC			= /usr/bin/gcc -g
CFLAGS		= -Wall -Wextra -Werror
FRAMEWORK	= -framework OpenGL -framework AppKit
LIBS		= -Lminilibx_macos -lmlx -Lkoflibc -lft
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} -Iminilibx_macos -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${OBJS}
		make -C koflibc
		make -C vectors
		${CC} ${CFLAGS} ${LIBS} ${FRAMEWORK} -o ${NAME} ${OBJS} ${LIB}

c		:
		find *.c */*.c | grep -v *vectors*| tr '\n' ' ' 

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME} 
re:		fclean all

lclean	: fclean
		rm -f ${LIB}
relib	: lclean all

leak	: fclean ${LIB}
		${CC} ${CFLAGS} ${SANITIZE} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

run		: all
		./miniRT rt_files/test.rt