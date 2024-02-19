NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDATORY = 
	
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