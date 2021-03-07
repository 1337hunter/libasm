# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbright <gbright@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 12:57:11 by gbright           #+#    #+#              #
#    Updated: 2020/07/14 15:45:21 by gbright          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ./ft_strlen.s ./ft_write.s ./ft_read.s ./ft_strcpy.s ./ft_strcmp.s		\
	   ./ft_strdup.s

BONUS = ./ft_atoi_base.s ./ft_list_push_front.s ./ft_list_size.s ft_list_sort.s\
		./ft_list_remove_if.s

OBJ = $(SRCS:.s=.o)
BOBJ = $(BONUS:.s=.o)

all: $(NAME)

%.o: %.s
	nasm -f elf64 $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

main: all
	gcc -o program  main.c $(NAME)

bonus: all $(BOBJ)
	ar rc $(NAME) $(OBJ) $(BOBJ)
	ranlib $(NAME)

bonus_main: bonus
	gcc -o bonus bonus_main.c $(NAME)

clean:
	rm -f $(OBJ) $(BOBJ) main.o bonus_main.o

fclean: clean
	rm -f program bonus
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
