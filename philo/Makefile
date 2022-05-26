.PHONY :	re fclean clean all print_header print_bottom

P_INC		:=	includes/
P_SRCS		:=	sources/
P_OBJS		:=	.objects/

HEADER		=	${P_INC}philosophers.h		\
				${P_INC}struct.h			\
				${P_INC}error_msg.h

LST_SRCS	=	action.c					\
				eat.c						\
				fill_data.c					\
				fork.c						\
				ft_atoi.c					\
				ft_error.c					\
				main.c						\
				mutex_init.c				\
				philo_entry.c				\
				philo_init.c				\
				start_philo.c				\
				timestamp.c		

LST_OBJS	=	${LST_SRCS:.c=.o}
SRCS		=	$(addprefix ${P_SRCS},${LST_SRCS})
OBJS		=	$(addprefix ${P_OBJS},${LST_OBJS})
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		= 	philo
RM			=	rm -rf
USAGE		=	$(BLUE)$(BOLD)Usage : ./${NAME} <Number_of_philo> <Time_to_eat> <Time_to_sleep> $(RESET)$(FAINT)*$(RESET)$(BLUE)$(BOLD)<Number_of_time_philo_has_to_eat> $(RESET)

#///////////////////////////////////////////////////////////////////////////////

# Colors
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

# Text
ERASE		=	\033[2K\r
RESET		=	\033[0m
BOLD		=	\033[1m
FAINT		=	\033[2m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m

BBLU 		=	\033[1;34m
BGREEN		=	\033[1;32m
BRED		=	\033[1;31m
BLU 		=	\033[0;34m
MGT			=	\033[0;35m
LMGT		=	\033[0;95m
LBLU 		=	\033[0;96m
GRN 		=	\033[0;32m
RED 		=	\033[0;31m
GRY 		=	\033[0;90m
RST 		=	\033[0m
#///////////////////////////////////////////////////////////////////////////////


all: print_header ${NAME} usage print_bottom

${NAME} : $(P_OBJS) $(OBJS) ${HEADER}
	@${CC} ${CFLAGS} ${OBJS} -o $(NAME) 
	@printf "\n$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)	✅"

$(P_OBJS)%.o: ${P_SRCS}%.c $(HEADER) Makefile | $(P_OBJS)
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$(FAINT)$(CC) $(CFLAGS) -c -o $(RESET)$(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

$(P_OBJS):
	@mkdir -p $(P_OBJS)
	@printf "$(GREEN)$(BOLD)${NAME} objects directories created$(RESET)	✅\n\n"

print_header:
	@echo "${GRY}====================================================================${RESET}\n"
	@echo " ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄   ▄▄▄▄▄▄▄ "
	@echo "█       █  █ █  █   █   █   █       █       █       █       █  █ █  █       █   ▄  █ █       █"
	@echo "█    ▄  █  █▄█  █   █   █   █   ▄   █  ▄▄▄▄▄█   ▄   █    ▄  █  █▄█  █    ▄▄▄█  █ █ █ █  ▄▄▄▄▄█"
	@echo "█   █▄█ █       █   █   █   █  █ █  █ █▄▄▄▄▄█  █ █  █   █▄█ █       █   █▄▄▄█   █▄▄█▄█ █▄▄▄▄▄ "
	@echo "█    ▄▄▄█   ▄   █   █   █▄▄▄█  █▄█  █▄▄▄▄▄  █  █▄█  █    ▄▄▄█   ▄   █    ▄▄▄█    ▄▄  █▄▄▄▄▄  █"
	@echo "█   █   █  █ █  █   █       █       █▄▄▄▄▄█ █       █   █   █  █ █  █   █▄▄▄█   █  █ █▄▄▄▄▄█ █"
	@echo "█▄▄▄█   █▄▄█ █▄▄█▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█   █▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄█  █▄█▄▄▄▄▄▄▄█"
	@echo "\n${GRY}====================================================================${RESET}\n"

usage:
	@printf "$(USAGE)"
	@printf "\n$(FAINT)$(BOLD)*: Optional $(RESET)\n"

print_bottom:
	@echo "\n${GRY}=================================================${RESET}\n"
	@echo " ▄   ▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄    ▄ "
	@echo "█ █ █   █       █   █   █  █ █  █       █  █  █ █"
	@echo "█ █▄█   █▄▄▄▄   █   █   █  █▄█  █   ▄   █   █▄█ █"
	@echo "█       █▄▄▄▄█  █   █   █       █  █ █  █       █"
	@echo "█▄▄▄    █ ▄▄▄▄▄▄█   █▄▄▄█▄     ▄█  █▄█  █  ▄    █"
	@echo "    █   █ █▄▄▄▄▄█       █ █   █ █       █ █ █   █"
	@echo "    █▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄█  █▄▄█"
	@echo "\n${GRY}==================>${RESET} By ${LMGT}dvilard${RESET} ${GRY}<=================${RESET}\n"

clean :
	@${RM} ${OBJS}
	@${RM} ${P_OBJS}
	@printf "$(YELLOW)$(BOLD)All ${NAME} object files removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)All ${NAME} object folders removed$(RESET)\n"

fclean :
	@${MAKE} clean
	@${RM} ${NAME} 
	@printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"

re :
	@${MAKE} fclean
	@${MAKE} all