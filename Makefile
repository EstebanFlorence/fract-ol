# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 19:11:52 by adi-nata          #+#    #+#              #
#    Updated: 2023/04/25 19:16:39 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	fractol.c

OBJS	=	$(addprefix obj/,$(notdir $(SRCS:.c=.o)))

CC		=	gcc

RM		=	rm -rf

FLAGS	=	-g -Wall -Wextra -Werror -Ilibft

LIB		=	libft

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m

${NAME}:	objs ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(LIB) ${CLR_RMV}..."
			@make -C ./libft
			@echo "$(GREEN)$(LIB) created[0m ✔️"

			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${FLAGS} ${OBJS} -L./libft -lft -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

obj/%.o:	%.c
			@${CC} ${FLAGS} -c $< -o $@

objs:
			@mkdir -p obj

clean:
			@ echo "$(RED)Deleting $(CYAN)$(LIB) $(CLR_RMV)libft objs ✔️"
			@make clean -C ./libft

			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@${RM} -r obj


fclean:		clean
			@ echo "$(RED)Deleting $(CYAN)$(LIB) $(CLR_RMV)binary ✔️"
			@make fclean -C ./libft

			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@${RM} ${NAME}


re:			fclean all

.PHONY:		all clean fclean re
