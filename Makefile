# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2022/12/09 13:08:44 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
MAIN 		= main.c
OBJS		= ${MAIN:.c=.o}

LIB 		= koflibc/libft.a
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= -I /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include -I  /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${LIB} ${OBJS}
		${CC} ${CFLAGS} ${MINILIBX} -o ${NAME} ${OBJS} ${LIB}

$(LIB)	: 
		make -C koflibc

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
