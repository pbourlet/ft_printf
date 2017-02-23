#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/14 16:37:03 by pbourlet          #+#    #+#             *#
#*   Updated: 2017/02/23 19:46:50 by pbourlet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libftprintf.a

SRCL = $(addprefix libft/, \
	  ft_atoibase.c \
	  ft_strdup.c \
	  ft_atoi.c \
	  ft_strclr.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strcjoin.c \
	  ft_strcpy.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_toupper.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_nblen.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strrev.c) \

SRC = ft_lenlu.c \
	  ft_itoaspec.c \
	  ft_printf.c \
	  ft_stock.c \
	  ft_strtoupper.c \
	  ft_solve.c \
	  ft_itoabase.c \
	  ft_testtype.c \
	  ft_stockspec.c \
	  ft_stockss.c \
	  ft_testflags.c \
	  ft_putnstr.c \
	  ft_testdigit.c \
	  ft_bintoa.c \

OBJ = $(SRC:.c=.o)

OBJL = $(SRCL:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -o $@ -c $< -I./includes
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[37;01m$<\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"

$(NAME): $(OBJ) $(OBJL)
	@ar rc $(NAME) $(OBJ) $(OBJL)
	@ranlib $(NAME)

clean:
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[31;01mclean\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"
	@rm -rf $(OBJ) $(OBJL)

fclean: clean
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[31;01mfull clean\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"
	@rm -rf $(NAME)

re: fclean all
