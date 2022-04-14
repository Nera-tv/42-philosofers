LST_SRCS	=	action.c			\
				eat.c				\
				fill_data.c			\
				fork.c				\
				ft_atoi.c			\
				ft_error.c			\
				main.c				\
				mutex_init.c		\
				philo_entry.c		\
				philo_init.c		\
				start_philo.c		\
				timestamp.c		

LST_OBJS	=	${LST_SRCS:.c=.o}
SRCS		=	$(addprefix sources/,${LST_SRCS})
OBJS		=	$(addprefix .objects/,${LST_OBJS})
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		= 	philo
HEADER		=	includes/philosophers.h
HEADER_STR	=	includes/struct.h
HEADER_ERR	=	includes/error_msg.h
RM			=	rm -rf
INC			=	-I includes/

.objects/%.o: sources/%.c $(HEADER) $(HEADER_ERR) $(HEADER_STR)
	mkdir -p .objects
	${CC} ${CFLAGS} -I includes/ -c $< -o $@

${NAME} :	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o $(NAME) 

all: ${NAME}

clean :
	${RM} .objects

fclean :	clean
	${RM} ${NAME} 

re :		fclean all

.PHONY :	re fclean clean all