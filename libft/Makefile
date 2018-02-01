# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 03:28:40 by phanna            #+#    #+#              #
#    Updated: 2017/05/04 15:26:57 by phanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =\
ft_atoi.c				ft_memdel.c				ft_striter.c\
ft_bzero.c             ft_memmove.c           ft_striteri.c\
ft_create_elem.c       ft_memset.c            ft_strjoin.c\
ft_factorial.c         ft_numlen.c            ft_strlcat.c\
ft_isalnum.c           ft_power.c             ft_strlen.c\
ft_isalpha.c           ft_putchar.c           ft_strlen_skip_white.c\
ft_isascii.c           ft_putchar_fd.c        ft_strmap.c\
ft_isdigit.c           ft_putendl.c           ft_strmapi.c\
ft_isprint.c           ft_putendl_fd.c        ft_strncat.c\
ft_isspace.c           ft_putnbr.c            ft_strncmp.c\
ft_itoa.c              ft_putnbr_fd.c         ft_strncpy.c\
ft_lstadd.c            ft_putstr.c            ft_strnequ.c\
ft_lstdel.c            ft_putstr_fd.c         ft_strnew.c\
ft_lstdelone.c         ft_sqrt.c              ft_strnstr.c\
ft_lstiter.c           ft_strcat.c            ft_strrchr.c\
ft_lstmap.c            ft_strchr.c            ft_strsplit.c\
ft_lstnew.c            ft_strclr.c            ft_strstr.c\
ft_memalloc.c          ft_strcmp.c            ft_strsub.c\
ft_memccpy.c           ft_strcpy.c            ft_strtrim.c\
ft_memchr.c            ft_strdel.c            ft_tolower.c\
ft_memcmp.c            ft_strdup.c            ft_toupper.c\
ft_memcpy.c            ft_strequ.c				ft_strndup.c\
ft_strlowcase.c			ft_strcapitalize.c		ft_str_is_alpha.c\
ft_str_is_numeric.c		ft_str_is_lowercase.c		ft_str_is_uppercase.c\
ft_str_is_printable.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(CC) -c $(CFLAGS) $(SRC) 
	@ar rc $(NAME) $(OBJ)
	@echo "generate libft"

clean:
	@rm -f $(OBJ) 
	@echo "cleaning objects files"

fclean: clean
	@rm -f $(NAME)
	@echo "delete $(NAME)"

re: fclean all
