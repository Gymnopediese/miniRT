# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2022/12/16 10:27:04 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
MAIN 		= dammier.c disperse.c main.c ray_tracing.c uvmapping.c background/gradient.c parser/atoi_life.c parser/init_objs.c parser/init_shapes.c parser/init_shapes_2.c parser/parser.c parser/parser_utils.c shapes/cone.c shapes/cylindre.c shapes/hyperboloid.c shapes/hyperboloid2.c shapes/matrix.c shapes/paraboloid.c shapes/paraboloid2.c shapes/plan.c shapes/sphere.c utils/debug.c utils/errors.c utils/inputs.c utils/iterate_objects.c utils/v_utils.c
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
		find *.c */*.c | grep -v *vectors* | grep -v *minilibx_macos* | tr '\n' ' ' 

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