NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDATORY = push_to_b_1.c checker.c helpers.c list_operations.c operations.c  push_swap.c\
			list_operations_2.c ft_split.c operations_2.c push_back_to_a.c push_to_b_2.c
	
MANDATORY_O = ${MANDATORY:.c=.o}
.o:.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${MANDATORY_O}
	${LIBC} ${NAME} ${MANDATORY_O}

all: ${NAME}

clean:
	${RM} ${MANDATORY_O}

fclean: clean
	${RM} ${NAME} 

re: fclean all