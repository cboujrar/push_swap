NAME = pushswap.a
BNAME = checker.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDATORY = push_to_b_1.c helpers.c parsing1.c list_operations.c operations.c  push_swap.c\
			list_operations_2.c ft_split.c operations_2.c push_back_to_a.c push_to_b_2.c\
			parsing2.c
BONUS  = bonus/get_next_line.c bonus/get_next_line_utils.c bonus/checker.c bonus/helpers_bonus.c bonus/operations_bonus1.c\
			bonus/operations_bonus2.c  parsing1.c parsing2.c helpers.c list_operations.c list_operations_2.c ft_split.c
			
	
MANDATORY_O = ${MANDATORY:.c=.o}
BONUS_O = ${BONUS:.c=.o}
.o:.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${MANDATORY_O}
	${LIBC} ${NAME} ${MANDATORY_O}

${BNAME}: ${BONUS_O}
	${LIBC} ${BNAME} ${BONUS_O}

all: ${NAME}

bonus: ${BNAME}

clean:
	${RM} ${MANDATORY_O} ${BONUS_O}

fclean: clean
	${RM} ${NAME} ${BNAME}

re: fclean all