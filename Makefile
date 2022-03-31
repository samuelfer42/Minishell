# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safernan <safernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 00:28:15 by safernan          #+#    #+#              #
#    Updated: 2022/03/31 03:23:21 by safernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INCLUDES = ./include

SRC = 	srcs/minishell.c 	\
		srcs/libft.c 		\
		srcs/list.c

FLAGS = -lreadline

CC = gcc $(FLAGS)


OBJ = $(SRC:.c=.o)

.PHONY: all re clean fclean 

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L $(INCLUDES) $(FLAGS) 
	@printf "\n\e[36msuccessfully\e[0m_\e[33m compiled \e[92mis ready !\e[0m\e[?25h\n"

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@
	@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

clean:
	@$(RM) -f $(OBJ)
	@printf "All object files [\033[31mX\033[0m]\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "$(NAME) [\033[31mX\033[0m]\n"

re : fclean all