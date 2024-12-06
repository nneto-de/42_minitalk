# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 14:01:20 by nneto-de          #+#    #+#              #
#    Updated: 2023/08/01 15:35:24 by nneto-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

all:	${OBJS_SERVER} ${OBJS_CLIENT}
		${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}
		${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}

client: ${OBJS_CLIENT}
		${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}

server: ${OBJS_SERVER}
		${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}

clean:
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER} 

fclean: clean
			${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all client server clean fclean re bonus