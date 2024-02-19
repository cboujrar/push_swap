NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDATORY = algorithm.c checker.c helpers.c list_operations.c operations.c  push_swap.c
	
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